#include<stdio.h>
#define SWAP(x,y)  { ((x)=(x)+(y)); ((y)=(x)-(y)); ((x)=(x)-(y)); }

int main(){
   int x=1,y=0;
   SWAP(x,y)
   printf("a=%d b=%d",x,y);
} 
