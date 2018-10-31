#include<iostream>
using namespace std;

/*
第一种 暴力旋转 
*/ 

void RightShift(int arr[],int len,int k) 
{
	while(k--)
	{
		int t=arr[len-1];
		for(int i=len-1;i>0;i--)
		{
			arr[i]=arr[i-1];
		}
		arr[0]=t;
	}
}
void display(int arr[],int len)
{
	for(int i=0;i<len;i++)
	{
		cout<<arr[i]<<" ";
	}
}
int main()
{
	int arr[]={12,34,56,1,2,3,4,5};
	RightShift(arr,sizeof(arr)/sizeof(arr[0]),8);
	int len=sizeof(arr)/sizeof(arr[0]);
	display(arr,len);
} 
