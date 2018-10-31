#include<stdio.h>
#define MAXSIZE 10
typedef struct
{
	int r[MAXSIZE+1];  //���ڴ洢�������飬r[0]���ڸ� 
	int length;   //˳���ĳ��� 
} SqList;
 /*�鲢����*/
 void Merge(int SR[],int TR[],int i,int m,int n)
{
	int j,k,l;
	for(j=m+1,k=i;k<m && j<=n;k++)
	{
		if(SR[i]<SR[j])
		TR[k]=SR[i++];
		else
		TR[k]=SR[j++];
	} 
	if(i<m)
	{
		for(l=0;l<m-i;l++)
		TR[k+1]=SR[i+1];
	}
	if(j<=n)
	{
		for(l=0;l<n-j;l++)
		TR[k+1]=SR[j+1];
	}
}
 /*��SR[s..t]�鲢����ΪTR1[s..t]*/
void MSort(int SR[],int TR[],int s,int t)
{
	int m=0;
	int TR2[MAXSIZE+1];
	if(s==t)
	TR[s]=SR[s];
	else 
	{
		m=(s+t)/2;/*��SR[s..t]ƽ��ΪSR[s..m]��SR[m+1..t]*/
		MSort(SR,TR2,s,m);  /*�ݹ齫SR[s..m]�鲢Ϊ�����TR2[s..m]*/
		MSort(SR,TR2,m+1,t); /*�ݹ齫SR[m+1..t]�鲢Ϊ�����TR2[m+1..t]*/
		Merge(TR,TR,s,m,t);  /*��TR2[s..m]��TR2[m+1..t]�鲢��TR1[S..T]*/
	 } 

}

void MergeSort(SqList L)
{
 	MSort(L.r,L.r,1,L.length);
} 

int main()
{
	int tr[10]={0,50,10,90,30,701,40,80,60,20};
	SqList l={tr[10],10};
	MergeSort(l);
	return 0;
}
