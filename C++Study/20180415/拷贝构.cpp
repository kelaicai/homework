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
		cout<<"默认构造函数正在执行"<<endl; 
		sname=new char[10];
		sage=0;
		sclan=0;
	}
	
	Stu(char *name,int age,int clan)
	{
		cout<<"带参数构造函数正在执行"<<endl; 
		int len=strlen(name)+1;
		sname=new char[len];
		strcpy(sname,name);
		sage=age;
		sclan=clan; 
	}
	
	~Stu()
	{
		cout<<"析构函数正在执行"<<endl; 
		delete[] sname;
		sname=NULL;
		sage=0;
		sclan=0;
	}	
	//拷贝构造函数 浅拷贝   
	Stu(const Stu &stu)
	{
		cout<<"拷贝构造函数正在执行"<<endl; 
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
	    cout<<"赋值函数正在执行"<<endl; 
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
