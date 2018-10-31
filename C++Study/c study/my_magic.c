#include<stdio.h>

void display1(int *arr,int row,int col);

void dispaly2(int (*arr)[10],int row,int col);
int input(void);

void magic_metrix(int (*a)[10],int n);

int input(void)
{
    int n=0;
	int p=1;
	while(p==1)
	{
	   printf("enter the value of the row(col=row)\n");
	   scanf("%d",&n);
	   if(n!=0 && n<=10 && n%2!=0)
	   {
	      p=0;	
	   }	
	} 
	return n; 
} 
void magic_metrix(int (*a)[10],int n)
{
	int i=0;
	int j=0;
	int k=0;
	j=n/2;
	a[0][j]=1;
	for(k=2;k<=n*n;k++)
	{
		i=i-1;
		j=j+1;
		if(i<0 && j==n) //前一个数是第一行第N列时，下一个数放在上一个数的下面 
		{
			i=i+2;
			j=j-1;
		}
		else
		{
			if(i<0) /*行数减到第一行，返回到最后一行*/
			{
			i=n-1;
		    }
		    if(j>n-1)/*到最后一列则返回第一列*/
		    {
		    	j=0; 
			}
		 }
		 if(a[i][j]==0)
		 {
		   	a[i][j]=k;
	     }
		 else
		 {
		 	i=i+2;
		 	j=j-1;
		 	a[i][j]=k;
		 }
	}

}

void display1(int *arr,int row,int col)
{
	int i=0;
	int j=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%5d",arr[i*col+j]);
		}
		printf("\n\n");
	}	
}

void display2(int (*arr)[10],int row,int col)
{
	int i=0;
	int j=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%5d",arr[i][j]);
		}
		printf("\n\n");
	}	
}
int main()
{
	int a[10][10]={0}; 
	int n=input();
	magic_metrix(a,n);
	//	display1((int *)a,n,n);
    display2(a,n,n);
}
