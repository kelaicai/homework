#include<iostream>
#include<stdlib.h>
#include<limits.h>
using namespace std;

#include"display.h"

int partition(int arr[],int left,int right)
{
	int pivot=arr[right];
	int tail=left-1;
	for(int i=0;i<right;++i)
	{
		if(pivot<=arr[i])
		{
			swap(arr,++tail,i);
		}
	}
	swap(arr,tail+1,right);
	return tail+1;
}


int findKitem(int arr[],int k,int len)
{
	if(arr==NULL || k<0 || len<0 || k>len)	return INT_MAX ;
	
	int pivot_index=partition(arr,0,len);
	int start=0;
	int end=len-1;
	while(pivot_index!=k-1)
	{
		if(pivot_index>k-1)
		{
			end=pivot_index-1;
			pivot_index=partition(arr,start,end);
		}
		else
		{
			start=pivot_index+1;
			pivot_index=partition(arr,start,end);
		}
	}
	return arr[pivot_index];
}

int main()
{
	int arr[]={12,78,44,57,13,45};
	int len=sizeof(arr)/sizeof(sizeof(arr[0]));
	int ret=findKitem(arr,2,len);
	cout<<"item is"<<ret<<endl;
	return 0;
} 
