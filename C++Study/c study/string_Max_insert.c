#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main()
{
	char buff[128]={0}; 
	char Max[6]="(max)" ;
	fgets(buff,128,stdin);
	int memMax=0;
	int max=buff[0];
	int len=strlen(buff);
	int j=0;
	int k=0;
	int i=0;
	while(buff[i])
	{
		while(!isspace(buff[i]))
		{
			if(max<buff[i])
			{
				memMax=i;
			}
			i++;	
		}
		/*
		for(k=0;k<5;k++)
		{
			for(j=len;j>memMax;j--)
			{
				buff[j]=buff[j-1];
			}
			buff[i++]=Max[k];
		}
		*/
		printf("buff[%d]=%c",i,buff[memMax]);
		int index=memMax;//���´�ʱ����ַ���λ�� 
		for(k=0;k<5;k++)
		{
			for(j=len;j>memMax;j--)
			{
				buff[j]=buff[j-1];
			}
		}
		k=0;
		for(j=index+1;j<index+5;j++)
		{
			buff[j]=Max[k++]; 
		}
		i++;
		//��һ���ַ�����ʼ1 
		memMax=buff[i];
	}
	printf("%s",buff);
	
}
