#include<iostream>

using namespace std;

int path[10240][10240];
int m,n;
int result;

int x[1024];
int y[1024];
int fun()
{
	for(int i=1;i<=n;i++)
	{
		//一个城市可以到达的其他城市 
		for(int j=1;j<=n;j++)
		{
			if(path[i][j])
			{
				x[i]++;	
			}
			if(path[j][i])
			{
				y[i]++;
			} 
		}
		if(y[i]>x[i])
		{
			result++; 
		}		
	}
	return result;
}
int main()
{
	while(cin>>m>>n)
	{
		for(int i=1;i<=n;i++)
		{
			int x,y;
			cin>>x,y;
			path[x][y]=1;
				
		}	
		int res=fun();
		cout<<res<<endl;
	}
	return 0;		
} 
