#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
int my_strlen(char *str)
{
	if(*str==0)
	{
		return 0;
	}
	else
	{
		return	my_strlen(++str)+1;
	}
}
//欠缺在于没有考虑内存重叠 
void *MyMemcopy(void *des,void* src,int count)
{
	assert(des!=NULL && src!=NULL);
		void *ret=des;
		while(count--)
		{
			*(char*)des=*(char*)src;
			des=(char*)des+1;
			src=(char*)src+1;
		}
		return ret;
}
 //strcnmp() +strchr
int My_strstr3(char srcstr[],char substr[])
{
	int i=0;
	int j=0;
	char *ptr_src=srcstr;
	char *ptr_sub=substr;
	int srclen=my_strlen(ptr_src);
	int sublen=my_strlen(ptr_sub);
	
	while(*ptr_src!='\0' || ptr_sub!=NULL)
	{
	
		if(strncmp(ptr_src,ptr_sub,sublen)==0)
		{
			return ptr_src-srcstr;
		}
		else
		{    //在主串中寻找子串中第一个字符出现的位置 
			ptr_src=strchr(ptr_src,*substr); 
		}
	}
	return -1;
} 
//strncmp 
int My_strstr2(char* srcstr,char *substr)
{
	assert(srcstr!=NULL && substr!=NULL);
	int i=0;
	int j=0;
	char *ptr=srcstr;
	int len=my_strlen(substr);
	
	while(*ptr!='\0')
	{
			if(strncmp(ptr,substr,len)==0)
			{
				return ptr-srcstr;
			}
			ptr++;
	}
	return -1;	
} 

//暴力匹配 
int My_strstr(char *srcstr,char *substr)
{
	assert((srcstr!=NULL) && (substr!=NULL));
	int srclen=my_strlen(srcstr);
	int sublen=my_strlen(substr);
	int i=0;
	int j=0;
	int flag=0;
    for(i=0;i<srclen;i++)
    {
    	for(j=0;j<sublen;j++)
    	{
    		if(srcstr[i+j]==substr[j])
    		{
    			flag++;
			}
			else
			{
				continue;
			}
		}
		if(flag==sublen)
		{
			return i;
		}
		flag=0;
	}
    	return -1;

}
int main()
{
	char p[]="hello i ma hekl hi youki";
	char p2[20]={0};
	
   printf("%d\n",My_strstr(p,"ma"));
   printf("%d\n",My_strstr2(p,"hek"));
   printf("%d\n",My_strstr3(p,"youki"));
  /* 
   int len=sizeof(p); 
   MyMemcopy(p2,p,len);
   printf("%s",p2);
   */
  
}
