#include<iostream>

using namespace std;


int& sum(int &a,int &b)
{
	a=a+b; 
	return a;	
} 

int main()
{
	int a=0;
	int b=3; 
	int c=sum(a,b);
	cout<<c<<endl;
}
