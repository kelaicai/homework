#define NDEBUG 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define MYASSERT(x)  \
   if(!(x)){   \
  printf("MYASSERT��%s��ʼ��⡭. \n",#x);   \
  printf("��ǰ������Ϊ%s���ļ���Ϊ%s �����к�Ϊ%d ",    \
  _FUNCTION_,_FILE_,_LINE_);   \
  char str[50];         \
  sprint(str,"��ǰ������%s,�ļ��� %s �����к� %d",  \
  _FUNCTION_,_FILE_,_LINE_);    \
   MassageBoxA(0,str,str,0);    \
}   \

int main(){
 char *p=(char *)malloc(sizeof(char)*1024*1024*1024*1024);
 MYASSERT(p!=NULL);
 *p='H';
 getchar();

} 
