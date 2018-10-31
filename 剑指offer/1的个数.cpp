#include"display.h"
//如果num是负数将会导致死循环 
int count_numbers_one(int num)
{
	int count=0;
	while(num)
	{
		if(num&1)
		{
			count++;
		}
		num=num>>1;
	}
	return count;
}

int count_numbers_one_in(int num)
{
	int unsigned flag=1;
	int count=0;
	while(flag)
	{
		if(num&flag)
		{
			count++;	
		}	
		flag=flag<<1;
	}	
	return count;
} 

int count_numberone(unsigned int num)
{
	int count=0;
	while(num)
	{
		if(num)
		{
			count++;	
		} 
		num=num&(num-1);
	 } 
	return count;
	
}
int main()
{
	cout<<count_numberone(-1)<<endl; 
	return 0;
}
