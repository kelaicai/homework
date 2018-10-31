#include<sdtio.h>
#include<stdlib.h>
#include<mybank.h>
#define MAX 10

int re_n=0; //资源种类数
int pro_m=0; //进程数

int avaialable[MAX]={0};
int max[MAX][MAX]={0};
int allocation[MAX][MAX]={0};
int need[MAX][MAX]={0};
int request[MAX]={0};
int work[MAX][MAX]={0};
booL finish[MAX];

int tmp[MAX]={0};
char pro_name[MAX]=" ";  //进程名

void input(){
	int i=0;
	int j=0;
	puts("下面是输入各进程的各个矩阵的信息");
	puts("输入进程数目");
	scanf("%d",&pro_m);
	puts("请输入资源种类数");
	scanf("%d",&re_n);
    //avaialable
    puts("请输入avaible向量");
    for(i=0;i<re_n;i++){
    	scanf("%d",&avaialable[i]);
    }
    //进程名
    puts("输入进程名")
    for(i=0;i<pro_m;i++){
    	scanf("%c",pro_name);
    }
    //max
    puts("请输入这些进程的MAX矩阵")
	for(i=0;i<pro_m;i++){
		for(j=0;j<re_n;j++){
          scanf("%d",&max[i][j]);
		}
		puts("\n");
	}
    //alloction
	puts("请输入这些进程的allocation矩阵");
	for(i=0;i<pro_m;i++){
		for(j=0;j<re_n;j++){
          scanf("%d",&alloction[i][j]);
		}
		puts("\n");
	}
   //need
	puts("请输入这些进程的need矩阵");
	for(i=0;i<pro_m;i++){
		for(j=0;j<re_n;j++){
          scanf("%d",&need[i][j]);
		}
		puts("\n");
	}
   //初始化标志位finish
	for(i=0;i<pro_m;i++){
		finish[i]=F;
	}

}
void show(){
	int i=0;
	int j=0;
	//max
	puts("            max                   ");
	for(i=0;i<pro_m;i++){
		printf("%c  ",pro_name[i]);
		for(j=0;j<re_n;j++){
			printf("%3d",max[i][j]);
		}
		puts("\n");
	}
	//allocation
	puts("            alloction                   ");
	for(i=0;i<pro_m;i++){
		printf("%c  ",pro_name[i]);
		for(j=0;j<re_n;j++){
			printf("%3d",alloction[i][j]);
		}
		puts("\n");
	}
	puts("            need                  ");
	for(i=0;i<pro_m;i++){
		printf("%c  ",pro_name[i]);
		for(j=0;j<re_n;j++){
			printf("%3d",max[i][j]);
		}
		puts("\n");
	}
	//check need[i][j]=max[i][j]-alooction[i][j]
	for (i = 0; i < pro_m ; i++){
		for(j=0;j<re_n;j++){
			if(need[i][j]!=max[i][j]-alooction[i][j]){
				printf("%s\n","您所输入的数据有误" );
					exit(0);
			}else{
				continue;
			}
		}
		finish=F;
	}
}
int init_state(){
	input();
	//安全性检测 
	if(check_safe()==F){
        printf("安全检测失败,可能发生死锁\n");
		return 0;
	}else{
       
		printf("\n进程顺利执行.\n\n");
		return 1;
	} 
}
int check_safe(){  //安全性检测算法
   int allcated=0;  //记录已经被分配资源的进程个数
   int i=0;
   int j=0;
   int sequance[MAX];  //安全性序列
   int b=0;
   //初始化work
   for(i=0;i<re_n;i++){
   	work[i]=avaialable[i];  //work初始为avaiable
   }
   //need[i][j]<work[i][j]?
   for(i=0;i<pro_m;i++){
   	for(j=0;j<re_n;j++){
   		if(need[i][j]>work[j]){
           break;
   		}
   	}
   	int k;
   	if(finish[i]=F && j==re_n){  //当前进程并未被分配资源
   		finish[i]=T;
   		sequance[b++]=i;
   		for(k=0;k<re_n;k++){
   			work[k]=work[k]+alloction[i][k];
   		}
   		allcated++;
   		i=-1; //重置i，为了寻找安全序列
   	}
   	else{
   		continue;
   	}
   	if(allcated==pro_m){
   		printf("现在系统安全\n");
   		printf("安全序列为\n");
   			for(k=0;k<pro_m;k++){
   				printf("%c\n",p[k][k+1] );
   				if(k!=pro_m){
   					printf("--->");
   				}else{
                    printf("\n");
   				}
   			}
   			return 1;
   	}
   }
  puts("此时系统不安全，不能满足你的要求\n");
  return 0；
}
booL  banker(int id){
   int i=0;
   int flah=0;
   for(i=0;i<pro_m;i++){
   	for(j=0;j<re_n;j++)
   	if(need[i][j]>=request[j]){
   		;
   	}else{
   		flag=1;   //需要的资源超过最大值
   		braek;
   	}
   	if(avaialable[i][j]>=request[j]){
   		;
   	}else{
   		flag=2;
   		break; //需要的资源大于先可用资源数
   	}
   	if(j<n){
   		if(flag==1){
   			printf("所需要的资源数目超过它的最大需求值\n");
   		}
   		if(flag==2){
   			printf("所需资源超过先可用资源数目\n");
   		}
   		printf("输入错误，请重新输入request\n");
   		return F;
   	}
   	else{
   		printf("request正确\n");
   		int s=0;
   		for(s=0;s<pro_m;s++){
   			tmp[s]=i;
   		}
   	}
   	alloc(id);
   	show();
   	return T;
   }
}
void alloc(int id){
	int j=0;
	for(j=0;j<re_n;j++){
		tmp_available[j]=avaialable[j];
	}
	for(j=0;j<re_n;j++){
		avaialable[j]-=request[j];
		alloction[id][j]=alloction[id][j]+request[j]
		need[id][j]=need[id][j]-request[j];
	}
}
int main(int argc, char const *argv[])
{
	/* code */
	system("color 3f");  //变更颜色
	puts("                    银行家算法实现            小彪版");
	int chose=0;
	int i=0;
	int j=0;
	int pro_id;
	while(1){
		chose=input();
		if(chose==1){
			break;
		}
	} 
	puts("\n");
	for(i=0;i<pro_m;i++){
		finish[i]=F;
	}
	int x=0;
	int flag=1;
	do{
		puts("请输入发出request的进程编号(0-%d) ");
		scanf("%d",&pro_id);
		fllush(stdin);
		printf("请输入发出request向量的对对应值\n");
		for(i=0;i<re_n;i++){
			scanf("%d",&request[i]);
		}
	}while(banker(pro_id));
	int h=0;
	if(check_safe()==0){
		printf("安全性检测失败，可能会发生死锁，该进程需要等待\n");
        for(h=0;h<re_n;h++){
        	avaialable[h]=tmp_available[h];
        }
        int s;
      show();
	}
	 else{
      	printf("进程顺利执行\n");
      	return 1;
      }
	return 0;
}




