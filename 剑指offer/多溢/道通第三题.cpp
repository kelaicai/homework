#include<iostream>
#include<string>
#include<cstring> 
using namespace std;
typedef enum  RPEncodeType
{
    MAN=0x4A,
    ReMAN=0x32,
    DiffMAN=0x4E
}RPEncodeType;

string manchester(string num)
{
	int len=num.size();
	string res;
    for(int i=0;i<len;i++)
    {
    	if(i+1<len && num[i]=='1')
    	{
    		res+="10";
		}
		else
		{
			res+="01";
		}
	}
    return res;
}

string unmanchester(string num)
{
     int len=num.size();
	string res;
    for(int i=0;i<len;i++)
    {
    	if(i+1<len && num[i]=='0' && num[i+1]=='1')
    	{
    		res+="01";
		}
		else
		{
			res+="10";
		}
	}
    return res;
}

string diffmanchester(string num)
{
     string res;
     string mcs=manchester(num);
     int len=mcs.size();
     
     for(auto i=1;i<len;i++)
     {
     	if(mcs[i]==mcs[i-1])
     	{
     		res+="0"; 
		}
		else
		{
			res+="1";
		} 
	 }
    return res;
}
string HexToBinary(string num)
{    
	string res;
	for(int i=0;i<num.size();i++)
	{
		if(num[i]=='0')
		{
			res+="0";
		}
		if(num[i]=='1')
		{
			res+="1"; 
		}
		if(num[i]=='2')
		{
			res+="10";
		}
			if(num[i]=='3')
		{
			res+="11";
		}
		if(num[i]=='4')
		{
			res+="100"; 
		}
		if(num[i]=='5')
		{
			res+="101";
		}
		if(num[i]=='6')
		{
			res+="110";
		}
		if(num[i]=='7')
		{
			res+="111"; 
		}
		if(num[i]=='8')
		{
			res+="1000";
		}
		if(num[i]=='9')
		{
			res+="1001";
		}
		if(num[i]=='A')
		{
			res+="1010";
		}
		if(num[i]=='B')
		{
			res+="1011"; 
		}
		if(num[i]=='C')
		{
			res+="1100";
		}
		if(num[i]=='D')
		{
			res+="1101"; 
		}
		if(num[i]=='E')
		{
			res+="1110";
		}
		if(num[i]=='F')
		{
			res+="1111"; 
		}
	}
	return res;
}
int main()
{
    string choice;
    string num;
    string res;
    while(cin>>choice>>num)
    {
    	cout<<choice<<" "<<num<<endl;
    	string my=HexToBinary(num);
        if(choice=="4A")
        {
            res=manchester(num);
        }
        else if(choice=="32")
        {
            res=unmanchester(num);
        }
        else 
        {
            res=diffmanchester(num);
        }
        cout<<res<<endl;
    }
    
}
