#include<iostream>
#include<vector>
#include<cstring>
#include<cassert>
using namespace std;

void Combination(char *string,int number,vector<char> &result);

/*
假设想在长度为N的字符串汇总求m个字符的组合。首先从头扫描字符串第一个字符针对于第一个字符
有两种选择：
1，把该字符放到组合中去，接下来需要在剩下的N-1个字符中选取m-1个字符
2，不把该字符放到组合中去，接下来需要在属于的n-1和字符中选择m个字符 
*/

void  Combination(char *string)
{
	assert(string!=NULL);
	vector<char> result;
	int length=strlen(string);
	for(int i=0;i<length;++i)
	{
		Combination(string,i,result);
	 } 
} 











 
