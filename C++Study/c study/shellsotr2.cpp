#include<stdio.h>
#include<stdlib.h>
void Core(int len, int * brr)//����,���ѷֺã���������������ζ���Ҫ�����������з���
{
	int step = (len / 3) + 1;
	for (int i = 0; i < len; i++)
	{
		brr[i] = 0;
	}
	int j = 0;
	while (step / 2 != 0)
	{
		brr[j] = step;
		step = step / 2;
		++j;
	}
	brr[j] = 1;
	j = 0;
	while (brr[j] != 0)
	{
		printf("%d ", brr[j]);
		j++;
	}
	printf("\n");
}
int Pcorenum(int *brr, int len, int i)// ÿ���ж��ٸ�Ԫ��
{
	int step = brr[i];
	float ft = (float)len / (float)step;
	int n = len / step;
	int Corenum = 0;
	if (n == ft)//����
	{
		Corenum = n;
	}
	else//��������
	{
		Corenum = n + 1;
	}
	return Corenum;
}
void Insert_Sort(int *arr, int len, int *brr, int i)//���뷨����
{
	int n = Pcorenum(brr, len, i);// ÿ���ж��ٸ�Ԫ��
	int m = brr[i];//�ֶ�����
	printf("����%d��\n", m);
	printf("ÿ����%d��Ԫ��\n", n);
	for (int k = 0; k < n; ++k)
	{
		for (int i = k; i < len - 3; i = i + n)
		{
			if (arr[i] > arr[i + n])
			{
				int tmp = arr[i + n];
				arr[i + n] = arr[i];
				arr[i] = tmp;
			}
			for (int j = i; j > 0; j = j - n)
			{
				if (arr[j] < arr[j - n])
				{
					int tmp = arr[j - n];
					arr[j - n] = arr[j];
					arr[j] = tmp;
				}
			}
		}
	}
}

void Sort(int *arr, int *brr, int len, int i)
{
	Insert_Sort(arr, len, brr, i);//���뷨����
}

void Show(int arr[], int len)//��ӡ����
{
	for (int i = 0; i < len; ++i)
	{
		printf("%d  ", arr[i]);

	}
	printf("\n");
}
int main()
{
	int arr[] = { 12,45,23,0,89,72,56,7,31,65 ,23,4,78,9,6,45,36,7,8,15,20,65 };
	const int len = sizeof(arr) / sizeof(arr[0]);
	//int brr[len];
	int *brr=(int*)malloc(len*sizeof(int));/*��̬����һ�����飬��Ϊ�������ݸ�Core���������������ʲôԭ��*/
	Core(len, brr);
	Show(arr, len);
	Sort(arr, brr, len, 0);
	Show(arr, len);
}


