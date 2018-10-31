#include"display.h"

int Fobnacci_stack(unsigned long num)
{
	if(num==0)
	{
		return 0;
	}
	if(num==1)
	{
		return 1;
	}
	return Fobnacci_stack(num-1)+Fobnacci_stack(num-2);
}

int Fobnacci_iterator(unsigned long num){
	int a[2]={0,1};
	
	int fa=0;
	int fb=1;
	int fn=fa;
	if(num==0 || num==1)
	{
		return num;
	}
	for(int i=2;i<=num;i++)
	{
		fn=fa+fb;
		fa=fb;
		fb=fn;
	}
	return fn;
} 
int main()
{
	int num=10; 
	//cout<<Fobnacci_stack(num)<<endl;
	cout<<Fobnacci_iterator(num)<<endl;
	return 0;
}
