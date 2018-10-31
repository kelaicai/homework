#include<stdio.h>
struct process{  //定义进程结构体
	 char name[10];//进程名
   float arrivetime;//到达时间
   float servicetime;//服务时间
   float starttime;//开始时间
   float finishtime;//完成时间
   float transfortime;//周转时间
   float withweighttime;//带权周转时间
   float avgtransfortime;//平均周转时间
   float avgweighttime;//平均带全周转时间

};
process a[50]; //定义最大处理进程数量为50个
//输入函数
void inPut(process *p,int n){
  int i;
  printf("请输入进程的 进程名 开始时间和服务时间，如 a 0 1");
  for(i=0;i<=n-1;i++){
     printf("输入%d个进程的信息\n",i+1);
     scanf("%s%f%f",&p[i].name,&p[i].arrivetime,&p[i].servicetime);
  }
 } 
 //输出函数
void outPut(process *p,float arrivetime,float servicetime,float starttime,float finishtime,float transfortime,float withweighttime,int n ){
   int i=0;
   printf("\n运行顺序\n");
   printf("%s",p[0].name);
   for(i=1;i<n;i++){
     printf("->%s",p[i].name);
   }  
   
   puts("\n\n进程\t 到达\t 开始\t结束\t周转带权\t 带权周转\t平均周转\t平均带权\n\n");
   for(i=1;i<n;i++)
   {
   printf("%s\t%-.2f\t%-.2f\t%-.2f\t%-.2f\t%-.2f\t%-.2f\t%-.2f\t%-.2f\t\n\n",p[i].name,p[i].arrivetime,p[i].servicetime,p[i].starttime,p[i].finishtime,p[i].transfortime,p[i].withweighttime,p[i].avgtransfortime,p[i].avgweighttime);
   }
 } 
void fcfs(process *p,float arrivetime,float servicetime,float starttime,float finishtime,float &transfortime,float &withweighttime,int n){
 int i=0;
 float summary1=0.0;
 float summary2=0.0;
 for(i=0;i<=n-1;i++){
 	if(i==0){
 		p[i].starttime=p[i].arrivetime;
 		p[i].finishtime=p[i].arrivetime+p[i].servicetime; 
 	}else{
 		p[i].starttime=p[i-1].finishtime;//开始时间等于上一个进程的结束时间
        p[i].finishtime=p[i-1].finishtime+p[i].servicetime;//j结束时间=前一个进程的完成时间+当前进程的服务时间       
 	}
 	for(i=0;i<=n-1;i++){
 		p[i].transfortime=p[i].finishtime-p[i].arrivetime;
 		p[i].withweighttime=p[i].transfortime/p[i].servicetime;
 		summary1+=p[i].transfortime;
 		p[i].avgtransfortime=summary1/n;
 		summary2+=p[i].withweighttime;
 		p[i].avgweighttime=summary2/n;
 	}
 }
}
void fcfsSort(process *p,int n){ //按照到达时间排序，先到达排在前面
    int i=0;
    int j=0;
    process temp;
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++){
         if(p[i].arrivetime<p[j].arrivetime){
         	temp=p[i];
         	p[i]=p[j];
         	p[j]=temp;
         }
		}
	}
}

void fcfs_interface(process *p,int n){
	float arrivetime=0.0,servicetime=0.0,starttime=0.0,finishtime=0.0,transfortime=0.0,withweighttime=0.0;
	fcfsSort(p,n);
	fcfs(p,arrivetime,servicetime,starttime,finishtime,transfortime,withweighttime,n);
	outPut(p,arrivetime,servicetime,starttime,finishtime,transfortime,withweighttime,n);
}
int main(){
	int function=0;
	
	 int N;
  printf("输入进程个数:\n");
  scanf("%d",&N);
  
   inPut(a,N);
	while(1){
	puts("欢迎来到作业调度算法 当前版本 1.0");
	puts("**************************************");
	puts("*        进程调度                   *");
	puts("*     1.先来先服务                 *");
	puts("*     2.短作业优先                  *");
    puts("*     3.时间片轮转                   *");
    puts("*     4.优先权算法                  *");
	puts("*     5.退出系统                    *");
    puts("*     6.请选择功能                   *");
	scanf("%d",&function);
	switch(function){
		case 1:fcfs_interface(a,N); break;
		case 2:/*sjb(); */ break;
		case 3:/*tst(); */ break;
		case 4:/*hs();*/  break;
	}
	}
} 
