#include<stdio.h>
struct process{  //������̽ṹ��
	 char name[10];//������
   float arrivetime;//����ʱ��
   float servicetime;//����ʱ��
   float starttime;//��ʼʱ��
   float finishtime;//���ʱ��
   float transfortime;//��תʱ��
   float withweighttime;//��Ȩ��תʱ��
   float avgtransfortime;//ƽ����תʱ��
   float avgweighttime;//ƽ����ȫ��תʱ��

};
process a[50]; //����������������Ϊ50��
//���뺯��
void inPut(process *p,int n){
  int i;
  printf("��������̵� ������ ��ʼʱ��ͷ���ʱ�䣬�� a 0 1");
  for(i=0;i<=n-1;i++){
     printf("����%d�����̵���Ϣ\n",i+1);
     scanf("%s%f%f",&p[i].name,&p[i].arrivetime,&p[i].servicetime);
  }
 } 
 //�������
void outPut(process *p,float arrivetime,float servicetime,float starttime,float finishtime,float transfortime,float withweighttime,int n ){
   int i=0;
   printf("\n����˳��\n");
   printf("%s",p[0].name);
   for(i=1;i<n;i++){
     printf("->%s",p[i].name);
   }  
   
   puts("\n\n����\t ����\t ��ʼ\t����\t��ת��Ȩ\t ��Ȩ��ת\tƽ����ת\tƽ����Ȩ\n\n");
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
 		p[i].starttime=p[i-1].finishtime;//��ʼʱ�������һ�����̵Ľ���ʱ��
        p[i].finishtime=p[i-1].finishtime+p[i].servicetime;//j����ʱ��=ǰһ�����̵����ʱ��+��ǰ���̵ķ���ʱ��       
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
void fcfsSort(process *p,int n){ //���յ���ʱ�������ȵ�������ǰ��
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
  printf("������̸���:\n");
  scanf("%d",&N);
  
   inPut(a,N);
	while(1){
	puts("��ӭ������ҵ�����㷨 ��ǰ�汾 1.0");
	puts("**************************************");
	puts("*        ���̵���                   *");
	puts("*     1.�����ȷ���                 *");
	puts("*     2.����ҵ����                  *");
    puts("*     3.ʱ��Ƭ��ת                   *");
    puts("*     4.����Ȩ�㷨                  *");
	puts("*     5.�˳�ϵͳ                    *");
    puts("*     6.��ѡ����                   *");
	scanf("%d",&function);
	switch(function){
		case 1:fcfs_interface(a,N); break;
		case 2:/*sjb(); */ break;
		case 3:/*tst(); */ break;
		case 4:/*hs();*/  break;
	}
	}
} 
