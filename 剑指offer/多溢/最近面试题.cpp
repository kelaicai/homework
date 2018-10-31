#include<iostream>
#include<cstring>
using namespace std;

bool countPoint(const char* str)
{
	if(!str) return false;
	int point=0;
	while(*str)
	{
			if(*str=='.')
			{
				point++;
			}
			str++;
	} 
		
	return point==3?true:false;
} 


bool IsIP(const char* str)
{  	bool flag=false;
	if(!str)  return flag;
	
	if(!countPoint(str)) return flag;
	
	int len=strlen(str);
	//串长度不符合 
	if(len<7 || len>12)   return flag;
	int  num=0; 
	while(*str)
	{
		//判断是不是点 
		if(*str=='.')  {  ++str; num=0; continue; }
		
		num=num*10+*str-'0';
		
		if(num>255)
		{
			flag=false;
			break;
		}
		++str;
	}
	return num<=255?true:false;
}
int main()
{
	char *str[] = {"192.168.1.1","1.0.0","1.0.0.0","256.1.2.1","192.1.1.256"};
	for(int i=0;i<sizeof(str)/sizeof(str[0]);i++)
	{
		if(IsIP(str[i]))
		{
			printf("%s 是合法的IP\n",str[i]);
		}
		else
		{
			printf("%s 不是合法的IP\n",str[i]);
		}
	}
	return 0;
} 
