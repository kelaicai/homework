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
ʱ�����ƣ�C/C++���� 1000MS���������� 3000MS
�ڴ����ƣ�C/C++���� 131072KB���������� 655360KB
��Ŀ������
�ֳ���N��ʳ�ÿ��ʳ����Ai�ݡ�

ÿ��ֳ����һ��ʳ�������һ��ʳ���ÿ��ֻ�ܽ��гԻ������е�һ�ֶ���������������M��

���ھֳ���֪��M����p��ʳ��ķ����������Ӵ�С����ͬ�㲢�У�����3 3 2��������Ϊ1 1 3��

N,M,P<=100,Ai<=1000

��һ��N M P

�ڶ���N����Ai

������M�У�ÿ��A i����B i�ֱ��ʾ��һ��ʳ��i����һ��ʳ��i
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
����ID
ʱ�����ƣ�C/C++���� 1000MS���������� 3000MS
�ڴ����ƣ�C/C++���� 131072KB���������� 655360KB
��Ŀ������
СC��һ��Ʊ������Ʊ��ID�ǳ���Ϊ6���ַ�����ÿ���ַ��������֣����������ID�����������ID���������Ϳ�ʼ����ID��ÿһ�β�����������ѡ������һ�����ֲ����滻����

������ID��ǰ��λ����֮�͵��ں���λ����֮�ͣ���ô���ID�������˵ġ����СC��һ�£�������Ҫ�������Σ���ʹID�������ID

����
����ֻ��һ�У���һ������Ϊ6���ַ�����

���
��������С��������
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

