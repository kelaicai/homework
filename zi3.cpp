#include <stdio.h>
int main(void)
{
	int i, n = 2,j=0;
	printf("������һ������\n");
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
		printf("���%d��������!",j);
	}
	else
	{
		printf("���%d����������",j); 
	}
}
	return 0;
}
