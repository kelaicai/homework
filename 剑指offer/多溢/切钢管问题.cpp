#include<iostream>
#include<climits> 
#include<cstring>
using namespace std;
int num=0;
int N;  //n个钢管 
int price[10240]; 
//price代表受益，n代表第一段的切割长 
int cut_rod(int n)
{
	if(n==0)  return  0;
	int q=INT_MIN;
	for(int i=1;i<=n;i++)
	{    //max(q,price[i]+cut_rod(n-i))   price[i]+cut_rod(n-i)表示
	//我们将钢条从左边切割下长度为i的一段，只对右边剩下的n-i段钢管继续切割 ，q表示0到i这一段的价值 
		q=max(q,price[i]+cut_rod(n-i));
	}
	return q;
}
/*

int main()
{
	while(cin>>N)
	{
		for(int i=1;i<N;i++)
		{
			cin>>price[i];
		}
		int maxValue=cut_rod(N);
		cout<<maxValue<<endl; 
	}
} 
*/
int memorized_cut_rod(int n);
int r[10240]={INT_MIN};  //备忘录方法  --->记录下切割到长度为i的钢条的价值 ，对，是价值！！ r[0]=0表示长度为零的钢条
//没有切割，价值为0 
int memoried(int n)
{
	return memorized_cut_rod(n);
}

int memorized_cut_rod(int n)
{
	num++;
	int q;
		if(n==0) 	return 0;//长度为0，价值为0 
		
		if(r[n]!=-1) return r[n];  //长度为n的钢条的价值已经被计算过 无需再次计算	
	
		
		
		q=INT_MIN;
		for(int i=1;i<=N;i++)
		{
			q=max(q,price[i]+memorized_cut_rod(n-i));
		}	
		r[n]=q;	
		return q; //返回长度为N的钢条切割的最大价值 
} 
/*
int main()
{
	memset(r,-1,1024);
	while(cin>>N)
	{
		
		price[0]=0;
		for(int i=1;i<=N;i++)
		{
			cin>>price[i];
		}
		cout<<N<<endl; 
		int n=N;
	
		int maxValue=memoried(n);
		cout<<maxValue<<endl; 
		for(auto i=0;i<=N;i++)
		{
			cout<<r[i]<<" ";
		}
		cout<<"count by="<<num<<endl;
		memset(price,0,sizeof(price));
		memset(r,-1,sizeof(r)); 
	}
}

*/


int bottom_to_rod(int n)
{
	r[0]=0;
	
	for(int i=1;i<=n;i++)
	{
		int q=INT_MIN;
		
		for(int j=1;j<=i;j++)
		{
			//长度为i的钢管切割的最大价值=分割j端和N-j段中的最大价值选出最大 i-j是模拟切钢管的长度 
			q=max(q,price[j]+r[i-j]);
		}
		r[i]=q; 
	}
	return r[n];
} 

int main()
{
	while(cin>>N)
	{
		for(int i=1;i<=N;i++)
		{
			cin>>price[i];
		}
		int maxValue=bottom_to_rod(N);
		cout<<maxValue<<endl; 
	}
}
