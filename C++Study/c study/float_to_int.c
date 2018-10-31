#include<stdio.h>
#include<stdlib.h>

int My_float_to_int(float flvar)
{
  int iit=0;
  __asm{
  cvttss2si   eax,dword ptr [flvar];  
  mov         dword ptr [a],eax ;
  mov eax,dword ptr [iit];
  }
  return iit;


} 
int main()
{
    float flvar=5.12;
	printf("flvar to int =%d\n",My_float_to_int(flvar));
	 
}
