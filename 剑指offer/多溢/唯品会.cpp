#include<iostream>

using namespace std;
int arr[10240][10240];
int k;
int n;
/*求二维数组第k小*/
bool guessWhat(int g)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		int left=0;
		int right=n-1;
		int ans=0;
		while(left<=right)
		{
			int mid=(left+right)/2;
			if(arr[i][mid]<g)
			{
				ans=mid+1;
				left=mid+1;
			}
			else
			{
				right=mid-1;
			}
			
		}
		sum+=ans;
	}	
	return k>sum;
}

int kInArray()
{
	int nn=n*n;
	int left=arr[0][0];
	int right=arr[n-1][n-1];
	int ans=0;
	while(left<=right)
	{
		int mid=(left+right)/2;
		if(guessWhat(mid))
		{
			ans=mid;
			left=mid+1;
		}else
		{
			right=mid-1;
		}
	}
	return ans;
}
int main()
{
	int res=0;
	while(cin>>k>>n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>arr[i][j];
			}
		}
		res=kInArray();
		cout<<res<<endl;
	 } 
} 
