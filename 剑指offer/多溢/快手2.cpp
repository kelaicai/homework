#include<iostream>

using namespace std;
int bags[3]={3,5,7};
int num;
int X;

void func()
{
	int x=X;
	int weight=0; 
	if(x < 3 || x < 5 || x < 7) 
	{
		num= -1;
		return;
	}
	for(int i=0;i<3;i++)
	{
		if(bags[i]<x)
		{
			weight+=bags[i];
			num++;	
			x-=bags[i];
		}
	}
}
int main()
{
	int res=0;
	while(cin>>X)
	{
		func();
		cout<<num+1<<endl;
		num=0;		
	} 
} 
