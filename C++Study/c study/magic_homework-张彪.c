/*
 edit by jack zhang 
 2018-3-18
 the magic metrix
*/
//如果编译平台不是VS系列，下面语句可以省略，或者使用安全版本_s函数
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
//使用宏定义的方式定义维度，可以减少程序后期的修改力度，增加程序的可维护性
#define N 10
//the error display 这个函数不可用，应为对应的i*col+j是以10为一列的，仅此以后要注意
void display1(int *arr, int row, int col);
//显示目标二维数组
void dispaly2(int(*arr)[N], int row, int col);

int input(void);

void magic_metrix(int(*a)[N], int n);

int input(void)
{
	int n = 0;
	int p = 1;
	while (p == 1)
	{
		printf("enter the value of the row(col=row)\n");
		scanf("%d", &n);
		if (n != 0 && n <= N && n % 2 != 0)
		{
			p = 0;
		}
	}
	return n;
}
void magic_metrix(int(*a)[10], int n)
{
	int i = 0;
	int j = 0;
	int k = 0;
	j = n / 2;
	a[0][j] = 1;
	for (k = 2; k <= n*n; k++)
	{
		i = i - 1;
		j = j + 1;
		if (i<0 && j == n) //前一个数是第一行第N列时，下一个数放在上一个数的下面 
		{
			i = i + 2;
			j = j - 1;
		}
		else
		{
			if (i<0) /*行数减到第一行，返回到最后一行*/
			{
				i = n - 1;
			}
			if (j>n - 1)/*到最后一列则返回第一列*/
			{
				j = 0;
			}
		}
		if (a[i][j] == 0)  //如果当前位置未被占领
		{
			a[i][j] = k;
		}
		else  //当前位置有数就将它放在上一个数的下面
		{
			i = i + 2;
			j = j - 1;
			a[i][j] = k;
		}
	}

}

void display1(int *arr, int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i<row; i++)
	{
		for (j = 0; j<col; j++)
		{
			printf("%5d", arr[i*col + j]);
		}
		printf("\n\n");
	}
}

void display2(int(*arr)[N], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i<row; i++)
	{
		for (j = 0; j<col; j++)
		{
			printf("%5d", arr[i][j]);
		}
		printf("\n\n");
	}
}
int main()
{
	int a[N][N] = { 0 };
	int n = input();
	magic_metrix(a, n);
	//	display1((int *)a,n,n);
	display2(a, n, n);
	system("pause");
}