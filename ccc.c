#include<stdio.h>
#define P(x) printf("%s=%d",#x,x);
int main()
{
	int a=2;
	int b=3;
	float x=11.5;
	float y=-5.5;
	printf("%f\n",(float)(a+b)+(int)x%(int)y);	//6.0
	x*=-1;
	y*=-1;
	printf("%d",a+b/1+(int)x%(int)y);//4
	P(a);
	
}
