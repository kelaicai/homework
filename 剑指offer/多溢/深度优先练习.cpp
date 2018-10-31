/*
深度优先联系 
*/


#include<iostream>
using namespace std;

int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
typedef struct point
{
	int x;
	int y;
}point;
int n,m;
char map[1000][1000];
bool vis[1000][1000];
int step;

bool Judge(int x,int y)
{
	if(x>=0 && x<n && y>=0 && y<m)  return true;
	
	return false;
}
void dfs(int x,int y)
{
	for(int i=0;i<4;i++)
	{
		x=x+dir[i][0];
		y=y+dir[i][1];
		if(Judge(x,y)&&map[x][y]=='.'&& vis[x][y]==0)
		{
			step++;
			vis[x][y]=1;
			//map[x][y]='#';
			dfs(x,y);
		}
	} 
}


int main()
{
	point start;
	point end;
	/*
	while(cin>>n>>m)
	{
		end.x=n-1;
		end.y=m-1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>map[i][j];
				if(map[i][j]=='@')
				{
					start.x=i;
					start.y=j;
				}
			}
		}
		step=1;
		vis[start.x][start.y]=1;
		dfs(start.x,start.y);
		cout<<step;
		step=0;
	}
	*/
	for(int i=0;i!=0;i++)
	{
		cout<<"she"<<endl;
	}
	return 0;
	
} 


