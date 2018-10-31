#include<iostream>
#include<cstring> 
using namespace std;

char str[100];
int main()
{
	
	while(cin>>str) 
	{
		int len=strlen(str);
		int bian=(len+2)/3; 
		int di=len-bian*2;
	
		for(int i=0;i<bian;i++)
		{
			cout<<str[i]<<" "<<str[len-i]<<endl;
		}
		for(int i=0;i<di;i++)
		{
			cout<<str[i+bian]<<" "; 
	    }
	}
}
