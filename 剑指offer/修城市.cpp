
#include<iostream>
#include<utility>
#include<vector>
using namespace std;

int arr[100][100];
/*
vector<pair<int,int>> vpair;

int main()
{
	pair<int,int> pa;
	while(cin>>N)
	{
		for(int i=0;i<=N/2;i++)
		{
				cin>>pa->first>>pa->second;
				vpair.push_back(pa);
		}
		int i=0;
		int j=0;
		int size=vpair.size();
		for(int;;)
		{
			
		}

	} 
	*/

int n,m;
const int N=2000;
int a[N];
int Q;
pair<int,int>  ipair;
vector<pair<int,int> > pvec;
int result[1024];

int count(int a[],int l,int right)
{
	int sum=0;
	for(;l!=right;l++)
	{
		sum+=a[l];
	}
	return sum;
} 
int main()
{
	while(cin>>n>>m)
	{
		for(int i=0;i<n;i++) cin>>a[i];
		
		cin>>Q;
		for(int i=0;i<Q;i++)
		{
			int tep1,tep2;
			cin>>tep1>>tep2;
			pvec.push_back(make_pair(tep1,tep2));
		}
		int j=0;
		for(vector<pair<int,int>>::iterator i=pvec.begin();
		i!=pvec.end();++i)
		{
			result[j++]=count(a,i->first,i->second);	
		} 
		for(int i=0;i<j;i++)
		{
			cout<<result[i]<<endl;		
		}		
	}
	
}
	
	
	
	
	
	
	
	
	
	
	
