#include<iostream>
#include<cstring>
using namespace std;

int N,M; 
int mp[10240][10240];
int dp[10240][10240];
int minP1()
{
	int row=N;
	int col=M;
	
	//int dp[row--][col--]={0};
	row--;
	col--;
	dp[row][col]=mp[row][col]>0?1:-mp[row][col]+1;
	
	for(int j=col-1;j>=0;j--)
	{
		dp[row][j]=max(1,dp[row][j+1]-mp[row][j]);		
    } 
    
    int right=0;
    int down=0;
    for(int i=row-1;i>=0;i--)
    {
    	dp[i][col]=max(dp[i+1][col]-mp[i][col],1);
    	for(int j=col-1;j>=0;j--)
    	{
    		right=max(dp[i][j+1]-mp[i][j],1);
    		down=max(dp[i+1][j]-mp[i][j],1);
    		dp[i][j]=max(right,down);
		}
	}
	return dp[0][0];
}
int main()
{
	while(cin>>N>>M)
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<M;j++)
			{
				cin>>mp[i][j];
			}
		}
		int res=minP1();
		cout<<res<<endl;
		memset(mp,0,10240);
		memset(dp,0,10240);
	}
}
