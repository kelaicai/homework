#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string addTowBinary(string &num1,string &num2)
{
	string res;
	int len_1=num1.size();
	int len_2=num2.size();
	
	if(!len_1) return num2;
	if(!len_2) return num1;
	
	int max_len=max(len_1,len_2);
	
	int add='0';
	
	for(int i=0;i<max_len;i++)
	{
		char ca=len_1>i?num1[len_1-i-1]:'0';
		char cb=len_2>i?num2[len_2-i-1]:'0';
		char s=(ca==cb?'0':'1');
		char sj=(s==add)?'0':'1';
		if(ca=='1'&& cb=='1' || s=='1' && add=='1')
		{
			add='1';
		}else
		{
			add='0'; 
		}
		res+=sj;
	}
	if(add=='1')
	{
		res+=add;
	}
	reverse(res.begin(),res.end());
	return res;
}
int main()
{
	string num1,num2;
	string result;
	while(cin>>num1>>num2)
	{
		result=addTowBinary(num1,num2);
		cout<<result<<endl;	
	}
} 
