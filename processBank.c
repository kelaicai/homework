#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#include<assert.h>   
#include"processBank.h"

int input(){
	int i=0;
	int j=0;
	puts("请输入系统所提供的资源种类的数目");
	scanf("%d",&re_n);
	fflush(stdin); //置空输入缓冲区
	puts("avaible各类资源的个数");
	fun();
	for(i=0;i<re_n;i++){
		scanf("%d",&avaible[i]);
	}
	puts("请输入进程个数：");
	scanf("%d",&pro_m);
	fflush(stdin);
	for(i=0;i<pro_m;i++){
		printf("请输入第 %d 个进程的名称",i);
	    scanf("%s",p[i].nam); 
		fflush(stdin);
		//输入max 
		puts("请输入该进程的各类资源的max");
		fun();
		for(j=0;j<re_n;j++){
			scanf("%d",&p[i].max[j]);
		}
		 //输入alloction 
		puts("请输入本进程各个资源已分配资源情况");
		fun();
		for(j=0;j<re_n;j++) {
			scanf("%d",&p[i].alloction[j]);
		}
		//输入need 
	/*	puts("请输入本进程对各个资源的需求量"); 
		for(j=0;j<re_n;j++){
			scanf("%d",&p[i].need[j]);
		}*/
		for(j=0;j<re_n;j++){
	  p[i].need[j]= p[i].max[j]-p[i].alloction[j]; 
		}
		p[i].finish=F; //进入安全区算法标志位 
	}
	show();
	if(check()==0){
		puts("安全性检测失败，有可能进入死锁");
		return 0; 
	} 
	else{
		puts("程序正常运行");
		return 1; 
	}
} 
void fun(){ //输出资源序号 
	int i=0;
	for(i=0;i<re_n;i++){
		printf(" %-2c  ",65+i); //输出的资源为字母 
	} 
	puts("\n"); 
}
void show(){
	int i=0;
	int j=0;
	puts("  当前所有数据  ");
	puts("       MAX      ");
	fun(); 
	for(i=0;i<pro_m;i++){
		for(j=0;j<re_n;j++){
		 printf("%-2d",p[i].max[j]);
	}
	puts("\n");
	} 
	
		puts("       alloction      ");
	fun(); 
	for(i=0;i<pro_m;i++){
		for(j=0;j<re_n;j++){
		 printf("%-2d",p[i].alloction[j]);
	}
	puts("\n");
   }
   
   	puts("       need      ");
	fun(); 
	for(i=0;i<pro_m;i++){
		for(j=0;j<re_n;j++){
		 printf("%-2d",p[i].need[j]);
	}
	puts("\n");
   }
   
   puts("avaible");
   for(i=0;i<re_n;i++){
   	printf("%-4d",avaible[i]);
   }
}

booL bank(int i){
	int j=0;
	int flag=0;

	for(j=0;j<re_n;j++){
		if(p[i].need[j]>=rqe.num[j]){
			;
		}else{
			flag=1;
			break;
		}
		if(avaible[j]>=rqe.num[j]){
			;
		}else{
		flag=2; 
		break;
	}
  }
  if(j<re_n){
  	if(flag==1){
  		printf("所需资源数目超过它现在需要的最大资源数目");
	  }
	  if(flag==2){
	  	puts("尚且没有足够资源，该进程暂时进入等待队列"); 
	  }
	  printf("输入错误，请重洗输入请求向量request\n");
	  return F;
  }
  else{
  	puts("请求向量合法");
  	int k=0;
  	for(k=0;k<pro_m;k++){
  		protmp[k]=p[k];
	  }
	  tryalloc(i);
	  show();
	  return T; 
  }
}

void tryalloc(int i){ //试着分配资源
 int j=0;
  for(j=0;j<re_n;j++){
  	avaibletmp[j]=avaible[j];
  }
  for(j=0;j<re_n;j++){
  	avaible[j]=avaible[j]-rqe.num[j];
  	p[i].alloction[j]=p[i].alloction[j]+rqe.num[j];
  	p[i].need[j]=p[i].need[j]-rqe.num[j];
  }
	
} 

