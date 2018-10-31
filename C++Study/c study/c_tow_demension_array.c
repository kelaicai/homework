#include<stdio.h>
#include<stdlib.h>

void show(int *arr,int row,int col)
{
	int i=0;
	int j=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%d",arr[i*col+j]);
		}
	printf("\n"); 
	}

} 
void show2(int *arr,int row,int col)
{
	int i=0;
	int j=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<=i;j++)
		{
			printf("%d",arr[i*col+j]);
		}
		puts("\n"); 
	}

} 
void transfer(int (*arr1)[3],int (*arr2)[2],int row,int col)
{
    int i=0;
	int j=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
		    	arr2[j][i]=arr1[i][j];
		} 
	}	
} 
void YH(int (*arr)[10],int row,int col)
{
	int i=0;
	int j=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			arr[i][j]=0; 
		}
	}
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(i==j|| j==0)
			{
				arr[i][j]=1;
			}
			else
			{
				arr[i][j]=arr[i-1][j]+arr[i-1][j-1];
			}
		}
	}
}

void Magicmetrix(int (*arr)[3],int n)
{
	
}
int main()
{
 int arr[2][3]={1,2,3,4,5,6};
 int arr2[3][2];
  int arr3[10][10]={0};
  int arr4[3][3];
 transfer(arr,arr2,2,3);
 show((int*)arr2,3,2);
 
 YH(arr3,10,10);
  show2((int*)arr3,10,10);
  Magicmetrix(arr4,3,3);
 } 
