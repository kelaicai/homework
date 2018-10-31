#include<iostream>
#include<cstring>

using namespace std;

int fun2(char str1[],char str2[])
{
	int sum1==0,sum2=0;
	for(int i=0;i<3;i++)
	{
		sum1+=str1[i]-'0';
		sum2+=str2[i]-'0';	
	} 
	// 
	int diff=0;
	if(sum1>sum2)
	{
		diff=sum1-sum2;
		for(int i=0;i<3;i++)
		{
			if(str2[i]+diff==)	
		}	
	}
}
int  fun(char str[])
{
	len=strlen();
	if(len!=0)  return 0;
	
	char* str1=new char[3];
	char* str2=new char[3];
	for(int i=0;i<len;i++)
	{
		if(i<3)
		{
			str1[i]=str[i];
		}
		else{
			str2[i]=str[i];
		} 
	}
	
	return fun2();
	
	return len;	
} 
int main()
{
	
}

/*
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 131072KB；其他语言 655360KB
题目描述：
局长有N种食物，每种食物有Ai份。

每天局长会吃一份食物，或者买一份食物（即每天只能进行吃或买其中的一种动作），这样过了M天

现在局长想知道M天后第p种食物的份数排名（从大到小，相同算并列，例如3 3 2，则排名为1 1 3）

N,M,P<=100,Ai<=1000

第一行N M P

第二行N个数Ai

接下来M行，每行A i或者B i分别表示买一份食物i，吃一份食物i
*/
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int N,M,P;
	cin>>N>>M>>P;
	vector<int> vec(N+1);
	for(int i=1;i<N+1;++i)
	{
		cin>>vec[i];
	}
	char ch;
	int tmp;
	for(int i=0;i<M;++i)
	{
		cin>>ch>>tmp;
		if(ch == 'A')
		{
			++vec[tmp];
		}
		if(ch == 'B')
		{
			--vec[tmp];
		}
	}
	int res = 1;
	for (int i=1;i<N+1;++i)
	{
		if(vec[i] != vec[P] && vec[i] > vec[P])
		{
			res++;
		}
	}
	cout<<res<<endl;
	return 0;
}
/*
幸运ID
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 131072KB；其他语言 655360KB
题目描述：
小C有一张票，这张票的ID是长度为6的字符串，每个字符都是数字，他想让这个ID变成他的辛运ID，所以他就开始更改ID，每一次操作，他可以选择任意一个数字并且替换它。

如果这个ID的前三位数字之和等于后三位数字之和，那么这个ID就是辛运的。你帮小C求一下，最少需要操作几次，能使ID变成辛运ID

输入
输入只有一行，是一个长度为6的字符串。

输出
输出这个最小操作次数
*/
#include<iostream>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;
char s[10240];
int arr[10240],brr[10240];
int sum1=0,sum2=0;
int main()
{
	while(cin>>s)
    {
		int n=strlen(s);
		for (int i=0;i<n;i++) arr[i+1]=s[i]-'0';
		for (int i=1;i<=3;i++) 
            sum1=sum1+arr[i];
		for (int i=4;i<=6;i++) 
            sum2=sum2+arr[i];
		if (sum1<sum2) 
        {
            for (int i=1;i<=3;i++) 
                swap(arr[i],arr[i+3]);
        }
		for (int i=1;i<=3;i++) brr[i]=arr[i];
		for (int i=4;i<=6;i++) brr[i]=9-arr[i];
		sort(brr+1,brr+7);
		int sum=0;
		for (int i=6;i>=1;i--){
			if (sum>=abs(sum1-sum2)){
			cout<<6-i<<endl;
				return 0;
		}
			sum=sum+brr[i];
	}
	cout<<0<<endl;
    }
	return 0;
}

