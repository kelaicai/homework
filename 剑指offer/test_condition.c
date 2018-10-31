#include<stdio.h>

int main()
{
	int x=1;
	int y=x;
	int z=x;
	int t= ++x || ++y && ++z;
	printf("%d",t); 
 } 
