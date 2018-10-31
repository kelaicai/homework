#include<iostream>
#include<string>
/*
template<typename T>
class NamedObject
{	
	public:
		NamedObject(const char* name,const T& value);
		NamedObject(const std::string &name,const T& value);
		
	private:
		std::string nameValue;
		T object;
};

*/

template<typename T>
class NamedObject
{
	public:
	NamedObject(std::string &name,const T & value);
	private:
	std::string & nameValue;  //�����һ������ 
	const T object;	//�����һ��const 
};

int main()
{
	std::string newDog("Personphone");
	std::string oldDog("Satch");
	
	NamedObject<int> p(newDog,2);
	NamedObject<int> s(oldDog,36);
	p=s; //p.nameValue����ָ��s.nameValue��ָ�Ǹ�string�� 
}
