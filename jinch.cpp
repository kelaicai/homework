#include<stdio.h>

struct fcfs//定义进程的结构体

{

   char name[10];//进程名
   float arrivetime;//到达时间
   float servicetime;//服务时间

   float starttime;//开始时间

   float finishtime;//完成时间

   float zztime;//周转时间

   float dqzztime;//带权周转时间

   float pjzztime;//平均周转时间

   float pjdqtime;//平均带全周转时间

};

struct sjf//定义进程的结构体
{
  char name[10];//进程名
  float arrivetime;//到达时间
  float servicetime;//服务时间
  float starttime;//开始时间
  float finishtime;//完成时间
  float zztime;//周转时间
  float dqzztime;//带权周转时间
  float pjzztime;//平均周转时间
  float pjdqtime;//平均带全周转时间
};

fcfs a[100];//定义先来先服务算法进程的最大数量

void Finput(fcfs*p,int N)//输入函数
{
  int i; 
  printf("输入进程例如: a 0 10\n");

  for(i=0;i<=N-1;i++){
    printf("输入%dth的信息:\n",i+1);
    scanf("%s%f%f",&p[i].name,&p[i].arrivetime,&p[i].servicetime);
	}
}//输出函数

void FPrint(fcfs *p,float arrivetime,float servicetime,float starttime,float finishtime,float zztime,float dqzztime,int N)
{
  int k;
  printf("\n运行顺序:\n");
  printf("%s",p[0].name);
  for(k=1;k<N;k++){
   printf("->%s",p[k].name);
  }

  printf("\n\n进程信息:\n");
  printf("\n进程\t到达\t服务\t开始\t完成\t周权\t带权周转\t平均周转\t平均带权\n\n");
  for(k=0;k<=N-1;k++){
  printf("%s\t%-.2f\t%-.2f\t%-.2f\t%-.2f\t%-.2f\t%-.2f\t%-.2f\t%-.2f\t\n\n",p[k].name,p[k].arrivetime,p[k].servicetime,p[k].starttime,p[k].finishtime,p[k].zztime,p[k].dqzztime,p[k].pjzztime,p[k].pjdqtime);
  }
}

//运行结果

void Fdeal(fcfs*p,float arrivetime,float servicetime,float starttime,float finishtime,float&zztime,float&dqzztime,int N){

  int k;
  float sum1=0.0;
  float sum2=0.0;
  for(k=0;k<=N-1;k++){
  if(k==0){
  p[k].starttime=p[k].arrivetime;p[k].finishtime=p[k].arrivetime+p[k].servicetime;
  }else{
       p[k].starttime=p[k-1].finishtime;//开始时间=前一个进程的完成时间
       p[k].finishtime=p[k-1].finishtime+p[k].servicetime;//结束时间=前一个进程的完成时间+现在进程的服务时间
       }
}

 for(k=0;k<=N-1;k++){
  p[k].zztime=p[k].finishtime-p[k].arrivetime;//周转时间=完成时间-到达时间
  p[k].dqzztime=p[k].zztime/p[k].servicetime;//带权周转时间=周转时间/服务时间
  sum1+=p[k].zztime;//平均周转时间=周转时间之和/进程数
  p[k].pjzztime=sum1/N;
  sum2+=p[k].dqzztime;//平均带权周转时间=带权周转时间之和/进程数
  p[k].pjdqtime=sum2/N;
}
}

void Fsort(fcfs *p,int N)//按到达时间排序，先到达排在前面
{
   for(int i=0;i<=N-1;i++)
       for(int j=0;j<=i;j++)
       if(p[i].arrivetime<p[j].arrivetime){
       fcfs temp;
       temp=p[i];
       p[i]=p[j];
       p[j]=temp;
   }
}

void FCFS(fcfs*p,int N)//先来先服务
{
   float arrivetime=0,servicetime=0,starttime=0,finishtime=0,zztime=0,dqzztime=0;
   Fsort(p,N);
   Fdeal(p,arrivetime,servicetime,starttime,
   finishtime,zztime,dqzztime,N);
   FPrint(p,arrivetime,servicetime,starttime,finishtime,zztime,dqzztime,N);
}

void Sinput(sjf*p,int N)//输入函数
{
   int i;
   printf("输入进程例如:a 0 10\n\n");
   for(i=0;i<=N-1;i++){
   printf("输入%dth 进程信息:\n",i+1);
   scanf("%s%f%f",&p[i].name,&p[i].arrivetime,&p[i].servicetime);
   }
}
   //输出函数
int main()//主函数
{
  int N;
  printf("------先来先服务调度算法------\n");
  printf("输入进程个数:\n");
  scanf("%d",&N);
  Finput(a,N);
  FCFS(a,N);
}


