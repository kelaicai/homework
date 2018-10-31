#include<iostream>
#include<vector>

using namespace std;
int main()
{
	vector<int> vec;
	vec.push_back(500);
	vec.push_back(300);
	vec.push_back(300);
	vec.push_back(200);
	
	vector<int>::iterator it=vec.begin();
	for(;it!=vec.end();++it)
	{
		if(*it==300)
		{
			it=vec.erase(it);
		}
	}	
	for(auto i:vec)
	{
		cout<<i<<endl;
	}
} 
