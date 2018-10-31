#include<stdio.h>
#define MAXSIZE 10
typedef struct
{
	int r[MAXSIZE+1];  //用于存储排序数组，r[0]座哨岗 
	int length;   //顺序表的长度 
} SqList;
 /*归并排序*/
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
 /*将SR[s..t]归并排序为TR1[s..t]*/
void MSort(int SR[],int TR[],int s,int t)
{
	int m=0;
	int TR2[MAXSIZE+1];
	if(s==t)
	TR[s]=SR[s];
	else 
	{
		m=(s+t)/2;/*将SR[s..t]平分为SR[s..m]和SR[m+1..t]*/
		MSort(SR,TR2,s,m);  /*递归将SR[s..m]归并为有序的TR2[s..m]*/
		MSort(SR,TR2,m+1,t); /*递归将SR[m+1..t]归并为有序的TR2[m+1..t]*/
		Merge(TR,TR,s,m,t);  /*将TR2[s..m]和TR2[m+1..t]归并到TR1[S..T]*/
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
