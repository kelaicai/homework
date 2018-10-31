#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h> 
/* edit by jack zhang*/
int my_strlen(const char *src)
{
	int length = 0;
	assert(src!=NULL);
	while (*src++)
	{
		length++;
	}
	return length;

}

char* my_strcpy(char *desc,const char *src)
{
    assert(src != NULL && desc != NULL);
	char* p = desc;
	while(*desc++);
	desc--;
	while (*desc++=*src++);
	return p;
}

int my_strcmp(const char *desc,const char *src)
{
	assert(src != NULL && desc != NULL);
	//desc和src相同的就后移，其中一个当前指向存贮‘\0'时，停止循环
	while (*desc++ == *src++ && *desc!='\0' && *src!='\0');
	if (*desc == '\0'&& *src == '\0'){
		return 0;
	}
	return *desc > *src ? 1 : -1;

}
 
int count_word(const char* src){
	assert(src); 
	int count = 0;
	int len = my_strlen(src);
	int i = 0;
	if(*(src+len-2)!=' '){  //如果字符串不是以空格结尾 
		count=1;
	}
	for (i = 0; i < len; i++)
	{
		if (*src++ == ' ')
		{
			count++;
		}
	}
	return count;
}
int count_word2(const char *src){
	assert(src!=NULL);
    int count=0;
    char* p=src; 
    int len=my_strlen(src);
    while(*src)
	{
    	if(*src!=' ' && *src!='\0')
		{
			
	      	count++;	
	        	while(*src!=' ' && *src!='\0')
		           {
	    	          src++;
		        }	
		}
		else
		{
			src++;
		}
	}
	return count;
} 
int count_word3(const char *src)
{
	int i=0;
	int count=0;
	int len=my_strlen(src);
	while( i<len && src[i] && *src!='\0')
	{ 
	  if(src[i]!=' ')
	  {
	  	count++;
		while(i<len && src[i]!=' ' && src[i]!='\0')
		{
			i++;
		} 
	  }
	  else
	  {
	  	i++;  	
	  } 
	} 
	return count;
}
int main(){
	char str1[]="hello man";
	char str2[]="hi nice to meet you";
	char *str3="ab cd ef gh   ";
	printf("my_strlen=%d\n",my_strlen(str1));
	printf("my_strcmp(str1,str2)=%d\n",my_strcmp(str1,str2));
	printf("my_strcpy(str1,str2)=%s\n",my_strcpy(str1,str2));
	printf("count_word(str1) now have %d word\n",count_word3(str3));
	getchar();
	return 0;
}
