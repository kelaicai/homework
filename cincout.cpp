#include<iostream>
using namespace std;
//cin,cout类对象， 
int main(){
//	char name[30];
	//scanf("%s",name)；
//	cin>>name;  // >>流输入运算符
   // fgets(name,30,stdin);
   string name;
   cin>>name;

	cout<<"name="<<name<<endl<<cout<<name.max_size()<<endl;
	//printf("name=%s",name);
	return 0; 
}
