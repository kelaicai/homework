#include<stdio.h>
#include<stdlib.h>
#include<time.h> 

int bit_sum(int para)
{
	int  num=0;
	while(para)
	{
		num+=para%10;
		para/=10;
	}
	return num;
}

int init_time()
{
	time_t seed;
	time(&seed);
	srand(seed);
	int res=rand();
	return res;
}
int binarry_sort()
{
   int guess=init_time()%100;
   int i=0;
   char buffer[128];
  int begin=0;
  int end=100;
  
  
   for(i=0;i<7;i++)
   {
   		printf("is this num  %d more or low than yours?\n",guess);
   		scanf("%s",buffer);
   	    if((strcmp(buffer,"more"))==0)
   	    {
   	       guess=(end-begin)/2+begin;
           begin=guess;
   	      
		}
		else if((strcmp(buffer,"low"))==0)
		{
		   guess=begin+end/2;
		   begin=guess;		
		}
		else
		{
			printf("you must want this num %d!\n",guess);
		}
		guess=(end-begin)/2;
   }	
   return 0;
}
int main()
{
	int para=1234;
  //  para=bit_sum(para);
  //  printf("para=%d",para);
   binarry_sort();
}
