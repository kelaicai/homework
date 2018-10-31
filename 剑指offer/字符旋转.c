#include<stdio.h>
#include"string.h"
/*
void reverse_string(char str[],int size)
{
	if(str==NULL)	
	{
		return ;
	}
	
	for(int i=0,j=len-1;i<j;i++,j--)
	{
		swap(str,i,j);	
	} 
}
*/

void swap(char str[],int i,int j)
{
	char ch=str[i];
	str[i]=str[j];
	str[j]=ch;
}

void foreword_star(char str[])
{
	if(str==NULL)  return ;
	int len=strlen(str); 
	int i=len-1,j=len-1;
	
	while(i>=0)
	{
		if(str[i]!='*')
		{
			swap(str,i,j);
			i--;
			j--;
		}
		else
		{
			i--;
		}
	}
}
int main()
{
	char str[]="abc***cd**ef*";
	foreword_star(str);
	printf("%s\n",str);
	return 0;
} 
