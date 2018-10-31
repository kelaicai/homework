#include<stdio.h>

typedef union add
{
	char buf[4];
	int val;
}add;



int main()
{
	
	add tal;
	tal.val=0x12345678;
	tal.buf[1]=0x22;
	printf("%x",tal.val);
	printf("%d\n",sizeof(add));
		/*
	char str[][10]={{"abc"},{""}};
	char* st[]={"abc","elf"};
	printf("%d\n",sizeof(str));
	printf("%d",sizeof(st)); 
	*/
} 
