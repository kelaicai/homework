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
	std::string & nameValue;  //如今是一个引用 
	const T object;	//如今是一个const 
};

int main()
{
	std::string newDog("Personphone");
	std::string oldDog("Satch");
	
	NamedObject<int> p(newDog,2);
	NamedObject<int> s(oldDog,36);
	p=s; //p.nameValue不会指向s.nameValue所指那个string吗？ 
}
