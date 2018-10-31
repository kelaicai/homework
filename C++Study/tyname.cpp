#include<iostream>
#include<typeinfo>
using namespace std;

int main()
{
	cout<<typeid("aaaa").name()<<endl;
}
