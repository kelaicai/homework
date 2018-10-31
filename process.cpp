#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<float.h>
typedef struct process{  //������̽ṹ��
   char name[2];//������
   float  arrivetime;//����ʱ�� 
   float servicetime;//����ʱ��
   float starttime;//��ʼʱ��
   float finishtime;//���ʱ��
   float transfortime;//��תʱ��
   float withweighttime;//��Ȩ��תʱ��
   float avgtransfortime;//ƽ����תʱ��
   float avgweighttime;//ƽ����ȫ��תʱ��
   int priority; //����Ȩ 
   int flags; 
   struct process* next;
}process;
int pro_num=0;  //��¼�������Ľ��̸���
process *pro;  //ͷ����¼��������ƽ����Ȩ��תʱ�䣬��ƽ����תʱ�� 
process *mem; //��¼ָ�� ��¼ָ����һ��������ͷ��� 
 
void init(){
	pro=(process *)malloc(sizeof(process));
	pro->next=NULL;
}

void show(){
	process *p=pro->next;
	while(p!=NULL){
		printf("�������� %s ����ʱ�� ��%.2f ����ʱ�䣺 %.2f ��ʼʱ��: %.2f ����ʱ��: %.2f ��תʱ�䣺%.2f ��Ȩ��תʱ�� %.2f \n ",p->name,p->arrivetime,p->servicetime,p->starttime,p->finishtime,p->transfortime,p->withweighttime);
	p=p->next;
	} 
}
void show_2(){
 	process *p=pro->next;
	while(p!=NULL){
		printf("�������� %s ����ʱ�� ��%.2f ����ʱ�䣺 %.2f ��ʼʱ��: %.2f ����ʱ��: %.2f ��תʱ�䣺%.2f ��Ȩ��תʱ�� %.2f ����Ȩ��%d \n ",p->name,p->arrivetime,p->servicetime,p->starttime,p->finishtime,p->transfortime,p->withweighttime,p->priority);
	p=p->next;
	} 

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
		 printf("�����������:   ");
		 scanf("%s",protemp->name);
		 printf("��ʼʱ�� ����ʱ��:  ");
		 scanf("%f%f",&protemp->arrivetime,&protemp->servicetime);
		 protemp->finishtime=0.0;
		 protemp->transfortime=0.0;
		 protemp->withweighttime=0.0;
		 protemp->avgtransfortime=0.0;
		 protemp->avgweighttime=0.0;
		 protemp->flags=1;  //�����־λ 
		 protemp->next=p->next;
		 p->next=protemp;
		 p=protemp;
		 pro_num++;
		}
		else{
			puts("����ռ�ʧ��"); 
		}
		puts("�Ƿ�Ҫ�������룿");
		scanf("%d",&flag); 
	} 
	puts("��������ɹ��������ǽ���������Ϣ"); 
	show();
}
void isNull(){
	if(NULL==pro->next){
		puts("δ����������");
		puts("���ڽ���������");
		create(); 
	}
}