int check(){  //安全性检测算法 
	int i=0;
	int j=0;
	int alpro=0;  
	int already[MAX];
    int add=0; //     ?
    int k=0;
    int temp_pro_m=pro_m;
    
	for(j=0;j<re_n;j++){
		work[j]=avaible[j];  //work向量初始等于avaible 
	} 
	for(i=0;i<pro_m;i++){
		for(j=0;j<re_n;j++){
			if(p[i].need[j]>work[j]){
				break;//跳到下一个进程 i+1个进程 
			}
		}
		if(p[i].finish==F && j==re_n) //need<work 如果是未完成的并且已经扫描到最后一种资源 
		{
			p[i].finish=T;
			already[add++]=i;
			for(k=0;k<re_n;k++){
				work[k]=work[k]+p[i].alloction[k];
			}
		if(p[i].recived==F){
	    	alpro++;  //已分配过资源的进程个数 
	    }else{
	    	temp_pro_m=temp_pro_m-1;
		}
		i=-1;  //重置i，为了寻找安全序列		
		}
		else{
			continue; 
		}
		if(alpro==temp_pro_m) //可以找出安全序列，输出并结束，每个进程的标志位finish都是false
		{
			puts("          现在的系统是安全的   ");
			puts("             安全序列为：      ");
			for(k=0;k<pro_m;k++){
				if(p[k].recived==F)
			    	printf("进程： %s",p[already[k]].nam);  //already存贮的是进程顺序序列 
	            if(k!=pro_m-1){
	            	printf("------>");
				}else{
					puts("\n");
				}	
			}
			return 1; 
		} 
	}
	puts("现在系统是不安全的，不能满足分配条件");
	return 0; 
}
void recive(int k){
	int i=0;
	int j=0;
		for(j=0;j<re_n;j++){
		   avaible[j]+=p[k].alloction[j];  //回收资源	
		   p[k].alloction[j]=0;
		}
}

int main(){
	system("color 5f"); //设置背景颜色为紫色，字体为白色
	puts("   *****************银行家算法的设计和实现**************");
	int chose=0;
	int i=0;
	int j=0;
	int flags=1;

	
	while(1){
		chose=input();  //等于1表示安全性检测成功 
		if(chose==1){
			break;
		}
	} 
	puts("                                                       ");
	for(i=0;i<pro_m;i++){
		p[i].finish=F;
		p[i].recived=F;
	}
	int k=0;
	int sign=1;
	int sign_recive=1;  //资源测试量 
    while(flags){
    	
	do{
		puts("请输出request进程名");
		//rqe.name=gets();
		 scanf("%s",rqe.name);
		 fflush(stdin);
		 puts("请输入requst对各资源的需求数量");
		 fun();
		 for(j=0;j<re_n;j++){
		   scanf("%d",&rqe.num[j]);
		 }
		 for(k=0;k<pro_m;k++){
		 	if(strcmp(rqe.name,p[k].nam)==0){
		 		break;
			 }
		 }
		 if(p[k].recived==T){
		 	puts("该程序运行结束，不能再参与申请");
		 	goto label;
		 }
	}while(!bank(k));
	int L=0;
	if(check()==0){
		puts("安全性检测失败，有可能产生死锁，该进程需要等待"); 
		for(L=0;L<re_n;L++){
			avaible[L]=avaibletmp[L];
		}
		int m=0;
		for(m=0;m<re_n;m++){
			p[m]=protmp[m];
		}
		show();
	}else{
		puts("进程顺利执行");
		for(i=0;i<pro_m;i++){
			sign_recive=0; 
			for(j=0;j<re_n ;j++){
				
				if(p[i].max[j]==p[i].alloction[j]){
					
					sign_recive++;

			    printf("sign_recive= %d ",sign_recive);  //测试语句 
			    if(sign_recive==re_n){
				puts("当前程序运行结束，系统回收资源"); 
				recive(i); 
				p[i].recived=T;
				sign_recive=0; 
				show();
				}
			}else{
					break;
				}
				
			}
		}
		
	//	return 1; 
    }
    
label:puts("是否继续操作"); 
    scanf("%d",&flags);
    if(flags==1){   //如果继续说明本次进程申请成功，但是下一次如果是继续的话需要对finish位置F 
    	for(i=0;i<pro_m;i++){
		p[i].finish=F;
	}
	}else{
		;
	} 	
  }
	return 0;
	
}
	

