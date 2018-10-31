#include<iostream>
using namespace std;
int main(){
	int b=10;
	const int* const a=&b; 
	int const* const c=&b;
	cout<<sizeof(a)<<endl;
} 
