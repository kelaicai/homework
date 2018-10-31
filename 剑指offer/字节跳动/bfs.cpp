#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

#if 0
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
#endif
#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

bool cmp(pair<int,int> p1,pair<int,int> p2)
{
	return (p1.second<p2.second || p1.second==p2.second && p1.first>p1.first);
}


int main()
{
	int N,M;
	cin>>N>>M;
	vector<pair<int,int>> time(N);
	
	for(int i=0;i<N;++i)
	{
		int s,t;
		cin>>s>>t;
		if(s>=t) t+=M;
		time[i]=make_pair(s,t);
	}
	sort(time.begin(),time.end()),cmp);
	int finalRes=0;
	for(int j=0;j<N;++j)
	{
		int res=0;
		int cur0=time.first;
		int cur=cur0;
		for(int i=0;i<N;++i)
		{
			if(i+j<N&&time[j].first>=cur)
			{
				cur=time[i].second;
				if(cur<cur0+M)
				{
					++res;
				}else break;
			}
		
		}
	}
	if(res>finalRes)
	{
		finalRes=res;			
	}
	cout<<finalRes<<endl;
	return 0;
	
}