void swap_char(char *a,char *b){
	char buff[2]=" ";
	strcpy(buff,a);
	strcpy(a,b);
	strcpy(b,buff);
}
void swap_float(float *a,float *b){
     *a=*a+*b;
     *b=*a-*b;
     *a=*a-*b;
}
void exchange(process *a,process *b){
	swap_char(a->name,b->name);
	swap_float(&a->arrivetime,&b->arrivetime);
	swap_float(&a->servicetime,&b->servicetime);	 
}
void fcfs_sort(){
	
	process *curr=pro->next;  //���������ĵ�һ������ 
	process *pre=curr->next;  //���������ĵڶ�������
	
	float min=curr->arrivetime;
	
	int i=0;
	int j=0;
	if(pre==NULL || curr==NULL){
		puts("��ǰָ��Ϊ�� ����ִ�� �������"); 
	} else{
		//ѡ������
		for(i=0;i<pro_num && curr!=NULL;i++){
			min=curr->arrivetime;	
			pre=curr->next;  //����ָ��pre 
			while(1){
				
				if(pre==NULL){
					break;  //���һ��Ԫ�ؾ������� 
				}
				if(min<pre->arrivetime){
					; //С��ʲôҲ���� 
				}
				else{
					min=pre->arrivetime;
					exchange(curr,pre);
				}
				if(pre->next!=NULL){
					pre=pre->next; 
				} else{
					break;
				}
			}
			curr=curr->next; 
		} 
	}
	free(pre);
	 puts("hello");
}
void fcfs_deal(){
	process* curr=pro->next;  //��һ������ 
	process* pre=curr->next;   //��ǰ���� 
	float time=0.0;   
	puts("��ǰ���� �����ȷ����㷨");
	//��һ�����̵������� 
	
	curr->finishtime=curr->starttime+curr->servicetime;
	curr->transfortime=curr->finishtime-curr->arrivetime;
	curr->withweighttime=curr->transfortime/curr->servicetime;  
	while(pre){
	  pre->starttime=curr->finishtime; //��ǰ���̿�ʼʱ�������һ�����̵Ľ���ʱ�� 
	  pre->finishtime=pre->starttime+pre->servicetime;//��ǰ���̽���ʱ����� 
	  pre->transfortime=pre->finishtime-pre->arrivetime;
	  pre->withweighttime=pre->transfortime/pre->servicetime; 
	  
	  if(curr!=NULL){
	  curr=curr->next;
	  pre=pre->next;
      }else{
      	break;
	  }
	}
	puts("fcfs�㷨���������");
	show();	
	pre=pro->next;
	while(pre){
		pro->avgtransfortime+=pre->transfortime;
		pro->avgweighttime+=pre->withweighttime;
		pre=pre->next;
	} 
	//ƽ����תʱ�� 
	pro->avgtransfortime=pro->avgtransfortime/pro_num;
	pro->avgweighttime=pro->avgweighttime/pro_num;
	printf(" ƽ����תʱ�䣺%.2f ƽ����Ȩ��תʱ�� %.2f\n",pro->avgtransfortime,pro->avgweighttime);
	puts("�������������һ���˵�");
	getchar();
	getchar();
	system("cls");
	 
}
void fcfs(){
    isNull(); 
    fcfs_sort(); //������ʱ������ 
    fcfs_deal();
}
void setFlags(process *p){
	p->flags=0;
}
void sjb_deal_2(process *a,process *b){
	setFlags(a);
	b->starttime=a->finishtime;
	b->finishtime=b->starttime+b->starttime+b->servicetime;
	b->transfortime=b->finishtime-b->arrivetime;
	b->withweighttime=b->transfortime/b->servicetime; 
}


void sjb_sort(){
	process *curr=pro->next;  //���������ĵ�һ������ 
	process *pre=curr->next;  //���������ĵڶ�������

	int i=0;
	float min=0.0; //��¼��С����ʱ�� 
//	fcfs_sort(); //ʹ�õ���ʱ�����Ÿ���
	//�Ե�һ���������� 
	curr=pro->next;
	
    
    curr=pre;
    puts("��һ���ڵ��ʼ����"); 
    show();
	for(i=0;i<pro_num && curr!=NULL;i++){
		
		pre=pro->next->next; //preÿ�δӱ�ͷ��ʼ���� δ����(flags=1) ���ҵ�ǰ������̵Ľڵ㴦��
		//currָ��ÿ�δ���Ľڵ� 
		min=FLT_MAX;
		while(1){
	  if(curr->finishtime>pre->arrivetime && pre->flags!=0  ){  //ɸѡ��δ����Ĳ��ҷ���ʱ��˳��Ҫ��Ľ��� 
	  	if(min>pre->servicetime)
	  	 min=pre->servicetime;
	  	 if(pre->next!=NULL){
	  	 pre=pre->next;	  
          }else{
          	break;
		  }
	  	  	 
	  }else{
	  	 if(pre->next!=NULL){
	  	 pre=pre->next;	  
          }else{
          	break;
		  }
	  }
    }
	sjb_deal_2(curr,pre);  
    }//for 
//	free(pre);
	
	puts("hello");
}

void sjb(){
	isNull();
	sjb_sort();
	puts("sjb�㷨�����"); 
    show(); 
}


