#include<stdio.h> 
#include<stdlib.h>
#include<string.h>

int main()
{
	char str[]={"hello world i am fine"};
	char* p=strtok(str," ");
	int i=5;
	while(i>0)
	{
		printf("%s\n",p);
		p=strtok(NULL," ");
		i--;
	}
	printf("%s",str);
	return 0;
}
