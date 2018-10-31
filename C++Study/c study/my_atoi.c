#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
int my_atoi(const char *src)
{
	char *p = src;
	int tmp=0;
	while(*src){
		if(*src>'9' || *src<'0'){
			printf("you have an error input\n");
			retrun -1;
		}
		src++;
	}
	src=p; 
	while((*src>='0' && *src<='9') *src!='\0'){
		tmp=tmp*10+*src-'0';
		src++;
	} 

}
int main(){
	
} 
