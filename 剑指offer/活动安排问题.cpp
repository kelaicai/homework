#include<iostream>


using namespace std;

const int NUM=50;
void GreedySelector(int n,int s[],int f[],bool b[])
{
	b[1]=true; //默认活动将第一个活动先安排 
	int j=1; //记录最近一次加入b中的活动
	
	
	//一次检查活动I和当前选择活动是否相容 
	for(int i=2;i<n;i++)
	{
		if(s[i]>f[j])
		{
			b[j]=true;
			j=i;
		}else b[i]=false;
	 } 
	 
		
} 
int main()
{
	int s[]={0,1,3,0,5,3,6,8,8,2,12};//开始时间 
	int f[]={0,4,5,6,7,8,9,10,11,12,13,14};//结束时间 
	bool b[NUM];  //存储被安排的编号 
	int n=sizeof(s)/sizeof(s[0])-1;
	
	GreedySelect(n,s,f,b);  
	for(int i = 1; i <= n; i++)      //输出被安排的活动编号和它的开始时间和结束时间 
    {  
         if(b[i]) cout << "活动 " << i << " :" << "(" << s[i] << "," << f[i] << ")" <<endl;  
     }  
     return 0;  
} 
