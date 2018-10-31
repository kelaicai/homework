#include<iostream>
#include<limits.h> 
using namespace std;

int sumMax(int arr[],int len)
{
	if(arr==NULL)  return 0;
	
	int min=INT_MIN; 
	int sum=0;
	for(int i=0;i<len;i++)
	{	sum=0;
		for(int j=i;j<len;j++)	
		{
			sum+=arr[j];
			if(sum>min)
			{
				min=sum;
			}
		}
	}	
	return min;
} 


/**
	计算连续子数组的和的最小值分为三种情况
	（1） 0==i的时候，元素a[0]本身构成和的最大一段
	（2）0==i<j的时候,和最大的一段以A[0]开始
	（3）0<i的时候，元素A【0】与最大的一段没有关系
	
	A【1】~A[n-1]之间的最大和为ALL【1】（3） 不含A【1】的情况 
	并且A【1】~A【n-1】包含A【1】的和最大的一段数组为start[i]（2）
	max(A[0],A[0]+start[1],all[1])----->最优解All[0] 
	 
*/
int All[100];
int start[100];

int MaxSum(int arr[],int len)
{
	start[len-1]=arr[len-1];
	All[len-1]=arr[len-1];
	
	for(int i=len-2;i>=0;i--)
	{
		start[i]=max(arr[i],arr[i]+start[i+1]);
		All[i]=max(All[i+1],start[i]);
	}
}

int main()
{
	int arr[]={1,-2,3,5,-3,2};
	int len=sizeof(arr)/sizeof(arr[0]);
	int val=sumMax(arr,len);
	cout<<val<<endl;
}
