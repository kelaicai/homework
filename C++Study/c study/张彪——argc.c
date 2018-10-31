#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void stringToLower(char *src)
{
	int i=0;
	while(src[i])
	{
		if(isupper(src[i]))
		{
			tolower(src[i]);
		}
		i++;
	}
}

void stringToUper(char *src)
{
	int i=0;
	while(src[i])
	{
		if(islower(src[i]))
		{
			toupper(src[i]);
		}
		i++;
	}
}

void  tranferAfter(int argc,int choise,char *src[],char *buff[])
{
	int i=0;
	for(i=2;i<argc;i++)
	{
		if(choise==1)   //表明是要转换成小写 
		{
			stringToLower(buff[i])	;
		}
		else
		{
			stringToUper(buff[i]);
		} 
	} 	
}

void display(char* buff[],int len)
{
	int i=2;
	for(;i<len;i++)
	{
		printf("%s      ",buff[i]);
	}
}
int main(int argc,char* argv[])
{
	printf("argc= %d\n",argc);	
	int i=2;
	char* buff[64]={0};
	for(i=0;i<argc;i++)
	{
		//argv[0]是默认的当前路径 
		printf("argv[%d]= %s\n",i,argv[i]);
		if((strcmp(argv[1],"-P"))==0) 
		{
			printf("%s\n",argv[1]);
		}
		else if((strcmp(argv[1],"-L"))==0)
		{
		    tranferAfter(argc,1,argv,buff);
			display(buff,argc-2);
		}
		else if((strcmp(argv[1],"U"))==0)
		{
			tranferAfter(argc,2,argv,buff);
			display(buff,argc-2);
		}
		else
		{
			printf("您的输入有误\n");
			continue;
		}
	}
}
