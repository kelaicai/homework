#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;

class String
{
public:
	String(char *ptr = NULL)
	{
		if (ptr != NULL)
		{
			mpstr = new char[strlen(ptr) + 1 + 4];
			strcpy(mpstr + 4, ptr);
		}
		else
		{
			mpstr = new char[1 + 4];
			*(mpstr + 4)= '\0';
		}
		*((int*)mpstr) = 1;
	}
	String(const String &src)
	{
		//mpstr = new char[strlen(src.mpstr) + 1 + 4];
		//strcpy(mpstr + 4, src.mpstr);
		mpstr = src.mpstr;
		++*((int*)mpstr);
	}
	String& operator=(const String &src)
	{
		if (this == &src)
		{
			return *this;
		}
		--*((int*)mpstr);
		if (*((int*)mpstr) == 0)
		{
			delete[]mpstr;
			mpstr = NULL;
		}
		mpstr = src.mpstr;
		/*mpstr = new char[strlen(src.mpstr) + 1 + 4];
		strcpy(mpstr + 4, src.mpstr);*/
		++*((int*)mpstr);
		return *this;
	}
	~String()
	{
		--*((int*)mpstr);
		if (*((int*)mpstr) == 0)
		{
			delete []mpstr;
			mpstr = NULL;
		}
	}
	bool operator>(const String &src)
	{
		return strcmp(mpstr, src.mpstr) > 0;
	}
	bool operator<(const String &src)
	{
		return strcmp(mpstr, src.mpstr) < 0;
	}
	bool operator==(const String &src)
	{
		return strcmp(mpstr, src.mpstr) == 0;
	}

	int length()const
	{	
		return strlen(mpstr);
	}
	char& operator[](int index)
	{
		char *tmp = new char[strlen(mpstr + 4) + 1 + 4];
		strcpy(tmp + 4, mpstr + 4);
		(*((int*)tmp)) = 1;
		++(*((int*)mpstr));
		mpstr = tmp;
		return (mpstr + 4)[index];

		//return mpstr[index];
	}
	const char* c_str()const
	{
		return mpstr+4;
	}
private:
	char *mpstr;
	friend String operator+(const String &lhs, const String &rhs);
	friend ostream& operator<<(ostream &out, const String &src);
};

String operator+(const String &lhs, const String &rhs)//¸ÄÎªÐ´Ê±¿½±´
{
	char *ptmp = new char[strlen(lhs.mpstr+4)+ strlen(rhs.mpstr+4) + 10];
	strcpy(ptmp + 4,lhs.mpstr + 4);
	strcat(ptmp,rhs.mpstr + 4);
	String tmp(ptmp+4);
	delete[]ptmp;
	return tmp;
}
ostream& operator<<(ostream &out, const String &src)
{
	out << src.mpstr + 4 << endl;
	return out;
}
int main()
{
	String str1;
	String str2 = "hello";
	String str3 = "world";
	String str4 = str2 + str3;
	//String str4 = "helloworld";

	cout << str4 << endl;

	if (str2 > str3)
	{
		cout << "str2 > str3" << endl;
	}

	int size = str4.length() + 4 + 5;//strlen(str4 + 4) + 1 + 4
	for (int i = 0; i<size; ++i)
	{
		cout << str4[i];
	}
	cout << endl;

	char buffer[1024] = { 0 };
	strcpy(buffer, str4.c_str());
	cout << buffer << endl;
	return 0;
}

