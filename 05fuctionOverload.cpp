#include<iostream>
using namespace std;
/*
int func(int a){
printf("int func(int a)");
} 
*/
/*
int func(char a){
  printf("int func(char a)"); 

}
*/

int abs(int data){
	return data>0? data:-data;
}

float abs(float data){
	return data>0? data:-data;
} 

int main( )
{
	int ret=abs(-5);
    cout<<ret<<endl;
    float ret2=abs(-5.5f);
    cout<<ret2<<endl;
	return 0; 
} 
