#include<stdio.h>
#include<stdlib.h>
#include<typeinfo.h>
using namespace std;
int main()
{
	const int a=10;
	//int arr[a]={0};   //���� 	[Error] variable-sized object may not be initialized
	
	//const int* p=&a;  //const int*  --->const int �ұ���ʲô����
	//int* p=&a;
	cout<<typeid(&a).name<<endl;
	cout<<typeid(p).name<<endl;
	
	 
}
