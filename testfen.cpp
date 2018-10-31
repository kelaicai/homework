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

void showdata()//��ʾ������������
{
	int i, j;
	printf("��ǰ�������ݣ�\n");
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
	printf("������ϵͳ�ṩ����Դ�������Ŀ��");
	scanf("%d",&n);
	fflush(stdin);
	printf("available����Դ�ĸ�����\n");
	func();
	for (int i =0;i<n;i++)
	{
		scanf("%d", &available[i]);
	}
	printf("��������̵ĸ�����");
	scanf("%d", &m);
	fflush(stdin);	
	for(int i=0;i<m;i++)
	{
		printf("��������̵����ƣ�");
		scanf("%s",p[i].name);
		fflush(stdin);
		printf("�����뱾���̸���Դ��Max��\n");
		func();
		for (int j=0;j<n;j++)
		{
			scanf("%d", &p[i].Max[j]);
		}

		printf("�����뱾���̸���Դ��Allocation��\n");
		func();
		for (int j=0;j<n;j++)
		{
			scanf("%d", &p[i].Allocation[j]);

		}
		printf("�����뱾���̸���Դ��Need��\n");
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
				printf("���������쳣\n");
				exit(0);
			}
		}
		p[i].finish=false;//���밲ȫ���㷨���ñ�־��
	}
	showdata();
	if (check() == 0)
	{
		printf("��ȫ���ʧ��,���ܷ�������\n");
		return 0;
	}
	else
	{
		printf("\n����˳��ִ��.\n\n");
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
			printf("������Դ��Ŀ�����������������ֵ\n");
		}
		if (sign_bank==2)
		{
			printf("�����㹻��Դ���ý��̵ȴ�\n");
		}
		printf("�������������������������\n");
		return false;
	}
	else
	{
		printf("����������ȷ\n");
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

void tryalloc(int i)//�Է��䡣
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
int check()//��ȫ���㷨�����ҽ���
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
				break;//������һ�����̣���i+1��
			}
		}
		int k;
		if(p[i].finish==false && j==n)//Need<workʱ���������ܷ��䣬������Դ������������
		{
			p[i].finish = true;
			already[b++]=i;
			for (k = 0; k < n; k++)
			{
				work[k] = work[k] + p[i].Allocation[k];
			}
			l++;//�Ѿ��ֹ���Դ�Ľ��̸�����
			i = -1;///����i��Ϊ��Ѱ�Ұ�ȫ����
		}  
		else
		{
			continue;
		}
		if (l == m)//�����ҵ���ȫ���У������������ÿһ�����̵�Finish����trueʱ��
		{
			printf("\nϵͳ��ȫ!\n");
			printf("��ȫ����Ϊ��\n");
		
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
	printf("\nϵͳ����ȫ�������������Ҫ��\n");
	return 0;
}

int exist(int a[],int i,int count)
{//������������в����Ƿ��иý���
	for(int j = 0; j < count; j++)
	{
		if(a[j] == i)
		{
			return 1;
		}
	}
	return 0;
}

void func()///�����Դ���
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
	
	printf("			���м��㷨�������ʵ��\n\n");
	int t;
	while (1)//����ѭ��
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
		printf("������request������: ");
		
		scanf("%s",rq.name);
		fflush(stdin);
		printf("������request����Դ��Ŀ��\n");
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
		printf("��ȫ���ʧ��,���ܷ�������,�ý�����ȴ�\n");
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
		printf("\n����˳��ִ��.\n\n");
		return 1;
	}	

	return 0;
}





