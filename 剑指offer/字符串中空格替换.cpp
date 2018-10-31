#include<iostream>
using namespace std;

//lenghth为数组的总容量 
void ReplaceBlank(char str[],int length)
{
	if(str==NULL || length <=0)
	{
		return ;
	}
	int originalLength=0;  //字符串的实际长度 
	int numberOfBlank=0;
	
	int i=0;
	while(str[i]!='\0')
	{
		originalLength++;
	    if(str[i]==' ')
		{
			numberOfBlank++;		
	    }	 
	    ++i;
	} 
	//newlength位把空格替换成%20之后的长度
	int newLength=originalLength+numberOfBlank*2;
	if(newLength>length)   //容量不够 
	{
		return ;	
    }
    
    int indexOfNew=newLength;
    int indexOfOriginal=originalLength;
    
    while(indexOfOriginal>=0 && indexOfNew>indexOfOriginal)
    {
    	if(str[indexOfOriginal]==' ')
    	{
    		str[indexOfNew--]='0';
    		str[indexOfNew--]='2';
    		str[indexOfNew--]='%';
		}
		else
		{
			str[indexOfNew--]=str[indexOfOriginal];
		}
		--indexOfOriginal;
	}
}
int main()
{
	char str[20]="hello i am a hl";
	ReplaceBlank(str,30);
	cout<<"  "<<str<<endl; 
}
