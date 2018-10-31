#include<stdio.h>
#include<stdlib.h>

void display(int *arr,int length);
void insert(int *a,int *num,int length)
{
	int i=0;
	int tmp=0;
	int j=0;
	for(i=0;i<length;i++)
	{
		if(a[i]>=*num)
		{
		    for(j=length-1;j>=i;j--)
		    {
		      a[j]=a[j-1];
			}
			a[i]=*num;
			display(a,10);
		}
	}
}
int func(int *a,int length)
{
  int pf=1;
  int num=0;
  while(pf==1)
  {
  	printf("请输入要插入得数\n");
  	scanf("%d",&num);
  	insert(a,&num,sizeof(a));
  	pf=0;
  }	
}
void display(int *arr,int length)
{
	int i=0;
    for(i=0;i<length;i++)
	{
		printf("%3d",arr[i]);
	}
}
int main()
{
  int a[10]={1,2,4,6,9,10,20};
  func(a,(int)sizeof(a));
  printf("result is \n"); 
  display(a,10);
} 
