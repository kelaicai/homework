#include<iostream>
using namespace std;
//�������� (����̬ 
//��������ͬ�������б�ͬ�����͸�����˳��
//�������Ͳ�������������
//ƥ��ԭ��
//1 �ϸ�ƥ�� 2��ʽת�� double int float int long double 

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
 //print("China"); //int a��long ��double 
 print_i(3.4);
	return 0;
}
