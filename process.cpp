#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<float.h>
typedef struct process{  //定义进程结构体
   char name[2];//进程名
   float  arrivetime;//到达时间 
   float servicetime;//服务时间
   float starttime;//开始时间
   float finishtime;//完成时间
   float transfortime;//周转时间
   float withweighttime;//带权周转时间
   float avgtransfortime;//平均周转时间
   float avgweighttime;//平均带全周转时间
   int priority; //优先权 
   int flags; 
   struct process* next;
}process;
int pro_num=0;  //记录进程链的进程个数
process *pro;  //头结点记录进程链的平均带权周转时间，和平均周转时间 
process *mem; //记录指针 记录指针是一个新链的头结点 
 
void init(){
	pro=(process *)malloc(sizeof(process));
	pro->next=NULL;
}

void show(){
	process *p=pro->next;
	while(p!=NULL){
		printf("进程名： %s 到达时间 ：%.2f 服务时间： %.2f 开始时间: %.2f 结束时间: %.2f 周转时间：%.2f 带权周转时间 %.2f \n ",p->name,p->arrivetime,p->servicetime,p->starttime,p->finishtime,p->transfortime,p->withweighttime);
	p=p->next;
	} 
}
void show_2(){
 	process *p=pro->next;
	while(p!=NULL){
		printf("进程名： %s 到达时间 ：%.2f 服务时间： %.2f 开始时间: %.2f 结束时间: %.2f 周转时间：%.2f 带权周转时间 %.2f 优先权：%d \n ",p->name,p->arrivetime,p->servicetime,p->starttime,p->finishtime,p->transfortime,p->withweighttime,p->priority);
	p=p->next;
	} 

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
		 printf("请输入进程名:   ");
		 scanf("%s",protemp->name);
		 printf("开始时间 服务时间:  ");
		 scanf("%f%f",&protemp->arrivetime,&protemp->servicetime);
		 protemp->finishtime=0.0;
		 protemp->transfortime=0.0;
		 protemp->withweighttime=0.0;
		 protemp->avgtransfortime=0.0;
		 protemp->avgweighttime=0.0;
		 protemp->flags=1;  //处理标志位 
		 protemp->next=p->next;
		 p->next=protemp;
		 p=protemp;
		 pro_num++;
		}
		else{
			puts("申请空间失败"); 
		}
		puts("是否要继续输入？");
		scanf("%d",&flag); 
	} 
	puts("建立链表成功！下面是进程链的信息"); 
	show();
}
void isNull(){
	if(NULL==pro->next){
		puts("未建立进程链");
		puts("现在建立进程链");
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
	
	process *curr=pro->next;  //建立链表后的第一个进程 
	process *pre=curr->next;  //建立链表后的第二个进程
	
	float min=curr->arrivetime;
	
	int i=0;
	int j=0;
	if(pre==NULL || curr==NULL){
		puts("当前指针为空 不能执行 请检查错误"); 
	} else{
		//选择排序
		for(i=0;i<pro_num && curr!=NULL;i++){
			min=curr->arrivetime;	
			pre=curr->next;  //重置指针pre 
			while(1){
				
				if(pre==NULL){
					break;  //最后一个元素就是最大的 
				}
				if(min<pre->arrivetime){
					; //小于什么也不干 
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
	process* curr=pro->next;  //上一个进程 
	process* pre=curr->next;   //当前进程 
	float time=0.0;   
	puts("当前所在 先来先服务算法");
	//第一个进程单独处理 
	
	curr->finishtime=curr->starttime+curr->servicetime;
	curr->transfortime=curr->finishtime-curr->arrivetime;
	curr->withweighttime=curr->transfortime/curr->servicetime;  
	while(pre){
	  pre->starttime=curr->finishtime; //当前进程开始时间等于上一个进程的结束时间 
	  pre->finishtime=pre->starttime+pre->servicetime;//当前进程结束时间等于 
	  pre->transfortime=pre->finishtime-pre->arrivetime;
	  pre->withweighttime=pre->transfortime/pre->servicetime; 
	  
	  if(curr!=NULL){
	  curr=curr->next;
	  pre=pre->next;
      }else{
      	break;
	  }
	}
	puts("fcfs算法处理结束后");
	show();	
	pre=pro->next;
	while(pre){
		pro->avgtransfortime+=pre->transfortime;
		pro->avgweighttime+=pre->withweighttime;
		pre=pre->next;
	} 
	//平均周转时间 
	pro->avgtransfortime=pro->avgtransfortime/pro_num;
	pro->avgweighttime=pro->avgweighttime/pro_num;
	printf(" 平均周转时间：%.2f 平均带权周转时间 %.2f\n",pro->avgtransfortime,pro->avgweighttime);
	puts("按任意键返回上一级菜单");
	getchar();
	getchar();
	system("cls");
	 
}
void fcfs(){
    isNull(); 
    fcfs_sort(); //按到达时间排序 
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
	process *curr=pro->next;  //建立链表后的第一个进程 
	process *pre=curr->next;  //建立链表后的第二个进程

	int i=0;
	float min=0.0; //记录最小工作时间 
//	fcfs_sort(); //使用到达时间先排个序
	//对第一个单独处理 
	curr=pro->next;
	
    
    curr=pre;
    puts("第一个节点初始化后"); 
    show();
	for(i=0;i<pro_num && curr!=NULL;i++){
		
		pre=pro->next->next; //pre每次从表头开始查找 未处理(flags=1) 并且当前链表最短的节点处理
		//curr指向每次处理的节点 
		min=FLT_MAX;
		while(1){
	  if(curr->finishtime>pre->arrivetime && pre->flags!=0  ){  //筛选出未处理的并且符合时间顺序要求的进程 
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
	puts("sjb算法处理后"); 
    show(); 
}


void tst(){  //时间片 
	
} 
void input_priority(){
	process *p=pro->next;
    puts(" 下面是进程链的各个进程情况，请按顺序输入进程的优先权"); 
	show(); 
	assert(pro->next);
	while(p){
		printf("请输入进程%s的优先权",p->name);
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
	fcfs_sort();//先按时间排序 
 
    curr->finishtime=curr->arrivetime+curr->servicetime;
    curr->transfortime=curr->finishtime-curr->arrivetime;
    curr->withweighttime=curr->transfortime/curr->servicetime;
    curr=curr->next;
    int i=0;
    
    if(pre==NULL || curr==NULL){
    	puts("当前指针为空，不能执行，现在退出");
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
	  	puts("curr为空"); 
	  }
	  ps_deal_1(curr);  //处理前链 
	  
	  curr=pro->next; //curr回到第一个节点 
	  while(curr->next!=NULL){
	  	curr=curr->next;
	  }
	  curr->next=pre;  //连接上 
	  ps_deal_2(curr,pre);  //处理后链 
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
	init(); //初始化头指针 
	while(1){
	puts("                               欢迎来到作业调度算法 当前版本 1.0              ");
	puts("                           **************************************            ");
	puts("                           *              进程调度              *            ");
	puts("                           *           1.先来先服务             *            "); 
	puts("                           *           2.短作业优先             *            ");
    puts("                           *           3.时间片轮转             *            ");
    puts("                           *           4.优先权算法             *            ");
	puts("                           *           5.退出系统               *            ");
    puts("                           *           6.请选择功能             *            ");
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

 


 
