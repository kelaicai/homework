#include<stdio.h>
#include<stdlib.h>

typedef int Arr[10];
typedef long Long;
typedef int *(pFun)(int, int);
typedef int (*P)[10];
//空结构体的
typedef struct A
{

}b;

typedef struct A1
{
	char a;
	int b;
}A;
int main()
{
	printf("%d",sizeof(A));
	getchar();
}
