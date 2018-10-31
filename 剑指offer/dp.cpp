#include<iostream>
#include<string.h>
using namespace std;
//����d[i]��ʾ����i��λ���ϵ����������еĳ��� 

/*
5��3��4��8��6��7
���������ҵ���״̬�����ǿ��Եõ��������ĵ���ǽ������ж���LIS��ʾ��

ǰ1������LIS����d(1)=1(���У�5)
ǰ2������LIS����d(2)=1(���У�3��3ǰ��û�б�3С��)
ǰ3������LIS����d(3)=2(���У�3��4��4ǰ���и�����С��3������d(3)=d(2)+1)
ǰ4������LIS����d(4)=3(���У�3��4��8��8ǰ�����С����3���������� d(4)=max{d(1),d(2),d(3)}+1=3)
OK���������⣬�Ҿ���״̬ת�Ʒ����Ѿ��������ˣ���������Ѿ������d(1)��d(i-1)�� ��ôd(i)�����������״̬ת�Ʒ��̵õ���



���Ƕ���d(i)����ʾǰi��������A[i]��β����ǽ������еĳ���
d(i) = max{1, d(j)+1},����j<i,A[j]<=A[i]
*/

int dp_for_lcs2(int arr[],int len);
int dp_for_lcs(int arr[],int len)
{
	if(arr==NULL || len<0) return -1;
	
	int *dp=new int[len];
	int res_len=0; 
	for(int i=0;i<len;i++)
	{
		dp[i]=0;
		for(int j=0;j<i;j++)
		{
			if(arr[j]<=arr[i] && dp[j]+1>dp[i])
			{
				dp[i]=dp[j]+1;
			}
		}
		if(dp[i]>res_len)
		{
			res_len=dp[i];
		}
	}
	for(int i=0;i<len;i++)
	{
		cout<<dp[i]<<" ";
	}
	cout<<endl;
	delete dp;
	return res_len;
} 


int** get_array(int row,int col)
{
	int **arr=new int*[row];
	for(int i=0;i<row;i++)
	{
		arr[i]=new int[col];
		memset(arr[i],0,col);
		if(arr[i]==NULL) throw "bad_alloc";	
	}
	
	return arr;
	
}

void free_array(int arr[][5],int row,int col)
{
	if(arr==NULL)  return ;
	
	for(int i=0;i<row;i++)
	{
		delete [] arr[i];
	}
	delete arr;
}


void display(int arr[][5],int row,int col)
{
	if(arr==NULL || row <0 || col<0)
	{
		return;
	}
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
int min_distance(int arr[][5],int row,int col)
{
	if(arr==NULL || row<0 || col<0) return -1;
	int** c=get_array(row,col);
	
	for(int i=1;i>row;i++)
	{
		for(int j=1;j<row;j++)
		{
			if(arr[j]<=arr[i])
			{
				c[i][j]=c[i-1][i-1]+1;
			}
			else
			{
				c[i][j]=c[i-1][j]>c[i][j-1]?c[i-1][j]:c[i][j-1];
			}
		}
	}
	display(c,row,col);
	return 0;
	
}
int main()
{
//	int arr[]={5,3,4,8,6,7};
	
//	int res=dp_for_lcs2(arr,sizeof(arr)/sizeof(arr[0]));
//	cout<<res<<endl;
	
	
//	string str1="ancbd";
//	string str2="ancbd";;

	int grap[][]={{0,2,1,0,0},{2,0,1,0,1},{1,1,0,2,0},{0,0,2,0,3}},
	{0,1,0,3,0}};
	int row=sizeof(grap)/sizeof(grap[0])
	int col=sizeof(grap[0])/sizeof(grap[0][0]);
	 
	min_distance(grap,row,col);
	
		
} 



int dp_for_lcs2(int arr[],int len)
{
	if(arr==NULL || len<0) return -1;
	
	int res_len=0;
	int *dp=new int[len];
	
	for(int i=0;i<len;i++)
	{
		dp[i]=0;
		for(int j=0;j<i;j++)
		{
			if(arr[j]<=arr[i] && dp[j]+1>dp[i])
			{
				dp[i]=dp[j]+1;
			}
		}
		if(dp[i]>res_len) res_len=dp[i];
	}
	return res_len; 
	
	
	
} 
 
