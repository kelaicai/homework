#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;

const int LEN=10;
 
//��������d[i][j]��ʾ������arr���㵽i��������ֵ 
int Max(int arr[],int l,int r,int len)
{
	
	int temp=arr[l];
	for(;r<len && l<r;l++)
	{
		if(temp<arr[l]) temp=arr[l];
	}
	
}

int Min(int arr[],int l,int r,int len)
{
	int min=arr[l];
	for(;r<len && l<r;l++)
	{
		if(min>arr[l]) min=arr[l];
	}
	return min;
}


int find(int arr[],int l,int r,int len)
{
	
} 
int main()
{
	int arr[10]={1,2,3,4,5,6,7,8,9};
	int len=sizeof(arr)/sizeof(arr[0]); 
	int m=max(arr,arr+len,greater<int>());
		
} 
