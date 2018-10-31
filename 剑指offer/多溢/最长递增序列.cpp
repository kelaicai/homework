#include<iostream>
#include<limit.h> 
using namespace std;
int max(int arr[],int len)
{
	int m=INT_MIN;
	for(int i=0;i<len;i++)
	{
		if(arr[i]>m)
		m=arr[i];
	}
	return m;
}
int min(int arr[],int len)
{
		int m=INT_MAX;
		for(int i=0;i<len;i++)
		{
			if(m>arr[i])
			m=arr[i];
		}
		return m;
} 
/*
假设在目标数组中的前i个元素中，最长增长序列的长度为lIS[I]
则 LIS[i+1]=max{1,LIS[k]+1} arr[i+1]>arr[k],for and k<=i 


即如果arr[i+1]大于arr[k],那么第i+1个元素可以接在LIS[K]长的子序列后面构成一个更长的子序列 
**/
int ordinayLIS(int arr[],int len)
{
	int *LIS=new int[len]();
	for(int i=0;i<len;i++)
	{
		LIS[i]=1;
		for(int j=0;j<i;j++)
		{
			if(arr[i]>arr[j] && LIS[j]+1>LIS[i])
			{
				LIS[i]=LIS[j]+1;
			}
		}
	}

	cout<<endl; 
	int Max=max(LIS,len);
	delete [] LIS;
	return Max;
} 

/**

动态规划做法
 
*/

int dp(int arr[],int len)
{
	int* maxV=new int[len]();
	maxV[1]=arr[0];
	maxV[0]=min(arr,len)-1;
	
	int*  LIS=new int[len]();
	
	for(int i=0;i<len;i++)
	{
		LIS[i]=1;
	}
	//j现在代表的是递增子序列的长度 
	int nMaxLIS=1;
	for(int i=0;i<len;i++)
	{
		int j;
		for(j=nMaxLIS;j>=0;--j)
		{
			if(arr[i]>maxV[j])
			{
				
				LIS[i]=j+1;
				break;
			}
		}
		
		if(LIS[i]>nMaxLIS)
		{
			cout<<"x"<<endl;
			nMaxLIS=LIS[i];
			maxV[LIS[i]]=arr[i];
		 } 
		 else if(maxV[j]<arr[i] &&  arr[i]<maxV[j+1]) 
		 {
		 	cout<<"h"<<endl;
		 	maxV[j+1]=arr[i];
		 }		  
		}

	cout<<endl; 
	return nMaxLIS;
} 
int  main()
{
	int arr[]={1,-1,2,-3,4,-5,6,-7};
	int max=dp(arr,sizeof(arr)/sizeof(arr[0]));
	cout<<max<<endl;
	 
}
