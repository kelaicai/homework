#include<iostream>
#include<exception>
#include<algorithm>
#include<vector>
#include<map>
#include<iterator>
#include<stdlib.h>
#include<ctime>
using namespace std;

template<typename T>
void display(T a[],T len)
{
	for(int i=0;i<len;++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void swap(int data[],int i,int j)
{
	
	int tmp=data[i];
	data[i]=data[j];
	data[j]=tmp;
	
}


void swap(char str[],int i,int j)
{
	char tmp=str[i];
	str[i]=str[j];
	str[j]=tmp;
}
/*
void swap(int &a,int &b)
{
	a=a+b;
	b=a-b;
	a=a-b;
}
*/
void shell_sort(int data[],int left,int right)
{
	int len=right-left+1;
	int inc=len;
	while(inc>1)
	{
		inc=(inc+1)/2;  //每次缩小增量 
		for(int i=left;i<right+1-inc;i++)
		{
			if(data[i+inc]<data[i])
			{
				swap(data[i+inc],data[i]);
			}
		}
	}
}
void init_data(int data[],int  len)
{
	srand((unsigned int)time(0));
	for(int i=0;i<len;++i)
	{
		data[i]=rand()%100;
	}
}
