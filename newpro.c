#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct process{  //定义进程结构体
   char name[2];//进程名
   float arrivetime;  //到达时间 
   float servicetime;//服务时间
   float starttime ; //开始时间 
   float finishtime;//完成时间
   float transfortime;//周转时间
   float withweighttime;//带权周转时间
   float avgtransfortime;//平均周转时间
   float avgweighttime;//平均带全周转时间
   struct process* next;
}process;
int pro_num=0;  //记录进程链的进程个数
process *pro;
 
void init(){
	pro=(process *)malloc(sizeof(process));
	pro->next=NULL;
}


void show(){
	
}

void create(){
	system("cls");
	int flag=1;
	process *protemp=pro->next; //暂存指针 
	process *p=pro; //游标指针 
	p->next=NULL;
	puts("请输入进程的进程名，开始时间，服务时间"); 
	while(flag){
		protemp=(process *)malloc(sizeof(process));
		if(protemp!=NULL){
		 printf("请输入进程名");
		 scanf("%s",protemp->name);
		 printf("开始时间 服务时间");
		 scanf("%f%f",&protemp->arrivetime,&protemp->servicetime);
		 protemp->finishtime=0.0;
		 protemp->transfortime=0.0;
		 protemp->withweighttime=0.0;
		 protemp->avgtransfortime=0.0;
		 protemp->avgweighttime=0.0;
		 protemp->next=p->next;
		 p->next=protemp;
		 p=protemp;
		 pro_num++;
		}
	} 
}
void fcfs_sort(){
	
}
void fcfs(){
	
}

void sjb(){
	
}
void sjb_sort(){
	
}


int main(){
	int function=0;
	init(); //初始化头指针 
	while(1){
	puts("                  欢迎来到作业调度算法 当前版本 1.0              ");
	puts("               **************************************            ");
	puts("               *        进程调度                    *            ");
	puts("               *     1.先来先服务                   *            "); 
	puts("               *     2.短作业优先                   *            ");
    puts("               *     3.时间片轮转                   *            ");
    puts("               *     4.优先权算法                   *            ");
	puts("               *     5.退出系统                     *            ");
    puts("               *     6.请选择功能                   *            ");
    puts("               **************************************            ");
	scanf("%d",&function);
	switch(function){
		case 1:fcfs(); break;
		case 2:sjb();  break;
		case 3:tst();  break;
		case 4:hs();  break;
	}
	}
} 

 
