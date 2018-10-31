#include<stdio.h>
#include<assert.h> 
#include<string.h>
int strlen_1(char *str)
{
	if(*str=='\0')
	{
		return 0;
	} 
	else
    {
    	return strlen_1(++str)+1; 
	}

}
int My_strstr_1(char srcstr[],char substr[])
{
	assert(srcstr!=NULL && substr!=NULL);
	int i=0;
	int j=0;
	int flag=0;
	int srclen=strlen_1(srcstr);
	int sublen=strlen_1(substr);
	
	for(i=0;i<srclen;i++)
	{
		for(j=0;j<sublen;j++)
		{
			if(srcstr[i+j]==substr[j])
			{
				flag++;			
			}
		}
		if(flag==sublen)
		{
			return i;
		}
	}
	return -1;
} 

int My_strstr_2(char srcstr[],char substr[])
{
	int i=0;
	int j=0;
	char *ptr_src=srcstr;
	char *ptr_sub=substr;
	int srclen=strlen_1(ptr_src);
	int sublen=strlen_1(ptr_sub);
	
	while(*ptr_src!='\0' || ptr_sub!=NULL)
	{
	
		if(strncmp(ptr_src,ptr_sub,sublen)==0)
		{
			return ptr_src-srcstr;
		}
		else
		{
			ptr_src++;
			ptr_sub=strchr(ptr_src,*substr); 
		}
	}
	return -1;
}
/*
void getNext(char p[],int next[],int strlen_t,int next_len)
{
	int j=0;
	int i=0;
	next[1]=0;
	
	while(i<strlen_t)
	{
		if(j==0 || p[i]==p[j])
		{
			i++;
			j++;
			next[i]=j;
		}
		else
		{
			j=next[j];
		}
	}
}
*/   
int main()
{
	printf("%s have %d length \n","hello",strlen_1("hello"));
	printf("substring in %d\n",My_strstr_1("hello i am a file","am"));
	printf("substring in %d\n",My_strstr_2("hello i am a file","am"));
}
