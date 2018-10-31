#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void display(int *arr,int length)
{
	int i=0;
    for(i=0;i<length;i++)
	{
		printf("%3d",arr[i]);
	}
	printf("\n");
}
void pope(int *a,int n)
{
	int i=0;
	int j=0;
	int tmp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<=n-i-1;j++)
		{
			if(a[j+1]<a[j])
			{
			  tmp=a[j+1];
			  a[j+1]=a[j];
			  a[j]=tmp;	
			}
		}
	}
}
void choice_sort1(int *a,int n)
{
	int i=0;
	int j=0;
	int tmp;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
		  if(a[i]<=a[j])
		  {
		     tmp=a[j];
		     a[j]=a[i];
		     a[i]=tmp;
		  }
		}
	}
}
void choice_sort2(int *a,int n)
{
	int i=0;
	int j=0;
	int tmp;
	int flag=0;
	int min=0;
	for(i=0;i<n;i++)
	{
		flag=i;
		min=a[i];
		tmp=a[i];
		for(j=i;j<n;j++)
		{
		  if(min<=a[j] && tmp<=a[j])
		  {
		     tmp=a[j];
		      flag=j;
		  }
		}
		tmp=a[flag];
		a[flag]=a[i];
		a[i]=tmp;
	}
}
int main()
{
	int a[20];
	int i=0;
	for(i=0;i<20;i++)
	{
		a[i]=rand()/1000;
	}
	printf("Ô­À´\n");
	display(a,20);
//	pope(a,20);
    choice_sort2(a,20);
    printf("ÅÅÐòºó\n");
	display(a,20);
	
}
