#include<stdio.h>
#include<string.h>
int main(){
	char a[10];
	char b[10];
	char buff[10];
	gets(a);
	gets(b);
	strcpy(buff,a);
	strcpy(a,b);
	strcpy(b,buff);
	puts(a);
	puts(b);
}
