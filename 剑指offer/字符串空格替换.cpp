#include<iostream>

using namespace std; 

class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str==NULL || length<0) return ;
       
        int oldlength=0;
        int blanknum=0;
        char* p=str;
        
        for(;*p!='\0';++p)
        {
            if(*p==' ')
            {
                blanknum++;
            }
            oldlength++;
        }
    
        int newlength=oldlength+2*blanknum;
        if(newlength>length) return ;
     
        
        while(oldlength>=0)
        {
            if(str[oldlength]==' ')
            {
                str[newlength--]='0';
                str[newlength--]='2';
                str[newlength--]='%';
        		oldlength--;
            }
            else
            {
          	  str[newlength--]=str[oldlength--];
           }
        }
	}
};

int main()
{
	Solution s;
	char str[]="ab cd sef";
	s.replaceSpace(str,sizeof(str));
	puts(str);	
} 
1 /boot  -->>存放系统启动的引导程序                              
  2 /etc  -->通常放置系统的配置文件                                
  3 /mnt   --> 对外提供挂载功能的临
  



