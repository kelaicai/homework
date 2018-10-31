#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
     int i=0;
	char string[100];
	FILE *file=fopen("test.txt","w");
	if(file==NULL) {
	printf("can't open the file'");
    exit(0);	
	}
	printf("input a string\n");
	gets(string);
	while(string[i]!='!'){
		if(string[i]>'a'&&string[i]<'z')
		string[i]=string[i]-32;
		fputc(string[i],file);
		i++;
	}
		fclose(file);
		file=fopen("test.txt","r");
		fgets(string,strlen(string)+1,file);
		printf("%s\n",string);
		fclose(file);
		system("pause");
		return 0;
}

 
