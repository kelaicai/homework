#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _request
{
	char name[10];
	int num[10];
}request;
typedef struct _PCB
{
	char name[10];
	int Max[10];
	int Allocation[10];
	int Need[10];
	bool finish;
}PCB;

PCB p[20];
PCB tmpp[20];

int available[10];
int tmp_available[10];

int work[10];
int work_allocation[10];

request rq;

int n;
int m;
void tryalloc(int );

int safe_array[10];
void func();
int check();

void showdata()//显示现在所有数据
{
	int i, j;
	printf("当前所有数据！\n");
	printf("\nMax\n");
	printf("   ");
	func();
	for (i = 0; i < m; i++)
	{
		printf("p%d ", i);
		for (j = 0; j < n; j++)
		{
			printf("%d ", p[i].Max[j]);
		}
		printf("\n");
	}

	printf("\nAllocation\n");
	printf("   ");
	func();
	for (i = 0; i < m; i++)
	{
		printf("p%d ", i);
		for (j = 0; j < n; j++)
		{
			printf("%d ",p[i].Allocation[j]);
		}
		printf("\n");
	}

	printf("\nNeed\n");
	printf("   ");
	func();
	for (i = 0; i < m; i++)
	{
		printf("p%d ", i);
		for (j = 0; j < n; j++)
		{
			printf("%d ", p[i].Need[j]);
		}
		printf("\n");
	}
	printf("\nAvailable\n");
	func();
	for (i = 0; i < n; i++)
	{
		printf("%d ", available[i]);
	}
	printf("\n===============================================================\n");
	printf("\n\n\n");
	return;
}

int init()
{
	printf("请输入系统提供的资源种类的数目：");
	scanf("%d",&n);
	fflush(stdin);
	printf("available各资源的个数：\n");
	func();
	for (int i =0;i<n;i++)
	{
		scanf("%d", &available[i]);
	}
	printf("请输入进程的个数：");
	scanf("%d", &m);
	fflush(stdin);	
	for(int i=0;i<m;i++)
	{
		printf("请输入进程的名称：");
		scanf("%s",p[i].name);
		fflush(stdin);
		printf("请输入本进程各资源的Max：\n");
		func();
		for (int j=0;j<n;j++)
		{
			scanf("%d", &p[i].Max[j]);
		}

		printf("请输入本进程各资源的Allocation：\n");
		func();
		for (int j=0;j<n;j++)
		{
			scanf("%d", &p[i].Allocation[j]);

		}
		printf("请输入本进程各资源的Need：\n");
		func();
		for (int j=0;j<n;j++)
		{
			scanf("%d", &p[i].Need[j]);

		}
		for(int j=0;j<n;j++)
		{
			if (p[i].Max[j] - p[i].Allocation[j] == p[i].Need[j])
			{
				break;
			}
			else
			{
				printf("输入数据异常\n");
				exit(0);
			}
		}
		p[i].finish=false;//进入安全性算法，置标志。
	}
	showdata();
	if (check() == 0)
	{
		printf("安全检测失败,可能发生死锁\n");
		return 0;
	}
	else
	{
		printf("\n进程顺利执行.\n\n");
		return 1;
	}
	
}
bool bank(int i)
{
	int j;
	int sign_bank = 0;
	for (j=0;j<n;j++)
	{
		if (p[i].Need[j] >= rq.num[j])
		{
		}
		else
		{
			sign_bank = 1;
			break;
		}
		if (available[j] >=rq.num[j])
		{
			
		}
		else
		{
			sign_bank = 2;
			break;
		}
	}
	if (j<n)
	{
		if (sign_bank==1)
		{
			printf("所需资源数目超出它所宣布的最大值\n");
		}
		if (sign_bank==2)
		{
			printf("尚无足够资源，该进程等待\n");
		}
		printf("输入错误，请重新输入请求向量\n");
		return false;
	}
	else
	{
		printf("请求向量正确\n");
		int s;
		for (s=0;s<m;s++)
		{
			tmpp[s] = p[s];
		}
		
		tryalloc(i);
		showdata();
		return true;
	}
}

void tryalloc(int i)//试分配。
{
	int j;
	for ( j=0;j<n;j++)
	{
		tmp_available[j] = available[j];
	}
	for (j=0;j<n;j++)
	{
		available[j] -=rq.num[j];
		p[i].Allocation[j] += rq.num[j];
		p[i].Need[j] -= rq.num[j];
	}

}

bool find()
{
	return false;
}
int check()//安全性算法，查找进程
{
	int l =0;
	int j;
	int already[10];
	int b=0;
	for ( j=0;j<n;j++)
	{
		work[j] = available[j];
	}
	for(int i=0;i<m;i++)
	{
		for (j = 0; j < n; j++)
		{
			if (p[i].Need[j] > work[j])
			{
				break;//跳到下一个进程，第i+1个
			}
		}
		int k;
		if(p[i].finish==false && j==n)//Need<work时，进来就能分配，所有资源都满足条件。
		{
			p[i].finish = true;
			already[b++]=i;
			for (k = 0; k < n; k++)
			{
				work[k] = work[k] + p[i].Allocation[k];
			}
			l++;//已经分过资源的进程个数。
			i = -1;///重置i，为了寻找安全序列
		}  
		else
		{
			continue;
		}
		if (l == m)//可以找到安全序列，输出并结束，每一个进程的Finish都是true时。
		{
			printf("\n系统安全!\n");
			printf("安全序列为：\n");
		
			for (k = 0; k < m; k++)
			{
				printf("%s", p[already[k]].name);
				if (k != m - 1 ) 
				{
					printf("-->");
				}
				else
				{
					printf("\n");
				}
			}
		
			return 1;
		}
	}
	printf("\n系统不安全，不能满足你的要求！\n");
	return 0;
}

int exist(int a[],int i,int count)
{//在已完成序列中查找是否有该进程
	for(int j = 0; j < count; j++)
	{
		if(a[j] == i)
		{
			return 1;
		}
	}
	return 0;
}

void func()///输出资源序号
{
	int k;
	for (k = 0; k < n; k++)
	{
		printf("%c ",65+k);
	}
	printf("\n");
}


int main()
{
	
	printf("			银行家算法的设计与实现\n\n");
	int t;
	while (1)//声明循环
	{
		t = init();
		if (t == 1)
		{
			break;
		}
	}
	printf("\n===============================================================\n");
	
	for (int q=0;q<m;q++)
	{
		p[q].finish = false;
	}
	int x=0;
	int sign =1;

	do 
	{
		printf("请输入request进程名: ");
		
		scanf("%s",rq.name);
		fflush(stdin);
		printf("请输入request各资源数目：\n");
		func();
		for (int j=0;j<n;j++)
		{
			scanf("%d", &rq.num[j]);
		}
		for( x=0;x<m;x++)
		{

			if (strcmp(rq.name,p[x].name)==0)
			{
				break;
			}
		}
	} while (!bank(x));	
	int h;
	if (check() == 0)
	{
		printf("安全检测失败,可能发生死锁,该进程需等待\n");
		for ( h=0;h<n;h++)
		{
			available[h] = tmp_available[h];
		}
		int s;
		for (h=0;h<m;h++)
		{
			p[h] = tmpp[h];
		}
		showdata();
	}
	else
	{
		printf("\n进程顺利执行.\n\n");
		return 1;
	}	

	return 0;
}





