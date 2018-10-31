#include<iostream>
using namespace std;

class A
{
	private:
		int num;
		char *mptr;
		int c;
	public:
	A():num(0),mptr(NULL),c(0)
	{
		cout<<"	A()"<<endl;
	}
	A(int mnum=10):num(mnum),mptr(NULL),c(mnum)
	{
		cout<<"	A(int num=10)"<<endl;
	}
	~A()
	{
		num=0;
		mptr=NULL;
		c=0;
		cout<<"~A()"<<endl;
	}
	A(const A &a)
	{
		cout<<"const A &a"<<endl;
	}
	int add()
	{
		return 10+11; 
	}
};

class B
{
	
};
int main()
{
	A a=10;
	void (A::int (*p))=&A::add();
}
