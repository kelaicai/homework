#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct process{  //������̽ṹ��
   char name[2];//������
   float arrivetime;  //����ʱ�� 
   float servicetime;//����ʱ��
   float starttime ; //��ʼʱ�� 
   float finishtime;//���ʱ��
   float transfortime;//��תʱ��
   float withweighttime;//��Ȩ��תʱ��
   float avgtransfortime;//ƽ����תʱ��
   float avgweighttime;//ƽ����ȫ��תʱ��
   struct process* next;
}process;
int pro_num=0;  //��¼�������Ľ��̸���
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
	process *protemp=pro->next; //�ݴ�ָ�� 
	process *p=pro; //�α�ָ�� 
	p->next=NULL;
	puts("��������̵Ľ���������ʼʱ�䣬����ʱ��"); 
	while(flag){
		protemp=(process *)malloc(sizeof(process));
		if(protemp!=NULL){
		 printf("�����������");
		 scanf("%s",protemp->name);
		 printf("��ʼʱ�� ����ʱ��");
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
	init(); //��ʼ��ͷָ�� 
	while(1){
	puts("                  ��ӭ������ҵ�����㷨 ��ǰ�汾 1.0              ");
	puts("               **************************************            ");
	puts("               *        ���̵���                    *            ");
	puts("               *     1.�����ȷ���                   *            "); 
	puts("               *     2.����ҵ����                   *            ");
    puts("               *     3.ʱ��Ƭ��ת                   *            ");
    puts("               *     4.����Ȩ�㷨                   *            ");
	puts("               *     5.�˳�ϵͳ                     *            ");
    puts("               *     6.��ѡ����                   *            ");
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

 
