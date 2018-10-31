#include<iostream>
using namespace std;


char map[1024][1024];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int n,m,time;
struct point{
	int x;
	int y;
	int time;
};

int main()
{
	while(cin>>n>>m)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)	
			{
				cin>>map[i][j];
			}
		}
		dfs()	
	}	
} 
