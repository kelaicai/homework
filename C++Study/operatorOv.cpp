// 20180513.cpp : �������̨Ӧ�ó������ڵ㡣
//

#
/*
1.
2.
3.


C++14   ���������
���壺�ö����������ֵĺ���������һ��    x-y => x.operator-(y) (T)

������


������������Ѱ����������غ���ʱ�Ĺ���
1.�����ҳ�Ա����(��������غ���)
2.����������������غ���

string

дʱ������stringʵ��  ��ÿһ��String��Դ���Ӽ���  ���ַ������ڴ�ŵ�һ��
*/
#include <iostream>
#include <string.h>
using namespace std;

class String
{
public:
	String(char *ptr = NULL)
	{
		mpstr=new NodeString(ptr);
	}
	String(const String &src)
	{
		//mpstr = new char[strlen(src.mpstr) + 1];
		//strcpy(mpstr, src.mpstr);
	//	mpstr = src.mpstr;
	//	++(*((int*)mpstr));
	    mpstr->str=src.mpstr->str;
		src.mpstr->count++; 
		mpstr->count=src.mpstr->count;
	}
	
	char* getMpstr()
	{
		return mpstr->str;
	}
	String& operator=(const String &src)
	{
		if (this == &src)
			return *this;

		//(*((int *)mpstr))--;
		mpstr->count--;
		src.mpstr->count--;
		if (mpstr->count == 0)
		{
			delete[]mpstr;
			mpstr = NULL;
		}

		//mpstr = new char[strlen(src.mpstr) + 1];
		//strcpy(mpstr, src.mpstr);
		mpstr->str = src.mpstr->str;
     //		++(*((int*)mpstr));
        mpstr->count++;
        src.mpstr->count++;
		return *this;
	}
	~String()
	{
		//(*((int *)mpstr))--;
		mpstr->count--;
		if (mpstr->count == 0)
		{
			delete[]mpstr;
			mpstr = NULL;
		}
	}

	bool operator>(const String &src)
	{
		return strcmp(mpstr->str, src.mpstr->str) > 0;
	}
	bool operator<(const String &src)
	{
		return strcmp(mpstr->str, src.mpstr->str) < 0;
	}
	bool operator==(const String &src)
	{
		return strcmp(mpstr->str, src.mpstr->str) == 0;
	}

	int length()const{ return strlen(mpstr->str); }
	char& operator[](int index)
	{
	/*	char *tmp = new char[strlen(mpstr + 4) + 1 + 4];
	//	strcpy(tmp + 4, mpstr + 4);
		*((int*)tmp) = 1;
		--(*((int*)mpstr));
		mpstr = tmp;
		return (mpstr + 4)[index];
	
	*/
	
	  NodeString *tmp=new NodeString[strlen(mpstr->str)+1];
	  tmp->count=1;
	  strcpy(tmp->str,mpstr->str);
	  mpstr->count--;
	  delete mpstr->str;
	  mpstr->str=tmp->str;
	  return  mpstr->str[index];
	  
    }
	const char* c_str()const{ return mpstr->str; }
private:
	struct NodeString
	{
		int count;
		char *str;
		NodeString(char *_str=NULL):count(0),str(_str)
		{
			if(_str==NULL)
			{
				str=new char[1];
				str[0]='\0';
			}
			else
			{
				int len=strlen(_str);
				str=new char[len+1];
				count=0;
			}
		}
	};
	
	NodeString* mpstr;
	

	friend ostream& operator<<(ostream &out, const String &src);
	friend String operator+(const String &lhs, const String &rhs);
};
//operator+
//��������������ڴ�й¶����
String operator+(const String &lhs, const String &rhs)
{
	/*
	char *ptmp = new char[lhs.length() + rhs.length() + 1];
	strcpy(ptmp, lhs.mpstr);
	strcat(ptmp, rhs.mpstr);
	String tmp(ptmp);
	delete[]ptmp;
	*/
	
	char *tmp=new char[lhs.length()+rhs.length()+1];
	strcpy(tmp,lhs.mpstr->str);
	strcat(tmp,rhs.mpstr->str);
	String stmp(tmp);
	delete tmp;
	return stmp;
}
ostream& operator<<(ostream &out, const String &src)
{
	out << src.mpstr->str;
	return out;
}
int main()
{
	//string
	String str1;
	String str2 = "hello";
	String str5(str2);     // str5[0] = 'k';
	String str3 = "world";
	String str4 = str2 + str3;

	cout << str4 << endl;

	if (str2 > str3)
	{
		cout << "str2 > str3" << endl;
	}

	int size = str4.length();
	for (int i = 0; i<size; ++i)
	{
		//str4.operator[](i)   char& operator[](int index);
		//int data = array[10]   array[10] = 10; str4[10] = 'a';
		cout << str4[i];
	}
	cout << endl;

	//char* <= string
	char buffer[1024] = { 0 };
	strcpy(buffer, str4.c_str());
	cout << buffer << endl;

	/*
	�����͵�����
	*/

	return 0;
}


