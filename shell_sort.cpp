#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	
	int a[10];
	void shell_sort(int a[],int n);
	void swap(int *a,int *b);
	void print(int a[]);
	srand(NULL);
	print(a);
	shell_sort(a,10);
	printf("******************************************");
	print(a);
	return 0;
} 
void swap(int *a,int *b)
{
	*a=*a^*b;
	*b=*a^*b;
	*a=*a^*b;
}
void shell_sort(int a[],int n)
{
	int k=0;
	int i=0;
	int j=0;
/*	for(k=n/3;k>=1;k=k/2)
	{
		for(i=0;i<=k;i++){
			for(j=k+1;j<n;j=k+i){
			if(a[i]>a[k])
			swap(&a[i],&a[k]);
		}
	}
	}*/
}

void print(int a[]){
	
	int i=0;
	for(i=0;i<10;i++)
	{
		if(i%5==0)
		puts("\n");
		a[i]=rand()/7;
		printf("%10d %d",a[i],i);
	}
}
