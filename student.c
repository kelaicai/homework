#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include <assert.h>
typedef struct student{
	int stu_id;
	char stu_name[10];
	char sex[2];
	int class_num;
	double score[3];
	double avg;
struct student* next;
}student;

int stu_num = 0; //����ȫ�ֱ���ѧ������
student* stu;  //����ѧ����Ϣ��

void init(){
	stu=(student*)malloc(sizeof(student));
	stu->next=NULL;
}

void isNULL(){
	if(NULL==stu->next){
	//	assert(stu->next);  //ʹ�ö��Ա������� 
		puts("����δ��������ת������ѧ����Ϣ");
		create(); 
	}
} 
void show(){
	isNULL();
	system("cls");
  student *p=stu->next; //
  while(p){
  	printf("ѧ�ţ� %d  ������ %s   �Ա�  %s   �༶ %d ���ģ� %.2lf ��ѧ�� %.2lf Ӣ� %.2lf ƽ���� %.2lf\n",p->stu_id,p->stu_name,p->sex,p->class_num,p->score[0],p->score[1],p->score[2],p->avg);
  p=p->next;
 }
  free(p);
}
int create(){  //����ɹ�����1��ʧ�ܷ���0
	system("cls");
	int flag = 1;
	student *stutemp, *p;
	stutemp = NULL; 
	
	p = stu;  //pָ�����α�ָ��
	p->next = NULL;
	puts("������ѧ������Ϣ\n");
	puts("id  name  sex class chinese math english");
	while (flag){
		stutemp = (student *)malloc(sizeof(student));
		if (stutemp != NULL){
			printf("������ѧ��ID");
			scanf("%d",&stutemp->stu_id);
			printf("������ѧ��������  ");
			scanf("%s",stutemp->stu_name);
			getchar();
			printf("ѧ�����Ա�  "); 
			scanf("%s",stutemp->sex);
			printf("������ѧ���İ༶ ");
			scanf("%d",&stutemp->class_num);
			printf("������ѧ�������� ��ѧ Ӣ�� �ɼ�");
			scanf("%lf%lf%lf",&stutemp->score[0],&stutemp->score[1],&stutemp->score[2]); 
			p->avg=0.0;  //��ʼ��ƽ����Ϊ0.0 
			stutemp->next = p->next;
			p->next = stutemp;
			p = stutemp;
			stu_num++;
		}
		else{
			puts("����������");
		}
		printf("�Ƿ�Ҫ��������");
		scanf("%d", &flag);
	}
}
void swap_int(int* a,int *b){
	int tmp=0;
	tmp=*a;
	*a=*b;
	*b=tmp;
}
void swap_double(double* a,double *b){
	double tmp=0.0;
	tmp=*a;
	*a=*b;
	*b=tmp;
}
void strexchg_char10(char *a, char *b){
   char buff[10]="   ";
   strcpy(buff,a);
   strcpy(a,b);
   strcpy(b,buff);
}

void strexchg_char2(char *a, char *b){
   char buff[2]=" ";
   strcpy(buff,a);
   strcpy(a,b);
   strcpy(b,buff);
}

void exchange(student *p1,student *p2){  //�����ڵ����Ϣ 
	int i=0;
    swap_int(&p1->stu_id,&p2->stu_id);
    strexchg_char10(p1->stu_name,p2->stu_name);
    strexchg_char2(p1->sex,p2->sex);
    swap_int(&p1->class_num,&p2->class_num);
    for(i=0;i<3;i++){
    swap_double(&p1->score[i],&p2->score[i]);
    }	
    swap_double(&p1->avg,&p2->avg);
} 


