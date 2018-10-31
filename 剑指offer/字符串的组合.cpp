#include<iostream>  
#include<vector>  
#include<cstring>  
using namespace std;  
#include<assert.h>  

void Combination(char *string ,int number,vector<char> &result);  
  /*
  假设我们想在长度为n的字符串中求m个字符的组合。我们先从头扫描字符串的第一个字符。
  针对第一个字符，我们有两种选择：第一是把这个字符放到组合中去，
  接下来我们需要在剩下的n-1个字符中选取m-1个字符；
  第二是不把这个字符放到组合中去，接下来我们需要在剩下的n-1个字符中选择m个字符。
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
        printf("第%d个组合\t",num++);  
  
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
        if( s&(1<<i) )         // 判断s的二进制中哪些位为1，即代表取某一位  
            printf("%c ",str[i]);   //或者a[i]  
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
