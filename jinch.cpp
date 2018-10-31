#include<stdio.h>

struct fcfs//������̵Ľṹ��

{

   char name[10];//������
   float arrivetime;//����ʱ��
   float servicetime;//����ʱ��

   float starttime;//��ʼʱ��

   float finishtime;//���ʱ��

   float zztime;//��תʱ��

   float dqzztime;//��Ȩ��תʱ��

   float pjzztime;//ƽ����תʱ��

   float pjdqtime;//ƽ����ȫ��תʱ��

};

struct sjf//������̵Ľṹ��
{
  char name[10];//������
  float arrivetime;//����ʱ��
  float servicetime;//����ʱ��
  float starttime;//��ʼʱ��
  float finishtime;//���ʱ��
  float zztime;//��תʱ��
  float dqzztime;//��Ȩ��תʱ��
  float pjzztime;//ƽ����תʱ��
  float pjdqtime;//ƽ����ȫ��תʱ��
};

fcfs a[100];//���������ȷ����㷨���̵��������

void Finput(fcfs*p,int N)//���뺯��
{
  int i; 
  printf("�����������: a 0 10\n");

  for(i=0;i<=N-1;i++){
    printf("����%dth����Ϣ:\n",i+1);
    scanf("%s%f%f",&p[i].name,&p[i].arrivetime,&p[i].servicetime);
	}
}//�������

void FPrint(fcfs *p,float arrivetime,float servicetime,float starttime,float finishtime,float zztime,float dqzztime,int N)
{
  int k;
  printf("\n����˳��:\n");
  printf("%s",p[0].name);
  for(k=1;k<N;k++){
   printf("->%s",p[k].name);
  }

  printf("\n\n������Ϣ:\n");
  printf("\n����\t����\t����\t��ʼ\t���\t��Ȩ\t��Ȩ��ת\tƽ����ת\tƽ����Ȩ\n\n");
  for(k=0;k<=N-1;k++){
  printf("%s\t%-.2f\t%-.2f\t%-.2f\t%-.2f\t%-.2f\t%-.2f\t%-.2f\t%-.2f\t\n\n",p[k].name,p[k].arrivetime,p[k].servicetime,p[k].starttime,p[k].finishtime,p[k].zztime,p[k].dqzztime,p[k].pjzztime,p[k].pjdqtime);
  }
}

//���н��

void Fdeal(fcfs*p,float arrivetime,float servicetime,float starttime,float finishtime,float&zztime,float&dqzztime,int N){

  int k;
  float sum1=0.0;
  float sum2=0.0;
  for(k=0;k<=N-1;k++){
  if(k==0){
  p[k].starttime=p[k].arrivetime;p[k].finishtime=p[k].arrivetime+p[k].servicetime;
  }else{
       p[k].starttime=p[k-1].finishtime;//��ʼʱ��=ǰһ�����̵����ʱ��
       p[k].finishtime=p[k-1].finishtime+p[k].servicetime;//����ʱ��=ǰһ�����̵����ʱ��+���ڽ��̵ķ���ʱ��
       }
}

 for(k=0;k<=N-1;k++){
  p[k].zztime=p[k].finishtime-p[k].arrivetime;//��תʱ��=���ʱ��-����ʱ��
  p[k].dqzztime=p[k].zztime/p[k].servicetime;//��Ȩ��תʱ��=��תʱ��/����ʱ��
  sum1+=p[k].zztime;//ƽ����תʱ��=��תʱ��֮��/������
  p[k].pjzztime=sum1/N;
  sum2+=p[k].dqzztime;//ƽ����Ȩ��תʱ��=��Ȩ��תʱ��֮��/������
  p[k].pjdqtime=sum2/N;
}
}

void Fsort(fcfs *p,int N)//������ʱ�������ȵ�������ǰ��
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

void FCFS(fcfs*p,int N)//�����ȷ���
{
   float arrivetime=0,servicetime=0,starttime=0,finishtime=0,zztime=0,dqzztime=0;
   Fsort(p,N);
   Fdeal(p,arrivetime,servicetime,starttime,
   finishtime,zztime,dqzztime,N);
   FPrint(p,arrivetime,servicetime,starttime,finishtime,zztime,dqzztime,N);
}

void Sinput(sjf*p,int N)//���뺯��
{
   int i;
   printf("�����������:a 0 10\n\n");
   for(i=0;i<=N-1;i++){
   printf("����%dth ������Ϣ:\n",i+1);
   scanf("%s%f%f",&p[i].name,&p[i].arrivetime,&p[i].servicetime);
   }
}
   //�������
int main()//������
{
  int N;
  printf("------�����ȷ�������㷨------\n");
  printf("������̸���:\n");
  scanf("%d",&N);
  Finput(a,N);
  FCFS(a,N);
}


