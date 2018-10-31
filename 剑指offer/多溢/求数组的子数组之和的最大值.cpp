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
	��������������ĺ͵���Сֵ��Ϊ�������
	��1�� 0==i��ʱ��Ԫ��a[0]�����ɺ͵����һ��
	��2��0==i<j��ʱ��,������һ����A[0]��ʼ
	��3��0<i��ʱ��Ԫ��A��0��������һ��û�й�ϵ
	
	A��1��~A[n-1]֮�������ΪALL��1����3�� ����A��1������� 
	����A��1��~A��n-1������A��1���ĺ�����һ������Ϊstart[i]��2��
	max(A[0],A[0]+start[1],all[1])----->���Ž�All[0] 
	 
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
