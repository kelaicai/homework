#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int a=12345;;
	float b=1234.56;
	//printf("%-8d--",a);
	//printf("%10.2f\n",b);
	//printf("%f",b);
/*	cout<<"xxxxxxxxxx"<<endl;
	//cout<<setiosflags(ios::left)<<setw(8)<<a<<endl;  //����λ�������
	cout<<b<<endl;
	cout<<setw(10)<<setprecision(2)<<setiosflags(ios::fixed)<<b<<endl; 
	printf("%x",a);
	printf("%o",a);
	printf("%d",a);
	
	cout<<hex<<a<<endl;; //ʮ������ 
	cout<<oct<<a<<endl;  //�˽��� 
	cout<<dec<<a<<endl;   //ʮ���� 
	
*/	
    cout<<setfill('x')<<setiosflags(ios::left)<<setw(8)<<a<<endl;
	int hour=0;
	int min=0;
	int sec=0; 
    cout<<setfill('0')<<setw(2)<<hour<<":"<<setw(2)<<min<<":"<<setw(2)<<sec<<endl; 
	return 0;
} 
