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
//��Ҫ������������ʹ��/�ţ��Ϳ⺯��������285/16���̺�������Ҫ��Ч�ʾ����� 
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
		Qout--;  //��   
		Remainder=m+n;  //���� 
		cout<<"285/16"<<Qout<<" "<<Remainder<<endl;
	}
	*/ 
	int m=285;
	int n=16;
	Result res;
	compute_result(m,n,res);
	cout<<"285/16"<<" "<<res.Qout<<" "<<res.Remainder<<endl;
} 
