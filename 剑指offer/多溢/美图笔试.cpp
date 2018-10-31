#include<iostream>
#include<stack> 
using namespace std;
int N;

int path[1024][1024];
int visit[1024][1024];
stack 
int dfs(int x,int y)
{
	if(visit[x][y]==1)
	{
		return ;		
	}
	
	visit[x][y]=1;
	for(i)
	
	
	
}
int main()
{
	int x,y;
	while(cin>>N)
	{
		for(int i=0;i<N-1;i++)
		{
			cin>>x>>y;
			path[x][y]=1;
			path[y][x]=1;
		}
		dfs();
	}
} 
