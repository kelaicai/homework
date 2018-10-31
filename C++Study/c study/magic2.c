#define N 3
#include<stdio.h>
void main()
{
  int a[N][N],i,j,k;
  for(i=0;i<N;i++)    //*<="" span="" style="word-wrap: break-word;">先处理第一行*/
    for(j=0;j<N;j++)
     {
      a[i][j]=0;     /*先令所有元素都为0*/
    }
      j=(N-1)/2;     /*判断j的位置*/
      a[0][j]=1;    /*将1放在第一行中间一列*/
  for(k=2;k<=N*N;k++)    /*再从2开始处理*/
    {
      i=i-1;    /*存放的行比前一个数的行数减1*/
      j=j+1;    /*存放的列比前一个数的列数加1*/
      if((i<0)&&(j==N))   /*前一个数是第一行第N列时,把下一个数放在上一个数的下面*/
      {
        i=i+2;
        j=j-1;
      }
      else
      {
        if(i<0)    /*当行数减到第一行，返回到最后一行*/
        i=N-1;
        if(j>N-1)   /*当列数加到最后一行，返回到第一行*/
        j=0;
      }
      if(a[i][j]==0)     /*如果该元素为0,继续执行程序*/
        a[i][j]=k;
      else     /*如果该元素不为0,就说明要填的数的位置已经被占,则该数放在上一个数的下面*/
      {
        i=i+2;
        j=j-1;
        a[i][j]=k;
      }
    }
    for(i=0;i<N;i++) //   *<="" span="" style="word-wrap: break-word;">输出数组*/
    {
      for(j=0;j<N;j++)
       printf("%5d",a[i][j]);
      printf("\n\n");
    }
  }
