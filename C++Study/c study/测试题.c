#include<stdio.h>

#if 0
struct mybitfields
{
    unsigned short a : 4;
    unsigned short b : 5;
    unsigned short c : 7;
} test;
 
int main0()
{
    int i;
    test.a = 2;
    test.b = 3;
    test.c = 0;
 
    i = *((short *)&test);
    printf("%d\n", i);
}

#endif 

#pragma pack(2)
struct A
{
 int a;
 char b;
 short c;
}A;

#pragma pack()
  
#pragma pack(4)
struct B
{
 char b;
 int a;
 short c;
}B;
#pragma pack()
void mer(char* str,int n) 
{
	char tmp='\0';
	int i=0;
	int len=strlen(str)+1;
	for(i=0;i<n;i++) 
	{
		tmp=str[len-1];
		for(j=len;j>0;j--)
		{
			a[j]=a[j-1];
		}
		str[0]=tmp;
	}
} 
 
int main()

{
    printf("sizeof(A)=%d,sizeof(B)=%d\n",sizeof(A),sizeof(B));
    return 0;
}



