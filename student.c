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

int stu_num = 0; //设置全局变量学生人数
student* stu;  //设置学生信息链

void init(){
	stu=(student*)malloc(sizeof(student));
	stu->next=NULL;
}

void isNULL(){
	if(NULL==stu->next){
	//	assert(stu->next);  //使用断言报错在哪 
		puts("由于未建表，现跳转到建立学生信息");
		create(); 
	}
} 
void show(){
	isNULL();
	system("cls");
  student *p=stu->next; //
  while(p){
  	printf("学号： %d  姓名： %s   性别：  %s   班级 %d 语文： %.2lf 数学： %.2lf 英语： %.2lf 平均分 %.2lf\n",p->stu_id,p->stu_name,p->sex,p->class_num,p->score[0],p->score[1],p->score[2],p->avg);
  p=p->next;
 }
  free(p);
}
int create(){  //建表成功返回1，失败返回0
	system("cls");
	int flag = 1;
	student *stutemp, *p;
	stutemp = NULL; 
	
	p = stu;  //p指针是游标指针
	p->next = NULL;
	puts("请输入学生的信息\n");
	puts("id  name  sex class chinese math english");
	while (flag){
		stutemp = (student *)malloc(sizeof(student));
		if (stutemp != NULL){
			printf("请输入学生ID");
			scanf("%d",&stutemp->stu_id);
			printf("请输入学生的姓名  ");
			scanf("%s",stutemp->stu_name);
			getchar();
			printf("学生的性别  "); 
			scanf("%s",stutemp->sex);
			printf("请输入学生的班级 ");
			scanf("%d",&stutemp->class_num);
			printf("请输入学生的语文 数学 英语 成绩");
			scanf("%lf%lf%lf",&stutemp->score[0],&stutemp->score[1],&stutemp->score[2]); 
			p->avg=0.0;  //初始化平均分为0.0 
			stutemp->next = p->next;
			p->next = stutemp;
			p = stutemp;
			stu_num++;
		}
		else{
			puts("请重新输入");
		}
		printf("是否要继续输入");
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

void exchange(student *p1,student *p2){  //交换节点的信息 
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
  student *curr=stu->next;   //第一个学生 
  student *pre=curr->next;  //第二个学生 
  double  min=curr->avg; //成绩最低 
  int i=0; 
 
  if(pre==NULL || curr==NULL){
  	puts("当前指针为空 不能执行 请检查错误"); 
  } else
  { //选择排序 
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
  puts("按任意键返回上一级菜单"); 
  getchar(); 
 // system("cls");
}  //avg 
void sort_stu_id(){
 	
  student *curr=stu->next;   //第一个学生 
  
  student *pre=curr->next;  //第二个学生 
  double  min=curr->stu_id; //成绩最低 
  int i=0; 
  
  if(pre==NULL || curr==NULL){
  	puts("当前指针为空 不能执行 请检查错误"); 
  } else
  { //选择排序 
  puts("             按学号排序               "); 
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
  puts("按任意键返回上一级菜单"); 
  getchar(); 
}
void sort_interface(){
	system("cls");
    isNULL();
    
	int chose=0;
		puts("                      当前所在模块： 排序                     ");
		puts("            **************************************            "); 
	    puts("            *          1.按平均分排序            *            ");
	    puts("            *          2.按学号排序              *            "); 
	    puts("            **************************************            "); 
	    puts("请输入查询方式：");
	   scanf("%d",&chose);
	   if(chose==1){
	   	sort_avg();
	   }
	   else if(chose==2){
	   	sort_stu_id();
	   }else{
	   	puts("输入错误") ; 
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
  puts("请输入学生的学号"); 
   scanf("%d",&id);
   while(p){  //默认输入的学号在输入的队列中 
   	if(p->stu_id==id){
   		printf("该学生的 语文 %.2lf 数学 %.2lf  英语 %.2lf",p->score[0],p->score[1],p->score[2]);
   	
   		break; 
	   }
	   p=p->next; 
   }
   //按任意键退出 
   puts("按任意键退出"); 
   getchar(); 
   getchar(); 
}

void avg(){
	isNULL();
  system("cls"); 
  puts("当前所在模块： 平均分"); 
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
	system("color 3f");//设置背景颜色浅绿色，亮白色 
	int chose = 0;
	init();
	while (1){
		 
		system("cls");
		puts("              *********************************************            ");
		puts("              *     欢迎来到学生成绩管理系统  版本1.0.0   *            ");
		puts("              *              1.建立学生信息               *            ");
		puts("              *              2.平均分                     *            ");
		puts("              *              3.排序                       *            ");
		puts("              *              4.查询信息                   *            ");
		puts("              *              5.显示学生信息               *            ");
		puts("              *              6.退出系统                   *            ");
		puts("              **********************************************           ");

		puts(" 请选择功能 \t");
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