void tst(){  //ʱ��Ƭ 
	
} 
void input_priority(){
	process *p=pro->next;
    puts(" �����ǽ������ĸ�������������밴˳��������̵�����Ȩ"); 
	show(); 
	assert(pro->next);
	while(p){
		printf("���������%s������Ȩ",p->name);
		scanf("%d",&p->priority);
		p=p->next;
	}
}
void sort_priority(process *p){
	
}
void ps_deal_1(process *p){
	process *curr=p;
	process *pre=curr->next;
	p->starttime=pro->next->finishtime;
	p->finishtime=p->starttime+p->servicetime;
	p->transfortime=p->finishtime-p->arrivetime;
	p->withweighttime=p->transfortime/p->servicetime;
	

	while(pre){
		pre->starttime=curr->finishtime;
		pre->finishtime=pre->starttime+pre->servicetime;
		pre->transfortime=pre->finishtime-pre->arrivetime;
		pre->withweighttime=p->transfortime/pre->servicetime;
		curr=curr->next;
		pre=pre->next;
	}
	 
	show_2();
} 
void ps_deal_2(process *curr,process *pre){

	while(pre){
		pre->starttime=curr->finishtime;
		pre->finishtime=pre->starttime+pre->servicetime;
		pre->transfortime=pre->finishtime-pre->arrivetime;
		pre->withweighttime=pre->transfortime/pre->servicetime;
		curr=curr->next;
		pre=pre->next;
	}
	show_2();
}
void sort_priority_deal(){
	process *curr=pro->next;
	process *pre=curr->next;
	float priority=FLT_MAX; 
	fcfs_sort();//�Ȱ�ʱ������ 
 
    curr->finishtime=curr->arrivetime+curr->servicetime;
    curr->transfortime=curr->finishtime-curr->arrivetime;
    curr->withweighttime=curr->transfortime/curr->servicetime;
    curr=curr->next;
    int i=0;
    
    if(pre==NULL || curr==NULL){
    	puts("��ǰָ��Ϊ�գ�����ִ�У������˳�");
		system("exit"); 
	}else{
		for(i=0;i<pro_num &&  curr->arrivetime<pre->arrivetime && curr!=NULL;i++){
			priority=curr->priority;
			pre=curr->next;
			while(1){
				if(priority>pre->arrivetime){
					priority=pre->arrivetime;
					exchange(curr,pre);
				}else{
					;
				}
				if(pre->next!=NULL){
					pre=pre->next;
				}else{
					break;
				}
			}
			curr=curr->next;
		}
      if(pre->next!=NULL){
      	pre=pre->next;
	  }
	  if(curr!=NULL){
	  	curr->next=NULL;
	  	curr=pro->next->next;
	  }else{
	  	puts("currΪ��"); 
	  }
	  ps_deal_1(curr);  //����ǰ�� 
	  
	  curr=pro->next; //curr�ص���һ���ڵ� 
	  while(curr->next!=NULL){
	  	curr=curr->next;
	  }
	  curr->next=pre;  //������ 
	  ps_deal_2(curr,pre);  //������� 
	}
    
    
    show();
}

void ps(){
	isNull();
	input_priority();
	sort_priority_deal();
}
int main(){                                           
	int function=0;
	system("color 5f");
	init(); //��ʼ��ͷָ�� 
	while(1){
	puts("                               ��ӭ������ҵ�����㷨 ��ǰ�汾 1.0              ");
	puts("                           **************************************            ");
	puts("                           *              ���̵���              *            ");
	puts("                           *           1.�����ȷ���             *            "); 
	puts("                           *           2.����ҵ����             *            ");
    puts("                           *           3.ʱ��Ƭ��ת             *            ");
    puts("                           *           4.����Ȩ�㷨             *            ");
	puts("                           *           5.�˳�ϵͳ               *            ");
    puts("                           *           6.��ѡ����             *            ");
    puts("                           **************************************            ");
	scanf("%d",&function);
	switch(function){
		case 1:fcfs(); break;
		case 2:sjb();  break;
		case 3:tst();  break; // 
		case 4:ps();  break;
	}
	}
} 

 


 
