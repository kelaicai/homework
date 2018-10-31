#include<iostream>
using namespace std; 

class MyClass
{
    int var;
public:
    virtual void fun()
    {}
};
class MyClassA:public MyClass
{
    int varA;
public:
	//函数没有大小 
    virtual void fun()
    {}
    virtual void funA()
    {}
    virtual void funB()
    {
	}
};

int main()
{
	cout<<sizeof(long)<<endl;
	cout<<sizeof(MyClass)<<endl; 
	cout<<sizeof(MyClassA)<<endl;
}
