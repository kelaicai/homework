#include<sdtio.h>
#include<ctype.h>
//������ķ�ʽ�򿪣�����ļ������ڣ�����һ����ָ�룬���򷵻�һ���ļ�ָ��
//�����д�ĵķ�ʽ�򿪣�����ļ����ڣ�����ļ���ǰ�����ݣ���д��
//                      ������ļ������ڣ��ȴ�������д��
/*
void main()
{
	FILE* fp=fopen("C:\\1.txt","r");
	FILE* fp2=fopen("C:\\2.txt","w");
	char ch;
	//fputc(ch,fp2);
	//strstr-->#include<sttring.h>
	//���ļ�ָ���ڶ�ȡһ���ļ����ļ�ָ���Զ�����ƶ���
        while((ch=fget(fp))!=EOF)
	{
		if(isupper(ch))
		{
			tolower(ch);
		}
             fputc(ch,fp2);	
	}
}
*/
//�����Ʋ���
void main()
{
   FILE *fr=fopen("");
   FILE *fw-fopen("");
   /*
   char ch;
   while((fread(&ch,1,1,fr))!=0)
   {
   	fwrite(&ch,1,1,fw);
   }*/
   /*
   while()
   {
   	fwrite(&ch,1,1024*1024*100,fw);	
   }
   */

   /*
    while()
   {
   	fwrite(&ch,1024*1024*100,1,fw);	
   }
   */
   
   /*
   int res;
   while((res=fread(&ch,1,1024*1024,fr)!=0)
  {
       fwrite(&ch,1,res,fw);		
  }
   */


   //fseek
   /* 
    
    fseek(fp,0,SEEK_END);  //��ȡ�ļ���С
   /*
  ftell(fp); //��������fp����λ������
  printf("%d",ftell(fp));
  */

   /*
    1.�ļ��ָ�ͺϲ� ���ɺ���
    */
}





