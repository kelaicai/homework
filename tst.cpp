
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#define OUTALLINFO //��Ҫ�����ϸ�Ľ���������Ϣ��򿪺�
#define Max 256
#define time 2 //ʱ��Ƭ��С

enum pathread_attr{ //���̵�״̬��Ϣ
    runing = 1,
    wait,
    finsih
};

struct Pthread{ //����������Ϣ
  char *name;
  int come_time;
  int need_time;
  int runing_time;
  double zz_time;
  double dqzz_time;
  enum pathread_attr attr;
  struct Pthread *next;

  Pthread() //Ĭ�Ϲ��캯��
  {
      name = NULL;
      come_time = 0;
      runing_time  = need_time = 0;
      zz_time = 0;
      dqzz_time = 12.66;
      attr = wait;
      next = NULL;
  }

  void get_info(int end_time) //������תʱ�䣬��Ȩ��תʱ��
  {

#ifndef OUTALLINFO
     printf("pathread:%s over time:%d\n",name,end_time);
#endif // OUTALLINFO

     this->zz_time = (end_time - this->come_time) * 1.0;
     dqzz_time = zz_time / need_time;
  }

  void copy_queue(struct Pthread *temp) //����������Ϣ
  {
      name = (char*)malloc(sizeof(char) * strlen(temp->name));
      strcpy(name,temp->name);

      come_time = temp->come_time;
      need_time = temp->need_time;
      runing_time = temp->runing_time;
      attr = temp->attr;
  }

};

int run_sum = 0; //ͳ�ƽ��̵ĸ���

void init_pthread(struct Pthread *head,const char *name,const int come_time,const int need_time) //��ʼ��������Ϣ
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

void out_one(struct Pthread *temp) //���һ��������Ϣ
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


    printf("��תʱ��: %0.2f\n",temp->zz_time);
    printf("��Ȩ��תʱ��: %0.2f\n",temp->dqzz_time);

    return;
}

void out_all(struct Pthread *head) //������н�����Ϣ
{
    for(struct Pthread *p = head->next; p; p = p->next)
        out_one(p);

    return;
}

void add_queue(struct Pthread *head_temp,struct Pthread *head_queue) //��ӽ��̵���������
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

void queue_del(struct Pthread *head_queue) //�Ӿ�������ɾ��һ������
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

void sqrt_queue(struct Pthread *head_queue) //��ʱ��Ƭ������δ��ɵĽ��̷ŵ���β
{
    struct Pthread *p = head_queue->next;
    head_queue->next = p->next;
    p->next = NULL;

    struct Pthread *q = NULL;

    for(q = head_queue; q ->next; q = q->next);
    q ->next = p;

    return;
}

void mo_ni(struct Pthread *head,struct Pthread *head_queue) //ģ��ʱ��Ƭ��ת�����㷨
{
    int run_i = 0,run_over = 0,time_runing = 0;

    while(time_runing >= 0){
        for(struct Pthread *p = head ->next; p; p = p->next) //����ʱ���Ƿ��н��̵���
        if(time_runing == p->come_time)
            add_queue(p,head_queue);

        if(head_queue ->next){ //����������зǿ�
            if(run_i == time && head_queue->next->runing_time){ //ʱ��Ƭ����&&����δ���
                    sqrt_queue(head_queue); //�ѽ��̷ŵ��������ж�β
                    run_i = 0; //ʱ��Ƭ��0
            }
            if(!head_queue->next->runing_time){ //�������ִ�н���
                    head_queue->next->get_info(time_runing);
                    queue_del(head_queue); //�Ӿ���������ɾ���ý���
                    run_i = 0; //ʱ��Ƭ��0
                    run_over++; //ͳ���Ѿ������Ľ��̸���
            }
           if(head_queue ->next) //����н�������ִ�У�����ʱ���1
            head_queue->next->runing_time--;
            run_i++; //ʱ��Ƭ��1
        }

        time_runing++;

        if(run_over == run_sum) //������������н��������ģ��
            return;
    }

    return;
}

int main(int argc,char *argv[])
{
    struct Pthread *head = new Pthread(); //��������
    struct Pthread *head_queue = new Pthread(); //����̬�����������
    char name[Max];
    int come_time,need_time;
    FILE *input_file = fopen("C:\\Users\\Lenovo\\Desktop\\zhangbiao\\test.txt","r"); //��ȡ������Ϣ

    printf("plase input name come_time need_time priority,if over,plase input [Ctrl + Z]\n\n");
    while(fscanf(input_file,"%s%d%d",name,&come_time,&need_time) != EOF){
        init_pthread(head,name,come_time,need_time); //��ʼ����������
        run_sum++; //ͳ���ܹ��ж��ٸ�����
    }

    mo_ni(head,head_queue); //ģ��ʱ��Ƭ��ת�����㷨

    return 0;
}



