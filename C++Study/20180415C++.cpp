#include<iostream>
using namespace std;
class Test{
public:
	Test(int a = 5) :ma(a)
	{
		cout << "Test(int=5)" << endl;
	}
	~Test()
	{
		cout << "~Test()" << endl;
	}
	Test(const Test &src) :ma(src.ma)
	{
		cout << "Test(const Test&)" << endl;
	}
	void operator=(const Test &src)
	{
		ma = src.ma;
		cout << "operator=" << endl;
	}
	int getValue(){ return ma; }
private:
	int ma;
};
class Stack
{
	public:
		Stack(int a=10):a(10)
		{
			cout<< "Stack(int a=10):a(10)"<<endl;
		} 
		~Stack()
		{
			cout<< "	~Stack()"<<endl;
		} 
private:
	int a;		
};

int main()
{
	/*
	Test t1(10);
	Test t2 = GetTestObject(t1);

	//t2 = GetTestObject(t1);
	cout<<t2.getValue()<<endl;
	*/
	Test t1=10;

	return 0;
}
