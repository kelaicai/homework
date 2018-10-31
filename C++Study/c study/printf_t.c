#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<assert.h>
#include<string.h>
#include<ctype.h>
#include<unistd.h>
//�Զ���printf���� 
/*
  ��name������ʼɨ�裬��ɨ�赽%dʱ���Ժ���������ַ�����ѡ��Ȼ��ʹ�ö�Ӧ����tmp_type��ʱ����va_arg(arg_arg,type)
  ���ն�Ӧ������������Ӧ�Ĵ�ӡ������charֱ�Ӵ�ӡ��int������Ҫת��ΪASCII�룬stringҪע���ȡ��str(������)��\0��
  ���ݲ��������ӡ������мǵý����ڷ��ʿɱ�����б��ָ��(va_list�����ָ��)��ΪNULL����va_end. 
*/
void My_prinf(char *name,...);

//����תӢ�ı�ʾ 
/*
  ����Ӣ��ʹ�õ�����λ���ʮ���Ƶı�ʾ���������Ե�һ������Ӧ�ö����ݣ�inum/1000��ȡ ����λ�ϵ���(ivar)�����houndred��Ȼ�� 
  ȡʮλ�ϵ����֣����teenty[ivar/10-1],��ȡ��λ�ϵ���ivar%=10; ��Ӷ�Ӧ����base[ivar].��Ȼ��������Ƿ���ĵģ���˿���
  �ݹ飬ÿ�γ���1000�����esp�ص���ʱ�� ���Ὣ��Ӧλ�ϵ����ݶ�Ӧ�ĵ��ʷ���ȥ 
   
*/
char* Write_count(int inum);


char *base[]={"zero","one","tow","three","four","five","six","seven","eight","nine","eleven","twelve","thridteen",
"fourtenn","fiften","sixteen","seventeen","eighteen","nineteen"};
char *tenty[]={" ","twenty","thity","fouty","fifty","sixty","seventy","eight","ninty"}; 
char *lion[]={" ","hundred","thousand","million"} ;


void Componet_one(int inum,char *buff,char **lion_a);

//��ת 
void Revese(char *buff,int n,int m);
//������ת 
void Revese_interface(char *buff); 



int main()
{ 
   My_prinf("i am %s %d %f","abd",2,0.5);
   Write_count(1255);
} 

void My_prinf(char *name,...)
{
	assert(name!=NULL);
	
	va_list va_arg;   //�˴���va_arg��һ�����������va_arg��ͬ���ڣ�����ջ�ռ俪���ڴ�
	                  //��va_arg������Ԥ����ʱ�ͱ��滻Ϊ��Ӧ�Ĵ��룬���Զ����ڳ�����û�з������ų�ͻ 
	
	int count=0;
	
	char *p=name;
	
	 int tmp_c=0;         //����char 
	 int tmp_i=0;       //����ar_arg��ȡ��Int�������� 
	 double tmp_d=0.0;   // 
	 char *ptmp_s=NULL;
	//��ʼ����ʹ��plistָ��name�ĵ�һ��Ԫ�� 
	va_start(va_arg,name);
	//������� 
	while(*name)
	{ 
	    if(*name == '%')             
	    {	
			switch(*++name)      //ע����ÿ��ƥ�������Ӧ�ý�name���Ų�� 
			{                    //�ӱ�������Ϊ�������ڿɱ���������£�char������Ϊint��float������Ϊdouble 
				
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
					 ++name; //����һ��Ԫ�ص�λ�� 
			          break;
					 
			     default:break;
			}
       	}  
	    else
     	{
     	putchar(*(name++));  //δƥ����ַ�ԭ����ӡ 
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
		strcat(buff,lion[1]);   //��λ 
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

//����ָ��Ϊʲô������ָ���ά����&arr???
/*
	Yԭ�����ڣ����ǵ����Ͳ�ͬ��������int arr[3][5],int **p��p��ָ��int*�ֽڵ�ָ�룬��&arr���������͵ģ���������
	����˵����sizeof(arr)�ֽڵ�ָ�����ͣ����Զ��ߵ����Ͳ�ͬ���Ͳ����㸳ֵ��������˾Ͳ���ָ���ά���� �������˵�����׵�ϣ����ʦ����ˣ� 
*/ 


