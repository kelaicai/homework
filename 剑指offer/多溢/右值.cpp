#include<iostream>
#include<Bitmap> 
using namespace std; 
/*
class A
{
	public:
		int * a;
		A():a(new int()){ fun(); cout<<" in A()"<<endl; cout<<*a<<endl;}
	virtual	~A(){
			cout<<"~A()"<<endl;
			delete a;
		}
		virtual void fun()
		{
			cout<<"i am fun a"<<" a="<<*a<<endl; 
		}
};

class B:public A
{
	public:
		int *b;
	B():b(new int()){ fun() ;cout<<"B()"<<endl;}
	~B(){  cout<<"in ~B()"<<endl; fun(); cout<<"~B()"<<endl; delete b;} 
	void fun()
	{
		cout<<"funb"<<endl; 
	}
	
};

int main()
{
	void (*f)();
	A* b=new B();
	cout<<"f����"<<endl;

	
	delete b;
	return 0;
}
*/

/*
class Base
{
	public:
		Base( ){ Function();}
		virtual void Function()
		{
			cout<<"Base"<<endl;
		}
};
class A:public Base 
{
	public:
	A()
	{
		Function();
	}
	virtual void Function()
	{
		cout<<"A:Function"<<endl;
	} 
};	

int main()
{
	A a;
}
*/
class A
{
	public:
	A()
	{
		cout<<"A�Ĺ��캯��"<<endl;
		Test();	
	}	
	~A()
	{
		cout<<"A����������"<<endl;
		cout<<"A::Test"<<endl;
	}
	virtual void Test()
	{
		cout<<"A::Test"<<endl; 
	}
};

class B:public A
{
	public:
	B()
	{
		cout<<"B���캯��"<<endl;	
	}	
	~B()
	{
		cout<<"B����"<<endl;
		Test();
	}
	virtual void Test()
	{
		cout<<"B::Test"<<endl;
	}
};

int main()
{
	A* pa=new B();
	cout<<"��̬����"<<endl;
	
	pa->Test();  //
	delete pa;
	return 0; 
} 
















