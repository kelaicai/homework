#include<stdio.h>

#include<stdlib.h>
int main(){
	int num1=100,num2=0;
	if(num2==0){
		printf("被除数不能为0，出错文档为 %s，出错在函数 %s,出错在第%d行",_FILE_,_FUNCTION_,_LINE_);
	}
	return 0;
} 
