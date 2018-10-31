#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<memory>
using namespace std;
int N;
int L[10240];
int R[10240]; 
int V[10240];
int main()
{
	vector<string> vec;
	while(cin>>N)
	{
		for(int i=0;i<N;i++)
		{
			cin>>V[i];
			cin>>L[i]>>R[i];
			if(V[i]<L[i]+R[i])
			{
				vec.push_back("NO");
			}
			else
			{
				vec.push_back("YES");
			}
		}
		for(int i=0;i<N;i++)
		{
			cout<<vec[i]<<endl;
		}
		vec.clear();
		memset(L,0,N);
		memset(R,0,N);
		memset(V,0,N);
		N=0;
	}
}

shared_ptr<int> ptr;
