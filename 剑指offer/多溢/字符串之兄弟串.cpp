#include<iostream>
#include<algorithm>
using namespace std;
/*
�ֵܴ����㣺������������ȣ���1�Ͷ�����ͬ���ַ������ҳ��ִ������ 
*/

bool isBrother(string & str1,string& str2)
{
	bool flag=false;
	
	if(str1.size()==0 || str2.size()==0 || str1!=str2) return flag;
	
	int hash1[26]={0};
	int hash2[26]={0};
	int len=str1.size();
	for(int i=0;i<len;i++)
	{
		hash1[str1[i]-'a']++;
		hash2[str2[i]-'b']++;
	}
	for(int j=0;j<26;j++)
	{
		if(hash1[j]!=hash2[j])
		return false;
	}
	
	return true; 
 } 
int main()
{
	
}
