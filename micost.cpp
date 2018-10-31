#include<stdio.h>
#include<stdlib.h>
#define N 5//ÿ����Ʒ���������
#define B 5//�����Ʒ������
#define S 99//�����Ż������
#define C 999//���ı��
//p104

/**
*B 0-5����Ʒ
*K 0-5ÿ����Ʒ����
*C 1-999��Ʒ���
*P 1-999��Ʒ��������
*S 0-99 �Ż����
*������ά���� cost(a,b,c,d,e)��ʾ������Ʒ a b c d e ��ϵ����ٻ���
*/

int cost[N+1][N+1][N+1][N+1][N+1]={0};//cost(a,b,c,d,e)��ʾ������Ʒ a b c d e ��ϵ����ٻ���.��1��ʼ
int offer[S][B+1];//�Ż������Ϣ
//offer[Si][Bj]  Si����е�Bj(��1��ʼ)����Ʒ������ offer[1..S][0]�洢������ϵĻ���

struct Purchase
{
	int code;//���
	int quatity;//Ҫ���������
	int price;//����
};
Purchase purch[B];//���幺����Ʒ��Ϣ����

int product[B]={0};//�洢��ǰ�ѹ������Ʒ����

int num[C]={-1};//code��ŵ���Ʒ��Ӧ����purch�����е�index

int b;//ʵ�ʹ������Ʒ����

int s;//ʵ�ʵ��Ż������

/*
*��ʼ������
*/
void init()
{
  FILE *kindandquatity;
  FILE *convenicecase;
  int i=0; 
  //***************************���´��ļ�******************************************
  kindandquatity=fopen("kindandquatity.txt","r");//open file

	if(kindandquatity==NULL)//open file error
	{
		printf("can't not open kindandquatity.txt!\n");
		exit(1);
	}

	convenicecase=fopen("convenicecase.txt","r");

	if(convenicecase==NULL)//open file error
	{
		printf("can't not open convenicecase.txt!\n");
		exit(1);
	}
//*******************************��ȡ���ݲ���ʼ��***********************************************

	//��0��ʼ��
	for(int i=0;i<N;++i)
	{
		purch[i].code=-1;
		purch[i].price=0;
		purch[i].quatity=0;
	}

	for(i=0;i<S;++i)
		for(int j=1;j<=B;++j)
		{
			offer[i][j]=0;
		}

	//�����ļ�����
	fscanf(kindandquatity,"%d",&b);//ʵ����Ʒ����

	for( i=0;i<b;++i)
	{
       fscanf(kindandquatity,"%d %d %d",&purch[i].code,&purch[i].quatity,&purch[i].price);//��Ʒ���� ���� ����
	   if(purch[i].quatity<0){
		   printf("����������޸��ļ��ڹ�����Ʒ��������Ϣ ������ҪΪ��");
		   break;
		   exit(-1);
	   }
	   num[purch[i].code]=i; //��Ʒ��Ŵ����num    

	}

	
	fscanf(convenicecase,"%d",&s);//ʵ�������
	for(i=0;i<s;++i)
	{
		int pairs;//����е���Ʒ��
		fscanf(convenicecase,"%d",&pairs);\
	 //  printf("pairs %d is%d",i,pairs);
		for(int j=0;j<pairs;++j)
		{
			int c;//��Ʒ���
			int n;//���i��c�����Ʒ������
			fscanf(convenicecase,"%d %d",&c,&n);
			offer[i][num[c]+1]=n;
		}

		fscanf(convenicecase,"%d",&offer[i][0]);//��ϵĻ���
	}

	//****************************���¹ر��ļ�************************************************
	fclose(kindandquatity);
	fclose(convenicecase);
}

/**
*������
*/
void printResult()
{
	FILE *out=fopen("mincost.txt","w");

	if(out==NULL)//open file error
	{
		printf("can't not open mincost.txt to write!\n");
		exit(1);
	}

	int mincost=cost[purch[0].quatity][purch[1].quatity][purch[2].quatity][purch[3].quatity][purch[4].quatity];
	printf("qu1%2d qu2%2d qu%2d qu%2d qu%2d\n",purch[0].quatity,purch[1].quatity,purch[2].quatity,purch[3].quatity,purch[4].quatity);
	printf("minCost=%d\n",mincost);
	fprintf(out,"%d",mincost);//д���ļ�

}



/**
* ��С�������������
*/

void minCost()
{
	int mincost=0;

	int quatity1;//�Ѿ�����ĵ�һ����Ʒ����
	int quatity2;
	int quatity3;
	int quatity4;
	int quatity5;

	for(int i=0;i<b;++i)
	{
		mincost+=product[i]*purch[i].price;//����С���ѳ�ʼΪû���Żݲ��ԵĻ���
		
	}
	printf("set1 %4d\n",mincost);

	//��s���Ż�������������
	for(int j=0;j<s;++j)
	{
		 quatity1=product[0]-offer[j][1];//��һ����Ʒ�۳���ǰ�Ż�����µĹ�����������������
		 quatity2=product[1]-offer[j][2];
		 quatity3=product[2]-offer[j][3];
		 quatity4=product[3]-offer[j][4];
		 quatity5=product[4]-offer[j][5];
       printf("j:%2d  %8d %8d %8d %8d %8d\n",j,quatity1,quatity2,quatity3,quatity4,quatity5);
		if(quatity1>=0&&quatity2>=0&&quatity3>=0&&quatity4>=0&&quatity5>=0
			&&cost[quatity1][quatity2][quatity3][quatity4][quatity5]+offer[j][0]<mincost)//�ڵ�ǰ�Ż�����£��������Ʒ���ܻ��ѱ�û���Ż����ߵ���
			{
			printf("��������j:%2d  %8d %8d %8d %8d %8d\n",j,quatity1,quatity2,quatity3,quatity4,quatity5);
			mincost=cost[quatity1][quatity2][quatity3][quatity4][quatity5]+offer[j][0];//�������ǰ���ܻ��ѣ�����������ϵĻ���
		    printf("��������ʱcost�����Ӧֵ %5d \n",cost[quatity1][quatity2][quatity3][quatity4][quatity5]);
			printf("��������ʱoffer�����Ӧֵ %5d \n",offer[j][0]);
			printf("*******j:%8d******mincosttmep:%d:\n",j,mincost);
	}
   }
	cost[product[0]][product[1]][product[2]][product[3]][product[4]]=mincost;//������������ϻ���
	printf("qu%2d qu%2d qu%2d qu%2d qu%2d\n",purch[0].quatity,purch[1].quatity,purch[2].quatity,purch[3].quatity,purch[4].quatity);
	printf("-----------------min%4d--------------",mincost);

}

/*���ڵ�i����Ʒ,���i���������Ʒ����b-1ʱ�������ʱ��ϵ���С����
*/

void combination(int i)//i����Ʒ
{
    if(i>=b){ minCost(); 
	printf("test combination and mincost\n");
	return;}//ȷ��һ�������⣬����һ�ε�ǰ��С����

	for(int j=0;j<=purch[i].quatity;++j)// 0 0�� 0 1�� 1 0�� 1 1�� 1 2 ��2 0 ��2 1�� 2 2������
	{
       product[i]=j; //��¼��i����Ʒ��������j�����
	   combination(i+1);
	}
}

void print(){
    int i=0;
    int j=0;
    printf("the offer array is��\n");
    for(i=0;i<2;i++){
    	for(j=0;j<3;j++){
    		printf("%12d",offer[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	init();
	combination(0);//�ӵ�0����Ʒ��ʼ
	printResult();
	print();
	system("pause");
	
 return 0;
}
