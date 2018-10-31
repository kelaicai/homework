#include<iostream>
#include<string>
#include<map>
#include<unordered_map>
#include<vector>
#include<list>
#include<deque>
#include<stack>
#include<iterator>
#include<algorithm>
#include<functional>
#include<memory> 
using namespace std;

class A
{
	private:
	int a;
	int *c;
	int e;
	public:
	A(int d=0):c(new int)
	{
		cout<<"A"<<endl;
	}
	virtual ~A()
	{
		delete c;
		cout<<"~A virtual"<<endl;	
	}	
	 void fun(int a=0)
	{
		cout<<"fun"<<a<<endl;
	}
};

class B:public A
{
	public:
	B()
	{
		cout<<"B()"<<endl;	
	}	
	~B()
	{
		cout<<"~B()"<<endl;
	}
	virtual void fun(int b=1)
	{
		cout<<"b"<<b<<endl; 
	}
};


class Oberser
{
	public:
	virtual void update(string state) =0;	
};

class ProgramMonkeyOberser:class Oberser
{
	public:
	void update()
	{
		cout<<"ProgramMonkeyOberser"<<endl;	
	}	
};

class Subject
{
	public:
	list<Oberser*> li=new 	
};
int main()
{/*
	cout<<sizeof(vector<int>)<<endl; 
	vector<int>::iterator it;
	cout<<sizeof(int*)<<endl; 
	cout<<sizeof(it)<<endl;
	*/
	/*
	map<int,int> mp;
	mp.insert(make_pair(1,2));
	mp.insert(make_pair(2,3));
	mp.insert(make_pair(3,4));
	map<int,int>::iterator it=mp.find(1);
	cout<<it->second<<endl;
	
	list<int> ilt;
	ilt.insert(1);
	ilt.insert(2);
	ilt.insert(3);
	list<int>::iterator 
	*/
	
	/*
	vector<int>  vec;
	for(int i=0;i<10;i++)
	{
		vec.push_back(i); 
	}
	
	for(vector<int>::iterator it=vec.begin();it!=vec.end();++it)
	{
		if((*it)%2==0)
		{
			it=vec.erase(it);
		}
	 } 
	 	for(vector<int>::iterator it=vec.begin();it!=vec.end();++it)
		{
				cout<<*it<<endl;
		 }
	 /*
	 for(auto i:vec)
	 {
	 	cout<<i<<endl;
	 }
	 */
	/* 
	 A* s=new A[10];
	 delete s;
	 */
	 /*
	 vector<int>  vec;
	 for(int i=0;i<10;i++)
	 {
	 	vec.push_back(i);
	 	vec.push_back(i);
	 }
//	 unique(vec.begin(),vec.end());
	bool t=binary_search(vec.begin(),vec.end(),6); 
	 cout<<"t="<<t<<endl;
	 for(auto i:vec)
	 {
	 	
	 	cout<<i<<" ";
	 }
	 */
	 
	 weak_ptr<int>
	 a->fun();
	 
} 
