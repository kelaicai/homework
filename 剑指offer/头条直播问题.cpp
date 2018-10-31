#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;

void show(vector<pair<int,int> >& a)
{
	for(int i=0;i<a.size();i++)
	{
		cout<<a[i].first<<" "<<a[i].second<<endl;
	}
}

//结束时间短的在前面，结束时间相同时，开始时间晚的在前面
bool cmp(pair<int,int>& p1,pair<int,int> &p2)
{
	return (p1.second<p2.second) || (p1.second==p2.second && p1.first>p2.first); 
} 


int main()
{
	int N,M; //N个主播，M个时间段

	while(cin>>N>>M)
	{
	
	vector<pair<int,int> > time(N); 
	for(int i=0;i<N;i++) 
	{
		int s,t;
		cin>>s>>t;
		if(s>=t) t+=M;
		
		time[i]=make_pair(s,t);
	}
	int finalRes=0;
	sort(time.begin(),time.end(),cmp);
	for(int j=0;j<N;j++)
	{
		int res=0;
		//当前节目的开始时间 
		int start_time=time[j].first;
		//当前时间 
		int cur_time=start_time;
		for(int i=0;i<N;i++)
		{
			//如果第i个直播的开始时间大于当前时间
			//说明第i个直播是在当前直播后面 
			cout<<"j="<<j<<"i="<<i<<"start_time "<<start_time<<" cur_time"<<cur_time<<endl; 
			if(i+j<N && time[i].first>=cur_time)
			{
				cout<<"first if"<<endl; 
				//将第i个直播的结束时间作为当前时间 
				cur_time=time[i].second;
				//如果当前时间小于当前直播的时间所在区间内 
					if(cur_time<start_time+M)
					{
						cout<<"res++"<<endl ;
						++res;
					}else break ;
			} 
			
			if(i+j>=N && time[i].first+M>=cur_time)
			{
				cout<<"second if"<<endl;
				if(cur_time<start_time+M)
				{
					++res; 
				}
				else break;
			}	
		}
		if(res>finalRes)
		finalRes=res;
	}
	cout<<finalRes<<endl;
	}
}
