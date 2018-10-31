#include <stdio.h>
int main(void)
{
	int i, n = 2,j=0;
	printf("请输入一个数：\n");
//	scanf("%d", &i);
	for(j=2;j<100;j++){
	while (1)
	{
		n=2;
		if (j%n == 0)
		{
			continue;
		}
		n++;
	}
	if (n == j)
	{
		printf("这个%d数是素数!",j);
	}
	else
	{
		printf("这个%d不是素数！",j); 
	}
}
	return 0;
}
