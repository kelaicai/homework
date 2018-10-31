#include<stdio.h>
#include<stdlib.h>

#if 0
static int count=0;
void my_string(char *start,int i)
{
	  //递归交换首字母和后面的字符
	  count++;
	  char tmp;
	  if(start[count]!='\0')
	  {
	  	for(start[count];start[i]!='\0';i++)
	  	{
	  	tmp=start[count];
	  	start[count]=start[i];
	  	start[i]=tmp;
	  	printf("now start = %s\n",start);
	  	my_string(start,i+1);
	    tmp=start[count];
	    start[count]=start[i];
	    start[i]=tmp;
	    } 
	  }
	  else
	  {
	     return ;
	  }
    
} 

#endif
void my_sort_string(char *pstr,char *p_begin)
{
	if(!p_begin)
	{
		printf("pstr=%s",pstr);
	}
	else
	{
		char *p_ch=NULL;
		char tmp;
		for(p_ch=p_begin;*p_ch!='\0';p_ch++)
		{
			
			tmp=*p_begin;
			*p_begin=*p_ch;
			*p_ch=tmp;
			my_sort_string(pstr,p_begin+1);
			tmp=*p_ch;
			*p_ch=*p_begin;
			*p_begin=tmp; 
			printf("pstr=%s\n",pstr);
			puts("\n");
		}
	}
}
void my_judge(char *pstr)
{
	if(pstr!=NULL)
	  {
	  	my_sort_string(pstr,pstr);
	  }
}
int main()
{
	char str1[]="abc";
	my_judge(str1);
	return 0;
} 
