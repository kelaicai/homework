#include<iostream>  
#include<vector>  
#include<cstring>  
using namespace std;  
#include<assert.h>  

void Combination(char *string ,int number,vector<char> &result);  
  /*
  �����������ڳ���Ϊn���ַ�������m���ַ�����ϡ������ȴ�ͷɨ���ַ����ĵ�һ���ַ���
  ��Ե�һ���ַ�������������ѡ�񣺵�һ�ǰ�����ַ��ŵ������ȥ��
  ������������Ҫ��ʣ�µ�n-1���ַ���ѡȡm-1���ַ���
  �ڶ��ǲ�������ַ��ŵ������ȥ��������������Ҫ��ʣ�µ�n-1���ַ���ѡ��m���ַ���
  */
    /*
void Combination(char *string)  
{  
    assert(string != NULL);  
    vector<char> result;  
    int i , length = strlen(string);  
    for(i = 1 ; i <= length ; ++i)  
        Combination(string , i ,result);  
}  
  
void Combination(char *string ,int number , vector<char> &result)  
{  
    assert(string != NULL);  
    if(number == 0)  
    {  
        static int num = 1;  
        printf("��%d�����\t",num++);  
  
        vector<char>::iterator iter = result.begin();  
        for( ; iter != result.end() ; ++iter)  
            printf("%c",*iter);  
        printf("\n");  
        return ;  
    }  
    if(*string == '\0')  
        return ;  
    result.push_back(*string);  
    Combination(string + 1 , number - 1 , result);  
    result.pop_back();  
    Combination(string + 1 , number , result);  
}  
  
int main(void)  
{  
    char str[] = "abc";  
    Combination(str);  
    return 0;  
}  
*/

  
int a[] = {1,3,5,4,6};  
char str[] = "abcde";  
  
void print_subset(int n , int s)  
{  
    printf("{");  
    for(int i = 0 ; i < n ; ++i)  
    {  
        if( s&(1<<i) )         // �ж�s�Ķ���������ЩλΪ1��������ȡĳһλ  
            printf("%c ",str[i]);   //����a[i]  
    }  
    printf("}\n");  
}  
  
void subset(int n)  
{  
    for(int i= 0 ; i < (1<<n) ; ++i)  
    {  
        print_subset(n,i);  
    }  
}  
  
  
  
int main(void)  
{  
    subset(5);  
    return 0;  
}  
