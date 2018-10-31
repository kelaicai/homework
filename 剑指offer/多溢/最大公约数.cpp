#include<iostream>
#include<stack>
using namespace std;

/*
102680513
*/
int gdc(int a,int b)
{
	cout<<a<<" "<<b<<endl; 
	return (!b)?a:gdc(b,a%b); 
}

int gdc2(int a,int b)
{
	   
	if(a<b)
	return gdc2(b,a);
	
	if(b==0)  return a; 
	else
	return gdc2(a-b,b); 
}
int main()
{
	static stack<int> st;
	st.push(1);

//	st.pop();
	/*
	int a=42;
	int b=30;
	int gdb=gdc2(a,b);	
	cout<<gdb<<endl;
	*/
} 
