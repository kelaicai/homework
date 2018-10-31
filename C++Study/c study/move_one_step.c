#include<stdio.h>

int main()
{
	int a[10]={2,3,4,5,6,1,1};
    int tmp=0;
    int i=0;
    int j=0;
    for(i=9;i>=0;i--)
    {
    	a[i]=a[i-1];
	}
	for(i=0;i<10;i++)
    {
    	printf("%3d",a[i]);
	}
	
}
