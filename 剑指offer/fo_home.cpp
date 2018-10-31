#include <iostream> 
#include<list>
#include<memory>
#include<map> 
#include<bits/shared_ptr.h>
#include<malloc.h>

using namespace std; 


#if 0
class VAC
{  
public:   
	int f() const{return 3;}  

	int f(){return 5;}

};

 int main()
{   
	VAC v1;   
	const VAC v2;   
	cout<<v1.f()<<v2.f();
	
	
	int a=10;
	float b=static_cast<float>(a);
	cout<<b<<endl; 
	
	list<int> ls;
	
	for(int i=0;i<10;i++)
	{
		ls.push_back(i);
	}
	for(list<int>::iterator it=ls.begin();it!=ls.end();++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	for(list<int>::reverse_iterator it=ls.rbegin();it!=ls.rend();++it)
	{
		cout<<*it<<" "; 
	}
//	ls.erase(ls.begin(),ls.end());
	ls.clear();
	for(list<int>::reverse_iterator it=ls.rbegin();it!=ls.rend();++it)
	{
		cout<<*it<<" "; 
	}
	
	int c=10;
	
	shared_ptr<int*> p=new int;
	p=&a;
	cout<<p->use_count()<<endl; 
	return 0;
}  


#endif
class A
{
	private :
		int a;
	public:
		A():a(0){ cout<<"this is A default"<<endl; }
		A(int _a):a(_a){ cout<<"this is A's int constractor"<<endl; }
		void disp();
};
void A::disp()
{
	cout<<a<<endl;
}

#if 0
#define DOUBLE(x) x+x

int main()
{
	int rt = 5*DOUBLE(10);
	cout<< rt << endl;
	return 0;
}

#endif

#if 0
int main()
{
	map<string,string> mp;
	mp.insert(pair<string,string>("1","2"));
	cout<<mp["1"]<<endl;	
}
#endif

class Test
{
	private:
	int value;
	public:
	Test(int x=0):value(x){}
	
	~Test(){}
	
	void show(){cout<<value<<endl;}
    virtual void fun(){cout<<"fun"<<endl;}
	static void print(){cout<<"Test static"<<endl;}
};
#if 0
template<typename T>
inline void destory(T *pointer)
{
	pointer->~T();
}
template<class T>
inline void destory(_FI _F,_FI _L)
{ 
/*  
	_FI X=++_F;
	while(X!=_L)  
	{
		 X=(++_F);
		--_F; 
		*(_F)->~T();
		_F=X; 
	}
	*/
	for(;_F!=_L;++_F)
	{
		destroy(&*_F);
	}
}
#endif
#if 0
int main()
{	
	Test t1;
	Test *p=(Test*)malloc(sizeof(Test));
	new(p)  Test(10); 
	p->show();
	p->fun();
	p->print();
}
#endif

int main()
{
	shared_ptr<int> * p=new int;
}
