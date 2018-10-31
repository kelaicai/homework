#include<iostream>
#include<typeinfo>
using namespace std; 

int main()
{
  	const int a=10;
  //	int *p=&a;     //	[Error] invalid conversion from 'const int*' to 'int*' [-fpermissive]
   	cout<<typeid(a).name()<<endl;
  //	cout<<typeid(p).name<<endl;
} 
