#include<iostream>
#include<cstring> //provide strlen()
using namespace std;
int main(){
	const int Size=15;
	char name1[Size];
	char name2[Size]="C++owboy";
	//note some implemention may require the static keyword
	//to initialize the array name2;
	cout<<"Howdy i'm "<<name2;
	cout<<"! what's your name \n";
	cin>>name1;
	cout<<"well, "<<name1<<" your name has";
	cout<<strlen(name1)<<"letters and is stored\n";
	cout<<"int an array of "<<sizeof(name1)<<"bytes"<<endl;
	cout<<"your initalize is "<<name1[0]<<endl;
	name2[3]='\0';
	cout<<"here are the first 3 characters of my name :";
	cout<<name2<<endl;
	return 0;
}
