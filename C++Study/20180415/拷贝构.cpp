#include<iostream>
#include<string.h>
using namespace std;

class Stu
{
	private:
	char *sname;
	int sage;
	int sclan;
	public:
	
	Stu()
	{
		cout<<"Ĭ�Ϲ��캯������ִ��"<<endl; 
		sname=new char[10];
		sage=0;
		sclan=0;
	}
	
	Stu(char *name,int age,int clan)
	{
		cout<<"���������캯������ִ��"<<endl; 
		int len=strlen(name)+1;
		sname=new char[len];
		strcpy(sname,name);
		sage=age;
		sclan=clan; 
	}
	
	~Stu()
	{
		cout<<"������������ִ��"<<endl; 
		delete[] sname;
		sname=NULL;
		sage=0;
		sclan=0;
	}	
	//�������캯�� ǳ����   
	Stu(const Stu &stu)
	{
		cout<<"�������캯������ִ��"<<endl; 
		sage=stu.sage;
		sclan=stu.sclan;
		int i=0;
		int len=strlen(stu.sname)+1;
		sname=new char[len];
		for(i=0;i<len;i++)
		{
			sname[i]=stu.sname[i];
		}
	}
	
	void operator=(const Stu &stu)
	{
		if(this==&stu)
		{
			return ;
		}
	    cout<<"��ֵ��������ִ��"<<endl; 
		delete sname;
		sname=new char[10];
		int len=strlen(stu.sname);
		for(int i=0;i<len;i++)
		{
			sname[i]=stu.sname[i];
		}
		sage=stu.sage;
		sclan=stu.sclan;
	}
	
	void getName()
	{
		cout<<sname<<endl;	
	} 
/*	
	Stu(const Stu &stu)
	{
        
		
	}*/
};
int main()
{
	char name[]="zhang";
	Stu s1(name,20,1);
	Stu s2(s1);
	Stu s3;
	s2=s1; 
	s3=s1; 
	s2.getName();
}
