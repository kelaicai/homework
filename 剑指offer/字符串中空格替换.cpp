#include<iostream>
using namespace std;

//lenghthΪ����������� 
void ReplaceBlank(char str[],int length)
{
	if(str==NULL || length <=0)
	{
		return ;
	}
	int originalLength=0;  //�ַ�����ʵ�ʳ��� 
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
	//newlengthλ�ѿո��滻��%20֮��ĳ���
	int newLength=originalLength+numberOfBlank*2;
	if(newLength>length)   //�������� 
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
