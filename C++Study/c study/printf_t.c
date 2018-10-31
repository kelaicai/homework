#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<assert.h>
#include<string.h>
#include<ctype.h>
#include<unistd.h>
//自定义printf函数 
/*
  从name参数开始扫描，当扫描到%d时，对后面紧跟的字符进行选择，然后使用对应类型tmp_type临时量从va_arg(arg_arg,type)
  接收对应的量，并做对应的打印处理，如char直接打印，int类型需要转化为ASCII码，string要注意读取从str(接收量)到\0的
  数据并且逐个打印。最后还有记得将用于访问可变参数列表的指针(va_list定义的指针)置为NULL，即va_end. 
*/
void My_prinf(char *name,...);

//数字转英文表示 
/*
  由于英语使用的是三位点分十进制的表示方法，所以第一步就是应该对数据（inum/1000）取 出百位上的数(ivar)，添加houndred，然后 
  取十位上的数字，添加teenty[ivar/10-1],并取个位上的数ivar%=10; 添加对应数据base[ivar].当然这个过程是反向的的，因此考虑
  递归，每次除以1000，最后esp回调的时候， 都会将对应位上的数据对应的单词放上去 
   
*/
char* Write_count(int inum);


char *base[]={"zero","one","tow","three","four","five","six","seven","eight","nine","eleven","twelve","thridteen",
"fourtenn","fiften","sixteen","seventeen","eighteen","nineteen"};
char *tenty[]={" ","twenty","thity","fouty","fifty","sixty","seventy","eight","ninty"}; 
char *lion[]={" ","hundred","thousand","million"} ;


void Componet_one(int inum,char *buff,char **lion_a);

//逆转 
void Revese(char *buff,int n,int m);
//单词逆转 
void Revese_interface(char *buff); 



int main()
{ 
   My_prinf("i am %s %d %f","abd",2,0.5);
   Write_count(1255);
} 

void My_prinf(char *name,...)
{
	assert(name!=NULL);
	
	va_list va_arg;   //此处的va_arg是一个变量，与宏va_arg不同在于：它在栈空间开辟内存
	                  //而va_arg宏是在预编译时就被替换为对应的代码，所以二者在程序中没有发生符号冲突 
	
	int count=0;
	
	char *p=name;
	
	 int tmp_c=0;         //接收char 
	 int tmp_i=0;       //接收ar_arg读取的Int类型数据 
	 double tmp_d=0.0;   // 
	 char *ptmp_s=NULL;
	//初始化，使得plist指向name的第一个元素 
	va_start(va_arg,name);
	//逐个访问 
	while(*name)
	{ 
	    if(*name == '%')             
	    {	
			switch(*++name)      //注意在每次匹配结束后都应该将name向后挪动 
			{                    //从编译器行为来看，在可变参数条件下，char会提升为int，float会提升为double 
				
			case 'c':
	                tmp_c=va_arg(va_arg,int);
					 putchar((char)tmp_c);
					 ++name; 
					 break;
					 
			case 'd':
					  tmp_i=va_arg(va_arg,int);
					  putchar(tmp_i+'0');
					  ++name;
					  break;
					  
			case 'f':
					  tmp_d=va_arg(va_arg,double);
					  char buff[15]={0};
					  sprintf(buff,"%lf",tmp_d);
					  puts(buff);
					  ++name; 
					  break;
					  
			case 's':
					 ptmp_s=va_arg(va_arg,char*); 
					 for(ptmp_s;*ptmp_s!='\0';ptmp_s++)
					 {
					 	putchar(*ptmp_s); 
					 }
					 ptmp_s=NULL;
					 ++name; //到下一个元素的位置 
			          break;
					 
			     default:break;
			}
       	}  
	    else
     	{
     	putchar(*(name++));  //未匹配的字符原样打印 
		continue;
	    }
    }
    va_end(va_arg);
}

char* Write_count(int inum)
{
	char buff[256]={0};
	if(inum==0)
	{
		return base[0];
	}
	else
	{
		Componet_one(inum,buff,lion);
	}
	
	printf("buff =%s",buff);
	return NULL;
}

void Componet_one(int inum,char *buff,char **lion_a)
{
	int ivar=inum/1000;
	
	if(ivar>0)
	{
 		Componet_one(ivar,buff,lion_a+1);	
	}
	
	int index=ivar%1000;  //8563%1000=500 
	ivar=inum/100;   //563/100=5
	
	if(ivar>0)
	{
		strcat(buff,base[ivar]); 
		strcat(buff," ");
		strcat(buff,lion[1]);   //百位 
		strcat(buff," ");
	} 
	
	ivar=inum%100;  //563%100=63
	if(ivar>20)
	{
		strcat(buff,tenty[ivar/10-1]);
		strcat(buff," ");
		ivar%=10;
	}
	
	if(ivar>0)
	{
		strcat(buff,base[ivar]);
		strcat(buff," ");	
	}
	
	if(inum>0)
	{
		strcat(buff,*lion_a) ;
		strcat(buff," ");
	} 

} 

//二级指针为什么不可以指向二维数组&arr???
/*
	Y原因在于：它们的类型不同，加入有int arr[3][5],int **p，p是指向int*字节的指针，而&arr是数组类型的，具体来讲
	就是说它是sizeof(arr)字节的指针类型，所以二者的类型不同，就不满足赋值条件，因此就不能指向二维数组 （如果此说法不妥当希望老师提出了） 
*/ 


