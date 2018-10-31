#include<stdio.h>
#include<stdlib.h>

void func( )
{
	for(i=0;i<n;i++)
	  {
	  	for(j=0;j<n;j++)
	  	{
	  	   	sum1+=a[j][j]++; //行的和 
	  	   	a[j][j]+=1;
		}
	  	for(j=0;j<n;j++)
	  	{
	  	   	sum2+=a[i][j]++; //行的和 
	  	   		a[i][j]+=1;
		}
		for(j=0;j<n;j++)
		{
		   sum3+=a[j][i];	 //列的和 
		   	a[j][i]+=1;
		} 
	  if(sum1==sum2 && sum2==sum3)
	  {
	  	show();
	  }
	  else
	  {
	  	a[i][j];
	  }
	   
	}
}
int main()
{
	
}
