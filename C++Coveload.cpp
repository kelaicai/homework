#include<iostream>
using namespace std;
//函数重载 (静多态 
//函数名相同，参数列表不同，类型个数，顺序
//返回类型不构成重载条件
//匹配原则
//1 严格匹配 2隐式转换 double int float int long double 

void print_i(int a){
	printf("void prin(int a)"); 
} 
void print_d(double a){
	cout<<"uisng print (double a)";
}
/*
void print(char  b){
	printf("void print(char b)"); 
}
void print(int a,char b){
	printf("void print(int a,char b)");
}
*/
int main(){
	int a;
	char b;
//	print(a);
  //print(b);
 // print(a,b);
// print(1);
 //print('a');
// print(4.5);
 //print("China"); //int a到long 和double 
 print_i(3.4);
	return 0;
}
