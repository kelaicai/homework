
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#define OUTALLINFO //若要输出详细的进程描述信息则打开宏
#define Max 256
#define time 2 //时间片大小

enum pathread_attr{ //进程的状态信息
    runing = 1,
    wait,
    finsih
};

struct Pthread{ //描述进程信息
  char *name;
  int come_time;
  int need_time;
  int runing_time;
  double zz_time;
  double dqzz_time;
  enum pathread_attr attr;
  struct Pthread *next;

  Pthread() //默认构造函数
  {
      name = NULL;
      come_time = 0;
      runing_time  = need_time = 0;
      zz_time = 0;
      dqzz_time = 12.66;
      attr = wait;
      next = NULL;
  }

  void get_info(int end_time) //计算周转时间，带权周转时间
  {

#ifndef OUTALLINFO
     printf("pathread:%s over time:%d\n",name,end_time);
#endif // OUTALLINFO

     this->zz_time = (end_time - this->come_time) * 1.0;
     dqzz_time = zz_time / need_time;
  }

  void copy_queue(struct Pthread *temp) //拷贝进程信息
  {
      name = (char*)malloc(sizeof(char) * strlen(temp->name));
      strcpy(name,temp->name);

      come_time = temp->come_time;
      need_time = temp->need_time;
      runing_time = temp->runing_time;
      attr = temp->attr;
  }

};

int run_sum = 0; //统计进程的个数

void init_pthread(struct Pthread *head,const char *name,const int come_time,const int need_time) //初始化进程信息
{
    struct Pthread *temp = new Pthread();
    temp->name = (char *) malloc(sizeof(char) * strlen(name));
    strcpy(temp->name,name);
    temp->come_time = come_time;
    temp->need_time = need_time;
    temp->runing_time = need_time;
    temp->attr = wait;

    temp->next = head->next;
    head ->next = temp;

    return;
}

void out_one(struct Pthread *temp) //输出一个进程信息
{


#ifdef OUTALLINFO
    printf("%s pathread info:\n",temp->name);
    printf("come_time: %d\n",temp ->come_time);
    printf("need_time: %d\n",temp ->need_time);
    switch(temp->attr){
        case 1: printf("attr: waiting \n"); break;
        case 2: printf("attr: runing \n"); break;
        case 3: printf("attr: finsih \n"); break;
    }
#endif // OUTALLINFO


    printf("周转时间: %0.2f\n",temp->zz_time);
    printf("带权周转时间: %0.2f\n",temp->dqzz_time);

    return;
}

void out_all(struct Pthread *head) //输出所有进程信息
{
    for(struct Pthread *p = head->next; p; p = p->next)
        out_one(p);

    return;
}

void add_queue(struct Pthread *head_temp,struct Pthread *head_queue) //添加进程到就绪队列
{
    struct Pthread *temp = new Pthread();
    temp->copy_queue(head_temp);

    if(!head_queue->next)
        temp->attr = runing;
    else
        temp->attr = wait;

    struct Pthread *p = NULL;
    for(p = head_queue; p ->next; p = p->next);
    p->next = temp;

    return;
}

void queue_del(struct Pthread *head_queue) //从就绪队列删除一个进程
{
    if(!(head_queue ->next))
        return;

    head_queue ->next->attr = finsih;
    out_one(head_queue ->next);

    struct Pthread *p = head_queue ->next;

    head_queue->next = p->next;
    delete p;

    return;
}

void sqrt_queue(struct Pthread *head_queue) //将时间片结束还未完成的进程放到队尾
{
    struct Pthread *p = head_queue->next;
    head_queue->next = p->next;
    p->next = NULL;

    struct Pthread *q = NULL;

    for(q = head_queue; q ->next; q = q->next);
    q ->next = p;

    return;
}

void mo_ni(struct Pthread *head,struct Pthread *head_queue) //模拟时间片轮转调度算法
{
    int run_i = 0,run_over = 0,time_runing = 0;

    while(time_runing >= 0){
        for(struct Pthread *p = head ->next; p; p = p->next) //检查此时刻是否有进程到达
        if(time_runing == p->come_time)
            add_queue(p,head_queue);

        if(head_queue ->next){ //如果就绪队列非空
            if(run_i == time && head_queue->next->runing_time){ //时间片结束&&进程未完成
                    sqrt_queue(head_queue); //把进程放到就绪队列队尾
                    run_i = 0; //时间片置0
            }
            if(!head_queue->next->runing_time){ //如果进程执行结束
                    head_queue->next->get_info(time_runing);
                    queue_del(head_queue); //从就绪队列中删除该进程
                    run_i = 0; //时间片置0
                    run_over++; //统计已经结束的进程个数
            }
           if(head_queue ->next) //如果有进程正在执行，服务时间减1
            head_queue->next->runing_time--;
            run_i++; //时间片加1
        }

        time_runing++;

        if(run_over == run_sum) //如果处理完所有进程则结束模拟
            return;
    }

    return;
}

int main(int argc,char *argv[])
{
    struct Pthread *head = new Pthread(); //进程链表
    struct Pthread *head_queue = new Pthread(); //就绪态进程链表队列
    char name[Max];
    int come_time,need_time;
    FILE *input_file = fopen("C:\\Users\\Lenovo\\Desktop\\zhangbiao\\test.txt","r"); //读取测试信息

    printf("plase input name come_time need_time priority,if over,plase input [Ctrl + Z]\n\n");
    while(fscanf(input_file,"%s%d%d",name,&come_time,&need_time) != EOF){
        init_pthread(head,name,come_time,need_time); //初始化进程链表
        run_sum++; //统计总共有多少个进程
    }

    mo_ni(head,head_queue); //模拟时间片轮转调度算法

    return 0;
}



