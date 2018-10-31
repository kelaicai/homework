#include<stdio.h>
#include<stdlib.h>

#define Row 3
void Metrix()
{
	int arr[Row][Row] = { 0 };
	arr[0][Row / 2]=1;
	int i = 0;
	int j = 0;
	//start
	int CurRow = 0;
	int CurCol = Row / 2;
	//放2到9这些数字
	
	for (i = 2; i<=Row*Row; i++)
	{
		if (arr[(CurRow - 1 + Row) % Row][(CurCol + 1 ) % Row] != 0)
		{
			CurRow = (CurRow + 1) % Row;
		}
		else
		{
			CurRow = (CurRow - 1 + Row) % Row;
			CurCol = (CurCol + 1 ) % Row;
		}
		arr[CurRow][CurCol] = i;
	}
	for (i = 0; i<Row; i++)
	{
		for (j = 0; j<Row; j++)
		{
			printf("%2d", arr[i][j]);
		}
		printf("\n");
	}
}
//质数又称素数。一个大于1的自然数，除了1和它自身外，不能被其他自然数整除的数叫做质数；否则称为合数。
void Select_prime()
{
	int arr[100];
	int i=0;
	int j=0;
	for(i=0;i<100;i++)
	{
     arr[i]=i;		
	}
	
	for(i=2;i<100;i++)
	{
		for(j=i+1;j<100;j++)
		{
			if(j%i==0)
			{
				arr[j]=0;
			}
		}
	}
	for(i=0;i<100;i++)
	{
		if(arr[i]!=0)
		{
			printf("%4d",arr[i]);
		}
	}
	
}
int main()
{
	Metrix();
	printf("\n\n\n");
	Select_prime();
	getchar();
	return 0;
}
