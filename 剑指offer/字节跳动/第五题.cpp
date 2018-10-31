#include<iostream>
#include<cstring>
#include<vector>
#include<map>
using namespace std;


#if 0 
int s[1024];
int f[1024];
bool b[1024];

bool GreedySelector(int n,int s[],int f[],bool b[])
{
	b[1]=true;
	int j=1;
	for(int i=2;i<n;i++)
	{
		if(s[i]>=f[j])
		{
			b[j]=true;
			j=i;
		}	else b[j]=false;
	}

} 

void show(int arr[],int len)
{
	if(arr==NULL) return ;
	
	for(int i=0;i<len;i++)
	{
		cout<<arr[i]<<endl; 
	}
	cout<<endl;	
} 
int main()
{
	
	int i=1,j=1;
	int n=0;
	int m=0;
	
	//注意输入的写法 
	while((scanf("%d",&m))!=EOF)
	{
		int t=m;
		while(t--)
		{
			scanf("%d%d",s+i,f+j);
			i++;
			j++;
		}
		int count=0;
		GreedySelector(m-1,s,f,b);
		for(int i=0;i<m;i++)
		{
			if(b[i]) count++;
		}
		cout<<count<<endl;
		//将原数组更新 
		memset(s,0,m);
		memset(f,0,m);
		memset(b,0,m);
		//将i，j更新 
		i=0;
		j=0;
		count=0;
	} 
} 
#endif

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;
class PointInfo
{
public:
    int x,y;
};
int n,m;
int f[1001][1001];
int dx[8]={-1, 0, 1,-1,1,-1,0,1};
int dy[8]={-1,-1,-1, 0,0, 1,1,1};
int bfs(int x,int y)
{
    queue<PointInfo> q;
    while (!q.empty()) q.pop();
    PointInfo now;
    now.x=x;
    now.y=y;
    q.push(now);
    f[x][y]=0;
    int cnt=1;
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        for (int i=0;i<8;i++)
        {
            x = now.x+dx[i];
            y = now.y+dy[i];
            if (x<0 || y<0 || x>=n || y>=m) continue;
            if (f[x][y]==0) continue;
            f[x][y]=0;
            PointInfo tmp;
            tmp.x = x;
            tmp.y = y;
            q.push(tmp);
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    scanf("%d,%d",&n,&m);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&f[i][0]);
        for (int j=1;j<m;j++)
            scanf(",%d",&f[i][j]);
    }
    int maxnum = 0;
    int cnt=0;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            if (f[i][j]==1)
        {
            int x = bfs(i,j);
            cnt++;
            if (x>maxnum) maxnum=x;
        }
    printf("%d,%d\n",cnt,maxnum);
    return 0;
}



