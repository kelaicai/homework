#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

int search_string(char *src,char *dst)
{
	assert(src!=NULL);
	assert(dst!=NULL);
	int num=0;
	int dst_len=strlen(dst);
	char *ptr=strtok(src," ");
	if((strncmp(ptr,dst,dst_len))==0)
	{
		num++;
	}
	
	while((ptr=strtok(NULL," "))!=NULL)
	{
		if((strncmp(ptr,dst,dst_len))==0)
		{
			num++;
		}
	}
	return num;
} 

 
int main()
{
	char buff[]="you are the one in the world";
	char dest[]="the";
	int n=search_string(buff,dest);
	printf("there are %d the int the buff",n);	
} 
