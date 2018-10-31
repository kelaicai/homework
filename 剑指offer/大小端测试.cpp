#include<iostream> 
using namespace std; 
int main()
{
	union et{
		short a;
		char b;
	};
	et t;
		t.a=1;
	if(t.b==1)
	{
		cout<<"Ð¡¶Ë"<<endl; 
	}
	else
	{
		cout<<"´ó¶Ë"<<endl; 
	}
	return 0;
}
