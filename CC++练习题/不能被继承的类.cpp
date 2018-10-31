#include<iostream>
using namespace std;

template<typename T> class A
{
	friend T;
	private:
		A();
		~A();
};


class B:virtual public A <B>
{
	public :
		B();
		~B();
};

class C:virtual public B
{
	public:
		C();
		~C();
};


int main()
{
	B b;
	return 0; 
	
}


