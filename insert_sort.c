#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 1000
int a[N];
int main(){
	
	void init(int a[]);
	void insert_sort();
	void swap(int *a,int *b);
	void print(int a[]);
   init(a);
   print(a);
   insert_sort(a,N);
   printf("\n*****************");
   print(a);
   return 0;
}
void init(int a[]){
    int i=0;
	for(i=0;i<N;i++){
		a[i]=rand()/100;
	}
}
void print(int a[]){
		int i=0;
	for(i=0;i<N;i++)
	{
		if(i%10==0)
		puts("\n");
		printf("%10d %d",a[i],i);
	}
}

void swap(int *a,int *b){
	*a=*a^*b;
	*b=*a^*b;
	*a=*a^*b;
}
void insert_sort(int a[],int n){
	int i=0;
	int j=0;
	for(i=1;i<N;i++){
		for(j=0;j<=i;j++){
			if(a[i]>a[j]){
				swap(&a[i],&a[j]);
			}
		}
	}
}
