#include<iostream>
#include<vector>
#include<cstring>
#include<cassert>
using namespace std;

void Combination(char *string,int number,vector<char> &result);

/*
�������ڳ���ΪN���ַ���������m���ַ�����ϡ����ȴ�ͷɨ���ַ�����һ���ַ�����ڵ�һ���ַ�
������ѡ��
1���Ѹ��ַ��ŵ������ȥ����������Ҫ��ʣ�µ�N-1���ַ���ѡȡm-1���ַ�
2�����Ѹ��ַ��ŵ������ȥ����������Ҫ�����ڵ�n-1���ַ���ѡ��m���ַ� 
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











 
