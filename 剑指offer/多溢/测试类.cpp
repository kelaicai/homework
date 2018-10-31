#include<iostream>
using namespace std;

class A{
	public:
static int a;

};

int A::a=0; 
int main()
{
	cout<<sizeof(A)<<endl;
	return 0;
} 
