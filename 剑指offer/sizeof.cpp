#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Test(void)
{
	char *str=(char *)malloc(100);
 strcpy(str, "hello");
free(str);
if(str != NULL)
{
strcpy(str,"world");
printf(str);
}
}
int main()
{
	char str[] = "http://www.ibegroup.com/";
//	char *p = str ;
	int n = 10;
//	int *p=(int *)malloc(100);
//	printf("%d",sizeof(p));
 int i=10, j=10, k=3; k*=i+j;
//Test();
printf("%d", k);
}

class myString
{
}; 


