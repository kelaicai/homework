#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void bubble_sort(int a[],int n);
void swap(int *i,int *j);
int main(){
	int i=0;
	int j=0;
	int a[10]={15,85,5,4,7,56,75,25,55,46};
	srand(NULL);
	for(i=0;i<10;i++){
		a[i]=rand()/8;
		printf("%8d  ",a[i]);
	}
	printf("\n");
     bubble_sort(a,10) ;
     for(i=0;i<10;i++){
     	printf("%8d   ",a[i]);
	 } 
     system("pause");	
	return 0;
} 
void bubble_sort(int a[],int n){
	int i=0;
	int j=0;
	for(i=0;i<n-1;i++){
//	int flag=0;
	for(j=0;j<n-i-1;j++)
	{
		if(a[j]>a[j+1]){
	  	swap(&a[j],&a[j+1]);
		//flag=1;
		}
	 }
	// if(flag==1) break; 
   }
}
void swap(int *i,int *j){
	int temp=2;
	temp=*i;
	*i=*j;
	*j=temp;
}
