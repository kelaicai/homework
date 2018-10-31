#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
//�����һ��λɾ��
/*
ֱ������ 
*/
int delete_last_bit(int num)
{
	return ((num) >> 1);
}

//�����һ��λ��0   /*ֱ�����ƣ��Զ�����*/
int add_last_zero(int num)
{
	return ((num) << 1);
}

//�����һ��λ��1  /*�������ٻ�1*/ 
int add_last_one(int num)
{
	return (((num) << 1) | 1);
}

//�����һλ��Ϊ1  /*  ֱ�ӻ�1  */
int set_last_one(int num)
{
	return ((num) | 1);
}

//�����һΪ��Ϊ��    /* ������1���   */
int set_last_zero(int num)
{
	return ((num) ^ (1 << 0));
}

//�����һλȡ��    /*���������1*/
int set_last_last_con(int num)
{
	return ((num) ^ 1);
}

//����Nλ��1    /*����λ�Ǵ�0����λ����n-1λ  ����������������� n=0 �� ������0�����*/
int set_n_to_one(int num, int n)
{
	if(n==0)
	{
		return (num | 1);
	 } 
	return (num | 1<<(n-1));
}

//����Nλ��Ϊ��    /*�Ƚ�1Ų���ڵ�nλ*/
int set_n_to_zero(int num, int n)
{
	return ((num)& ~(1<<n));
}

//��������N��ȡ��
int set_n_to_con(int num,int n)
{
	if(n==0)
	{
		return num^1;
	 } 
	return  ((num) ^ (1 <<(n-1)));
}

//��������λ
int get_last_three(int num)
{
	return num& 7;
}


//��ȡĩβnλ
int get_last_n_bit(int num, int n)
{
	int i=0;
	int tmp=1;
	for(i;i<n;i++)
	{
		tmp=tmp*2;
	}
	return num &(tmp-1);
}
//��ȡ��Nλ
int get_n_bit(int num, int n)
{
	if(n==0)
	{
		return num&1;
	}
	return (num>>(n-1))&1;
}

//�������һ��0��Ϊ1
int seq_first_zero_to_one(int num)
{
	int tmp=num;
	int i=1;
	while(get_n_bit(num,i))
	{
		i++;
	}
	 num=set_n_to_one(num,i);
	return num;
}

//���ҿ�ʼ�����Ϊ1     
/*num��ʱ��Ȼ��ż��������˵2��n�η�������ǰһ����ȫ
һ������ ������ǰһ��ֵ �� ��������׽������1����*/ 
int seq_zero_to_one(int num)
{
	return (num | (num-1));
}

#define ENTER printf("\n");

//��������1��Ϊ0���ֽ������ȡ�ж��Ƿ���1��

/*���������Ƶģ�����ȫһ�����֣�һ�㶼��2��n�η�����һ���ԣ���������һ�����������㼴�ɽ������1��Ϊ0*/
int seq_one_to_zero(int num)
{
    
	return  num=num&(num+1);
}

int display_binary(int src)
{
	if (src == 0)
	{
		printf("0\n");
	}

	int binary[20], i;
	for (i = 0; src; i++)
	{
		binary[i] = src%2;
		src/= 2;
	}
	for (i = i - 1; i >= 0; i--)
	{
		printf("%d", binary[i]);
	}
	return 0;
}




//����һ������1�ĸ���
int count(int num)
{
  int count = 0;
  while(num != 0) 
  {
    num = num & (num-1);
    count++;
  }
  return count; 	
} 
void bit_operation( )
{


	printf("����    | ʵ��  | ����\n");
	printf("101101ȥ�����һλ         ");
	display_binary(delete_last_bit(45));
	ENTER
	
	printf("101101�����Ӹ�0          ");
	display_binary( add_last_zero(45));
	ENTER
	
	printf("101101�����Ӹ�1           ");
	display_binary(add_last_one(45));
	ENTER
	
    printf("101100(44)�����һ����Ϊ1   ");
	display_binary(set_last_one(44));
	ENTER

    printf("101101(45)�����һ����Ϊ0   ");
	display_binary(set_last_zero(45));
	ENTER
	
	printf("101101(45)�����һλȡ��    ");
	display_binary(set_last_last_con(45));
	ENTER
	
	printf("101001(41)��������k����Ϊ1 k=3    ");
	display_binary(set_n_to_one(41,3));
	ENTER
	
	printf("101001(45)��������k����Ϊ0 k=3    ");
	display_binary(set_n_to_zero(45,3));
	ENTER
	
	printf("101001(45)��������k����Ϊ0 k=3    ");
	display_binary(set_n_to_zero(45,3));
	ENTER
	
	printf("101001(41)��������k��λȡ�� k=3    ");
	display_binary(set_n_to_con(41,3));
	ENTER
	
	printf("1101101(109)��ȡ�����λ k=3       ");
	display_binary(get_last_three(109));
	ENTER
	
	printf("1101101(109)ȡĩβkλ k=5          ");
	display_binary(get_last_n_bit(109,5));
	ENTER
	
	printf("1101101(109)ȡ������kλ k=4        ");
	display_binary(get_n_bit(109,4));
	ENTER
	
	printf("100101111(303)��������1��Ϊ0         ");
	display_binary(seq_one_to_zero(303));
	ENTER
	
	printf("100101111(303)��������һ��0��Ϊ1         ");
	display_binary(seq_first_zero_to_one(303));
	ENTER
	
	printf("11011000(216)���ұ�������0��Ϊ1         ");
	display_binary(seq_zero_to_one(216));
	ENTER
	

}
int main()
{
	
	bit_operation();
	
	printf("\n");
	int cou=count(15);
	printf("15 has %d 1\n",cou);
	system("pause");


}

