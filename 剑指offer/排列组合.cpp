#include<iostream>
#include<string.h>
using namespace std;
#define N 4

void perm(int *,int );

int main()
{
	int num[N+1];
	for(int i=i;i<=N;++i)
	{
		num[i]=i;
		perm(num,1);
	}
 } 
 
void perm(int* num,int i){
	int j,k,tmp;
	if(i <N)
	{
		for(j = i;j<=N;j++)
		{
		tmp =num[j];
		// ��ת���������ұ������������
		for(k = j;k > i;k--)
		num[k] =num[k-1];
		num[i] =tmp;
		perm(num,i+1);
		// ��ԭ
		for(k = i;k < j;k++)
		num[k] =num[k+1];
		num[j] =tmp;
		}
	}
	else{ // ��ʾ�˴�����
	for(j = 1;j<= N;j++)
	printf("%d ",num[j]);
	printf("\n");
	}
}
 
 
 
 
 
 
 
