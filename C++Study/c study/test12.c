#include<stdio.h>
int main(){
	int a[5]={0};
	int *r=&a;
	int j=0;
	for(j=0;j<5;j++)
	printf("%d",*(r+j));
} 
