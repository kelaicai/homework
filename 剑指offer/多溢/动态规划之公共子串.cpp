#include<iostream>
#include<string>
#include<cstring>
int dp[10240][10240];

void getDp(char str1[],char str2[])
{
	int len1=strlen(str1);
	int len2=strlen(str2);
	for(int i=0;i<len1;i++)
	{
		if(str1[i]==str2[0])
		dp[i][0]=1;
	}
	for(int i=0;i<len2;i++)
	{
		if(str2[i]==str1[0])
		dp[0][i]=1;
	} 
	for(int i=1;i<len1;i++)
	{
		for(int j=1;j<len2;j++)
		{
			if(str1[i]==str2[j])
			{
				dp[i][j]=dp[i-1][j-1]+1;
			}
		}
	}
}

char* lcst1(char str1[],char str2[])
{
	if(str1==NULL || str2==NULL)  return "";
	int end=0;
	int max=0;
	int len1=strlen(str1);
	int len2=strlen(str2);
	for(int i=0;i<len1;i++)
	{
		for(int j=0;j<len2;j++)
		{
			if(dp[i][j]>max)
			{
				max=dp[i][j];
				end=i;
			}
		}
	}
	char* res=new char[end];
	strncpy(res,str1+end-max+1,max);
	return res;
} 
char in1[10240];
char in2[10240];
char res[10240];
int main()
{
	while(cin>>in1>>in2)
	{
		char *p=lcst1(in1,in2);
		strcpy(res,p);
		delete p;
		cout<<res<<endl;
		memset(res,0,10240);
	}
} 
