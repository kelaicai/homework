#include<iostream>
#include<climits> 
#include<cstring>
using namespace std;
int num=0;
int N;  //n���ֹ� 
int price[10240]; 
//price�������棬n�����һ�ε��и 
int cut_rod(int n)
{
	if(n==0)  return  0;
	int q=INT_MIN;
	for(int i=1;i<=n;i++)
	{    //max(q,price[i]+cut_rod(n-i))   price[i]+cut_rod(n-i)��ʾ
	//���ǽ�����������и��³���Ϊi��һ�Σ�ֻ���ұ�ʣ�µ�n-i�θֹܼ����и� ��q��ʾ0��i��һ�εļ�ֵ 
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
int r[10240]={INT_MIN};  //����¼����  --->��¼���и����Ϊi�ĸ����ļ�ֵ ���ԣ��Ǽ�ֵ���� r[0]=0��ʾ����Ϊ��ĸ���
//û���и��ֵΪ0 
int memoried(int n)
{
	return memorized_cut_rod(n);
}

int memorized_cut_rod(int n)
{
	num++;
	int q;
		if(n==0) 	return 0;//����Ϊ0����ֵΪ0 
		
		if(r[n]!=-1) return r[n];  //����Ϊn�ĸ����ļ�ֵ�Ѿ�������� �����ٴμ���	
	
		
		
		q=INT_MIN;
		for(int i=1;i<=N;i++)
		{
			q=max(q,price[i]+memorized_cut_rod(n-i));
		}	
		r[n]=q;	
		return q; //���س���ΪN�ĸ����и������ֵ 
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
			//����Ϊi�ĸֹ��и������ֵ=�ָ�j�˺�N-j���е�����ֵѡ����� i-j��ģ���иֹܵĳ��� 
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
