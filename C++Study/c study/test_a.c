  #include<iostream>
   #include<stdio.h>
  #include<stdlib.h>
  #include<assert.h>
  #include<string.h>
  #include<unistd.h>
  int main()
  {   
      fork();
      int sid=getsid(0);
      int gid=getpgid(0);
     printf("pid=%d gpid=%d id=%d\n",getpid(),gid,sid);
 }
