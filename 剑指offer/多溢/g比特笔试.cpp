#include<iostream>
using namespace std;

/*
int fun(int arr[],int len)
{

	int min=0;
	for(int i=0;i<len;i++)
	{	
		int sum=0;
		for(int j=i;j<len;j++)
		{
			sum+=arr[j];
			if(min<sum)
			{
				min=sum;
			}
		}
	}
	return min;
}
int main()
{
	int arr[]={-2,6,-1,-5,4,-7,-2,3};
	int len=sizeof(arr)/sizeof(arr[0]);
	int f=fun(arr,len);
	cout<<f<<endl;
} 
*/

#include <bits/stdc++.h>
using namespace std;
#define mo 200005
int ans;
int a[11]={2,0,1,8};
int ss[mo];
int le=0;
int n;
void dfs(int t,int l,int s,int p)
{
    if(s>n||t+4-p>10) return ;
    if(p==4) ans++;
    int lr=0;
    if(t==0) lr=1;
    for(int i=lr;i<10;i++)
    {
        if(i==a[p]&&p<4) dfs(t+1,i,s*10+i,p+1);
        else dfs(t+1,i,s*10+i,p);
    }
}

int main()
{
    while(cin>>n)
    {
        ans=0;
        dfs(0,0,0,0);
        cout<<ans<<endl;
    }
}


bool func(int a)
{
	char buff[128] = "";
	sprintf(buff, "%d", a);

	int len = strlen(buff);

	char want[5] = "2018";
	int j = 0;
	int k=0;
	for (int i = 0; i<len; ++i)
	{
		for(int j=i;j<len;j++)
		if (buff[j] == want[k])
		{
			j++;
			k++;
		}
		if (j == 4)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int val;
	cin >> val;
	int count = 0;
	for (int i = 2018; i<=val; ++i)
	{
		if (func(i))
		{
			count++;
		}
	}
	cout << count << endl;
	return 0;
}
