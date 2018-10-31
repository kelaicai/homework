#include<iostream>
#include<assert.h>
using namespace std;
typedef struct Result
{
	int Qout;
	int Remainder;
} Result;

bool compute_result(const int original,const int devied,Result& res)
{
	assert(devied!=0);
	int m=original;
	int n=devied;
	res.Qout=0;
	while(m>0)
	{
		m=m-n;
		res.Qout++;
	}
	if(m<0)
	{
		res.Qout--;
		res.Remainder=m+n;
	}
}
//不要除法（即不能使用/号）和库函数，计算285/16的商和余数，要求效率尽量高 
int main()
{
/*
	int m=285;
	int n=16;
	int Remainder=0;
	int Qout=0;
	while(m>0)
	{
		m=m-n;
		Qout++;  
	}
	if(m<0)
	{
		Qout--;  //商   
		Remainder=m+n;  //余数 
		cout<<"285/16"<<Qout<<" "<<Remainder<<endl;
	}
	*/ 
	int m=285;
	int n=16;
	Result res;
	compute_result(m,n,res);
	cout<<"285/16"<<" "<<res.Qout<<" "<<res.Remainder<<endl;
} 
