#include<stdio.h>
int main( )
{
   int i,j,n=0,xx[1000];
   for(i=1;i<1000;i++)
   { 
   for(j=2;j<i;j++)
     if(i%j==0) break;
    if(j>=i) /*保证i以下的每个数都不能被i整除*/
    xx[n++]=i;
    }
    printf("1到1000以内的所有素数如下\n");
    for(i=0;i<n;i++)
    printf(" %d ",xx[i]);
    printf("\n 共有n=%d个素数 \n",n);
    return 0;
}

