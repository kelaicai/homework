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
������Ŀ�������е�ǰi��Ԫ���У���������еĳ���ΪlIS[I]
�� LIS[i+1]=max{1,LIS[k]+1} arr[i+1]>arr[k],for and k<=i 


�����arr[i+1]����arr[k],��ô��i+1��Ԫ�ؿ��Խ���LIS[K]���������к��湹��һ�������������� 
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

��̬�滮����
 
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
	//j���ڴ�����ǵ��������еĳ��� 
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
