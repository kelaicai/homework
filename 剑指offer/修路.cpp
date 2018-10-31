#include<iostream>
#include<algorithm>
using namespace std;

int c[1024];
int n; 
int arr[1024];


int main()
{
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
			cin>>arr[i];
		for(int i=1;i<n;i++)
		{
			c[i]=arr[i];
	
		}
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<n;j++)
			{
				c[i][j]=max(c[i-1][j],c[i][j-1])+c[i-1][j-1];
			}
		}
		
		cout<<c[1][n-1];
	}
} 

/*
int cmp(const void* x,const void* y)
{
	return *(int*)x<*(int*)y;
}
int n;
int start[1024];
int finish[1024]; 
bool b[1024];

bool GreedySelector(int n,int s[],int f[],bool b[])
{
	b[1]=true;
	int j=1;
	for(int i=2;i<n;i++)
	{
		if(s[i]>f[j])
		{
			b[j]=true;
			j=i;
		}	else b[j]=false;
	}

}
int main()
{
	int count=0; 
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>start[i];
			cin>>finish[i];
		}
	
		GreedySelector(n-1,start,finish,b);
		for(int i=0;i<n;i++)
		{
			if(b[i]) count++;
		}
		cout<<n-count<<endl;
	}
}
*/

