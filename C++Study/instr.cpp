//instr1/cpp
#include<iostream>
using namespace std;
int main(){
	const int ArSize=20;
	char name[ArSize];
	char dessert[ArSize];
	
	cout<<"enter your name:"<<endl;
	cin>>name;   //cin.getline(name,20);
	 
	cout<<"enter your favorit dessert:\n";
	cin>>dessert;
	cout<<"I have some_delicious dessert"<<dessert;
	cout<<"for you   "<<name<<"\n";
	return 0; 
}
