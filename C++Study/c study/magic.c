#include<stdio.h>
void main()
{int a[16][16],i,j,k,p,m,n;
p=1;
while(p==1)
   {printf("请输入阶数:");   /*原答案没有这个输出语句*/
     scanf("%d",&n);
    if((n!=0)&&(n<=15)&&(n%2!=0))p=0;
   }
for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
     a[i][j]=0;
j=n/2+1;
a[1][j]=1;
for(k=2;k<=n*n;k++)
   {i=i-1;
    j=j+1;
    if((i<1)&&(j>n))
      {i=i+2;
       j=j-1;
      }
    else
      {if(i<1)i=n;
       if(j>n)j=1;
      }
    if(a[i][j]==0)a[i][j]=k;
    else
      {i=i+2;
       j=j-1;
       a[i][j]=k;
      }
    }
for(i=1;i<=n;i++)
   {for(j=1;j<=n;j++)
      printf("%3d",a[i][j]);
    printf("\n");
   }
   
}
