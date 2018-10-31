#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	int k=0;
	int n=0,i=0,c=0;
	scanf("%d",&n);
	int j=(int)sqrt(n);
	printf("%d\n",j);
   for(i=2;i<=j;i++)
   {
   	if(n%i==0){
   	//	printf("%d不是质数",j);
	    break; 
	   }
	   
   }
   if(i>j) printf("%d是一个质数",n);
   else printf("%d不是一个质数",n); 
	return 0; 
} 
