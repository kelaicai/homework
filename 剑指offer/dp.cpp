#include<iostream>
#include<string.h>
using namespace std;
//定义d[i]表示到第i个位置上的最大递增序列的长度 

/*
5，3，4，8，6，7
根据上面找到的状态，我们可以得到：（下文的最长非降子序列都用LIS表示）

前1个数的LIS长度d(1)=1(序列：5)
前2个数的LIS长度d(2)=1(序列：3；3前面没有比3小的)
前3个数的LIS长度d(3)=2(序列：3，4；4前面有个比它小的3，所以d(3)=d(2)+1)
前4个数的LIS长度d(4)=3(序列：3，4，8；8前面比它小的有3个数，所以 d(4)=max{d(1),d(2),d(3)}+1=3)
OK，分析到这，我觉得状态转移方程已经很明显了，如果我们已经求出了d(1)到d(i-1)， 那么d(i)可以用下面的状态转移方程得到：



我们定义d(i)，表示前i个数中以A[i]结尾的最长非降子序列的长度
d(i) = max{1, d(j)+1},其中j<i,A[j]<=A[i]
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
 
