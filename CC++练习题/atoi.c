#include<stdio.h>
#include<math.h>
int myAtoi( char *src)
{
	int num=0;
	int Negative=0;
	int n=0;
	
	char *p=src;
	
	if(p==NULL)   //���ж��ǲ��ǿմ� 
	{
		return -1;	
	} 
	while(*p++) //���ǿմ����㳤�� 
	{
		n++;;
	}
	
	p=src;  
	while(p[0]=='-')   //�ж����� 
	{
		Negative=-1;
	 } 
	 
	 char tmp='0';
	 
	 int i=0;
	 for(i=0;i<n;i++)
	 {
	 	char temp=*p++;
		if(temp>'9' || temp<'0' )
		{
			continue;  //�˹����Ϸ��ַ�		
		}
       if(num!=0 || temp!='0')	
       {
       	temp-=0x30;
       	num+=temp*(int)(pow(10,n-1-i)) ;
	   }
	 }  
	 
	 if(Negative)
	 {
	 	return (0-num);
	 }
	 else
	 {
	 	return num;
	} 
}

int main() 
{
	printf("12345=%d",myAtoi("12345"));
}
