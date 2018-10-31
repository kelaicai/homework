#include<iostream>
using namespaces std;

struct pos
{
	int x;
	int y;
	int time; 
};

int main
{
	int dir={{0,1},{0,-1},{-1,0},{1,0}};
	int n,m,time;
	bool ok;
	
	while(cin>>n>>m>>time)
	{
		if(n==0 && m==0 && time==0) retunr 0
		
		ok=false;
		vector<vector<char> > mp(m,vector<char>(n));
		queue<pos>  find;
		pos start,goal;
		
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>mp[i][j];
				if(mp[i][j]=='S')
				{
					start.x=i;
					start.y=j;
					start.time=0;
				}
				if(mp[i][j]=='P')
				{
					goal.x=i;
					goal.y=j;
				}
			}	
			
		}
		
		find.push(start);
		mp[start.x][start.y]='x';
		pos cur;
		
		while(!find.empty())
		{
			cur=find.front();
			find.pop();
			
			if(cur.x==goal.x&& cur.y==goal.y&& cut.time<time)
			{
				cout<<"yes"<<endl;
				ok=true;
				break;
			}
			
			for(int i=0;i<4;i++)
			{
				pos nbr;
				nbr.x=cur.x+dir[i][0];
				nbr.y=cur.y+dir[i][1];
				nbr.time=cur.time+1;
				if(nbr.x>=0 && nbr.x<m && nbr.y>=0 && nbr.y<n && 
				nbr.time<time)
				{
					find.push(nbr);
					mp[nbr.x][nbr.y]='*';
				}
			}
			if(!ok){
				cout<<"no"<endl;
			}
			mp.clear();
		}
	}
	
}
