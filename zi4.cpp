#include<stdio.h>
int main( )
{
   int i,j,n=0,xx[1000];
   for(i=1;i<1000;i++)
   { 
   for(j=2;j<i;j++)
     if(i%j==0) break;
    if(j>=i) /*��֤i���µ�ÿ���������ܱ�i����*/
    xx[n++]=i;
    }
    printf("1��1000���ڵ�������������\n");
    for(i=0;i<n;i++)
    printf(" %d ",xx[i]);
    printf("\n ����n=%d������ \n",n);
    return 0;
}

