#include<iostream>
using namespace std;

int s,m;
int w[10240],v[10240];

int dp[10240][10240];
int fun()//��̬�滮
{
    int i,j;
    //���
    for(i=0;i<=s;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(j<w[i])//��װ����
            {
                dp[i][j]=dp[i-1][j];
            }
            else//��װ
            {
                if(dp[i-1][j]>dp[i-1][j-w[i]]+v[i])//��װ��ֵ��
                {
                    dp[i][j]=dp[i-1][j];
                }
                else//ǰi-1����Ʒ�����Ž����i����Ʒ�ļ�ֵ֮�͸���
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
