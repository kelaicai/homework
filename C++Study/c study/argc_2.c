#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<ctype.h>

#define TRANSFER(arg,argv)  for(j=2;j<argc;j++)	{	stringToLower(argv[j]);	printf("%s\n",argv[j]);	}

void stringToLower(char *src)
{
	int i=0;
	while(src[i])
	{
		if(isupper(src[i]))
		{
		//	tolower(src[i]);  tolower函数不起作用？？？ 
			src[i]+=32;
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
			src[i]-=32;
		}
		i++;
	}
}

int main(int argc,char *argv[])
{
	if(argc<0)
	{
		perror("no input arguments");
	}
	int j=0;
	printf("argc=%d\n",argc);
	for(;j<argc;j++)
	{
		
		printf("argv[%d] %s\n",j,argv[j]);	
	}
	
	int i=0;
	for(i=0;i<argc;i++)
	{
		if((strcmp(argv[1],"-P")==0))
		{
			int j=0;
			for(j=2;j<argc;j++)
			{
				printf("%s\n",argv[2]);
			}
			break;
		}
		if((strcmp(argv[1],"-L"))==0)
		{
			TRANSFER(argc,argv);
			break;
		} 
		if((strcmp(argv[1],"-U"))==0)
		{
			TRANSFER(argc,argv);
			break;
		}
		else
		{
			perror("argument error");
		}
	}
	return 0;
}
