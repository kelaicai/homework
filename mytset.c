#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int i=0;
	FILE *P=fopen("mytest.txt","w");
	char a[100];
	if(P==NULL)
	{
	puts("cant't open file");
    exit(0); 
	}
	printf("please input a number");
	gets(a);
	while(a[i]!='0'){
		if(a[i]>='a'&&a[i]<='z'){
			a[i]=a[i]-32;
		}
		fputc(a[i],P);
		i++;
	}
	fclose(P);
	P=fopen("mytest.txt","r");
	fgets(a,strlen(a)+1,P);
	printf("%s",a);
	fclose(P);
	return 0;
} 
