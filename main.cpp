#include<iostream>
#include<stdlib.h>
/*
typedef enum BOOOL{
   false.true
}
*/
using namespace std;
int main1(void){
	const int a=100;  //������const 
	//a=200;
	const int *p=&a;    // const int->const int
   char *q=(char*)malloc(100); //void *
    //string
    bool b=true;
    if(!b){
    	printf("b value is false");
	}else{
		printf("b is true");
	}
	return 0;
} 
enum SEASON{
	Spr,Sum,Aut,Win
};
//�ȼ���
/*
#define Spr 0;
#define Sum 1;
#define Aut 2;
.. 
*/ 

int main(){
	SEASON s; //C++ö������ֻ�ܸ�ֵΪö�ٱ��� 
	s=Spr;
	
	int a,b=5;
	/*a=b=100;
	printf("a=%d,   b=%d\n",a,b);*/
	(a=b)=100;
	printf("a=%d,   b=%d",a,b);
	(a!=b? a:b)=1000;
	printf("a=%d,   b=%d",a,b);
	return 0;
}

