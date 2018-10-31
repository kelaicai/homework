/*

*/
#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
int divide_num = 3;
void divide()
{
	FILE *file_source = fopen("C:\\aaa.flv", "rb");
	assert(file_source!=NULL);
	FILE* file_div[3] = {NULL};
    int i = 0;
	fseek(file_source, 0L, SEEK_END);
	long real_len = ftell(file_source);
	assert(real_len != 0);
	printf("real_len=%Ld\n",real_len);
	
	
	file_div[0] = fopen("c:\\aa_part0.flv", "wb");
	file_div[1] = fopen("c:\\aa_part1.flv", "wb");
	file_div[2] = fopen("c:\\aa_part2.flv", "wb");

	rewind(file_source);
	printf("ftell=%Ld\n", ftell(file_source));
	printf("malloc=%Ld\n", 1024 * 1024 * 700);
	int res ;
	char* ch=(char *)malloc(1024*1024*700);
	assert(ch!=NULL);
	long n = real_len / 3;
	printf("n=%d\n",n);

	while ((res = fread(ch,1, n, file_source))!=0 && i<3)
	{
		printf("res=%d\n", res);
		if(res<n)
		{
			fwrite(ch, 1,real_len-ftell(file_source) , file_div[i]);
		}
		 else 
		 {
		    printf("file_source=%d\n", ftell(file_source));
	    	fwrite(ch, 1, n, file_div[i]);
	     }
	     i++;
	}
	//assert(res != 0);
	/*for (i = 0; i < 3; i++)
	{
		while ((res = fread(ch, 1,n, file_source)) != 0)
		{
			fwrite(ch, 1, res, file_div[i]);
		}
		assert(res!=0);
	}*/
	printf("end\n");
	//for (i = 0; i < 3; i++)
	//{
	//	fclose(file[i]);
 //   }
}

int main()
{

 divide();
 getchar();
	

}