void sort_avg(){
  student *curr=stu->next;   //��һ��ѧ�� 
  student *pre=curr->next;  //�ڶ���ѧ�� 
  double  min=curr->avg; //�ɼ���� 
  int i=0; 
 
  if(pre==NULL || curr==NULL){
  	puts("��ǰָ��Ϊ�� ����ִ�� �������"); 
  } else
  { //ѡ������ 
  	for(i=0;i<stu_num-1&&curr!=NULL && pre!=NULL;i++){
  			min=curr->avg;	
			pre=curr->next;
  		while(1){
  			if(min<pre->avg){
  				;
			  }
			  else{
			  	min=pre->avg;
			    exchange(curr,pre);
			  }
			if(pre->next!=NULL){
			  pre=pre->next;
		}else{
		break;	
		}
		  }
		  curr=curr->next;
	  } 
  }  //else
  show(); 
  //free(pre);
 // free(curr);
  puts("�������������һ���˵�"); 
  getchar(); 
 // system("cls");
}  //avg 
void sort_stu_id(){
 	
  student *curr=stu->next;   //��һ��ѧ�� 
  
  student *pre=curr->next;  //�ڶ���ѧ�� 
  double  min=curr->stu_id; //�ɼ���� 
  int i=0; 
  
  if(pre==NULL || curr==NULL){
  	puts("��ǰָ��Ϊ�� ����ִ�� �������"); 
  } else
  { //ѡ������ 
  puts("             ��ѧ������               "); 
  	for(i=0;i<stu_num-1&&curr!=NULL && pre!=NULL;i++){
  			min=curr->stu_id;
  			pre=curr->next;
  		while(1){
  		
  			if(min<pre->stu_id){
  				;
			  }
			  else{
			  	min=pre->stu_id;
			    exchange(curr,pre);
			  }
			if(pre->next!=NULL){
			  pre=pre->next;
		}else{
		break;	
		}
		  }
		  curr=curr->next;
	  } 
  }  //else
  show(); 
  //free(pre);
  //free(curr);
  puts("�������������һ���˵�"); 
  getchar(); 
}
void sort_interface(){
	system("cls");
    isNULL();
    
	int chose=0;
		puts("                      ��ǰ����ģ�飺 ����                     ");
		puts("            **************************************            "); 
	    puts("            *          1.��ƽ��������            *            ");
	    puts("            *          2.��ѧ������              *            "); 
	    puts("            **************************************            "); 
	    puts("�������ѯ��ʽ��");
	   scanf("%d",&chose);
	   if(chose==1){
	   	sort_avg();
	   }
	   else if(chose==2){
	   	sort_stu_id();
	   }else{
	   	puts("�������") ; 
	   }
	getchar();
	getchar();
	system("cls");
}
void seach(){
	isNULL();
	 system("cls"); 
	int id=0; 
	student *p=stu->next;
  puts("������ѧ����ѧ��"); 
   scanf("%d",&id);
   while(p){  //Ĭ�������ѧ��������Ķ����� 
   	if(p->stu_id==id){
   		printf("��ѧ���� ���� %.2lf ��ѧ %.2lf  Ӣ�� %.2lf",p->score[0],p->score[1],p->score[2]);
   	
   		break; 
	   }
	   p=p->next; 
   }
   //��������˳� 
   puts("��������˳�"); 
   getchar(); 
   getchar(); 
}

void avg(){
	isNULL();
  system("cls"); 
  puts("��ǰ����ģ�飺 ƽ����"); 
  double sum=0.0;
  int i=0;
  
  
  student* p=stu->next;
  while(p){
  sum=0.0;
  for(i=0;i<3;i++){
  	sum+=p->score[i];
  }
  p->avg=sum/3;
  p=p->next;
  }
  show(); 
  getchar(); 
  getchar();
}
int main(){
	system("color 3f");//���ñ�����ɫǳ��ɫ������ɫ 
	int chose = 0;
	init();
	while (1){
		 
		system("cls");
		puts("              *********************************************            ");
		puts("              *     ��ӭ����ѧ���ɼ�����ϵͳ  �汾1.0.0   *            ");
		puts("              *              1.����ѧ����Ϣ               *            ");
		puts("              *              2.ƽ����                     *            ");
		puts("              *              3.����                       *            ");
		puts("              *              4.��ѯ��Ϣ                   *            ");
		puts("              *              5.��ʾѧ����Ϣ               *            ");
		puts("              *              6.�˳�ϵͳ                   *            ");
		puts("              **********************************************           ");

		puts(" ��ѡ���� \t");
		scanf("%d", &chose);
		switch (chose){
		case 1:create(); break;
		case 2:avg();  break;
		case 3:sort_interface();  break;
		case 4:seach();  break;
		case 5:show(); system("pause"); break;
		case 6:goto label; 
		}
	}
	label:system("taskkill /f /im cmd.exe");
}

