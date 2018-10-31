#define NDEBUG 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define MYASSERT(x)  \
   if(!(x)){   \
  printf("MYASSERT宏%s开始检测…. \n",#x);   \
  printf("当前函数名为%s，文件名为%s 代码行号为%d ",    \
  _FUNCTION_,_FILE_,_LINE_);   \
  char str[50];         \
  sprint(str,"当前函数名%s,文件名 %s 代码行号 %d",  \
  _FUNCTION_,_FILE_,_LINE_);    \
   MassageBoxA(0,str,str,0);    \
}   \

int main(){
 char *p=(char *)malloc(sizeof(char)*1024*1024*1024*1024);
 MYASSERT(p!=NULL);
 *p='H';
 getchar();

} 
