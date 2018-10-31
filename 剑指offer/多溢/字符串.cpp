#include<iostream>
#include<string>
#include<cctype> 
using namespace std;

string fun(string  str)
{
	int len=str.size();
	for(int i=0;i<len;i++)
	{
		if(isdigit(str[i]))
		{
			char s=str[i];
			for(int j=i;str[i]!='\0' && j<len;j++)
			{
				str[j]=str[j+1];
			}
			str[len-1]=s;
		}
	}
	return  str;
}

string str; 
int main()
{
	while(cin>>str)
	{
		string s=fun(str);
		cout<<s<<endl; 
	}	
} 
