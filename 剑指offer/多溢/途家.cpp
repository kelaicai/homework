#include<iostream>
using namespace std;

int s,m;
int w[10240],v[10240];

int dp[10240][10240];
int fun()//动态规划
{
    int i,j;
    //填表
    for(i=0;i<=s;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(j<w[i])//包装不进
            {
                dp[i][j]=dp[i-1][j];
            }
            else//能装
            {
                if(dp[i-1][j]>dp[i-1][j-w[i]]+v[i])//不装价值大
                {
                    dp[i][j]=dp[i-1][j];
                }
                else//前i-1个物品的最优解与第i个物品的价值之和更大
                {
                    dp[i][j]=dp[i-1][j-w[i]]+v[i];
                }
            }
        }
    }
    return dp[s][m];
}
 
int main()
{
	while(cin>>s>>m)
	{
		for(int i=0;i<s;i++)
		{
			cin>>w[i]>>v[i];	
		}
		int res=fun();
		cout<<res<<endl;	
	}
}
