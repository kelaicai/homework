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

//����ʱ��̵���ǰ�棬����ʱ����ͬʱ����ʼʱ�������ǰ��
bool cmp(pair<int,int>& p1,pair<int,int> &p2)
{
	return (p1.second<p2.second) || (p1.second==p2.second && p1.first>p2.first); 
} 


int main()
{
	int N,M; //N��������M��ʱ���

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
		//��ǰ��Ŀ�Ŀ�ʼʱ�� 
		int start_time=time[j].first;
		//��ǰʱ�� 
		int cur_time=start_time;
		for(int i=0;i<N;i++)
		{
			//�����i��ֱ���Ŀ�ʼʱ����ڵ�ǰʱ��
			//˵����i��ֱ�����ڵ�ǰֱ������ 
			cout<<"j="<<j<<"i="<<i<<"start_time "<<start_time<<" cur_time"<<cur_time<<endl; 
			if(i+j<N && time[i].first>=cur_time)
			{
				cout<<"first if"<<endl; 
				//����i��ֱ���Ľ���ʱ����Ϊ��ǰʱ�� 
				cur_time=time[i].second;
				//�����ǰʱ��С�ڵ�ǰֱ����ʱ������������ 
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
