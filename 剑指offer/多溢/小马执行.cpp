#include<iostream>
#include<string>

char plain[15][15];

int vis[15][15];

bool Judge(int x,int y)
{
	if(x>=0 && x<n && y>=0 && y<m)  return true;
	
	return false;
}

int dfs(int x,int y)
{
	int res=0;
	for(int i=0;i<4;i++)
	{
		x=x+dir[i][0];
		y=y+dir[i][1];
		if(Judge(x,y)&&map[x][y]=='.'&& vis[x][y]==0)
		{
			step++;
			vis[x][y]=1;
			//map[x][y]='#';
			res=dfs(x,y);
		}
	} 
	if(res==5)
	{
		return 1;
	}
}
int main()
{
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<15;j++)
			cin>>palin[i][j];
		
		int res=dfs(0,0);
		
	}	
} 
