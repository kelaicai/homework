#include<stdio.h>
#include<stdlib.h> 
#if 0
void* my_memcpy(void* src,void *dec,int count)
{
	if(src==NULL || dec==NULL)
	{
		return NULL;
	}
	void* ret=NULL;
	while(count--)
	{
		*(char*)dec=*(char*src);
		dec=(char*)dec+1;
		src=(char*)src+1;
	}
	return ret;
}
#endif
struct s_u
{
	union  //8          //8   //64
	{
		double ua[8];
		int ub;
	};
	struct c    //8
	{
		char s_a;
		int s_b; 
	};
	int a;  
	char b;  //8     //64+8+8=80
//	double c;  //8

};
int main()
{
	printf("%d",sizeof(struct s_u));
}
