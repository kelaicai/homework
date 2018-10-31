#include<iostream>
using namespace std;

class A
{
	A():buff('0')
	{
		
	}
	private:
		char buff[100];
};
int main()
{
	A a;
	return 0;	
} 
