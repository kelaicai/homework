#include<stdio.h>
#include<stdlib.h>
#define N 5//每种商品的最大数量
#define B 5//最大商品种类数
#define S 99//最大的优惠组合数
#define C 999//最大的编号
//p104

/**
*B 0-5种商品
*K 0-5每种商品数量
*C 1-999商品编号
*P 1-999商品正常单价
*S 0-99 优惠组合
*定义五维数组 cost(a,b,c,d,e)表示购买商品 a b c d e 组合的最少花费
*/

int cost[N+1][N+1][N+1][N+1][N+1]={0};//cost(a,b,c,d,e)表示购买商品 a b c d e 组合的最少花费.从1开始
int offer[S][B+1];//优惠组合信息
//offer[Si][Bj]  Si组合中的Bj(从1开始)类商品的数量 offer[1..S][0]存储这种组合的花费

struct Purchase
{
	int code;//编号
	int quatity;//要购买的数量
	int price;//单价
};
Purchase purch[B];//定义购买物品信息数组

int product[B]={0};//存储当前已购买的商品数量

int num[C]={-1};//code编号的商品对应的在purch数组中的index

int b;//实际购买的商品种类

int s;//实际的优惠组合数

/*
*初始化数据
*/
void init()
{
  FILE *input;
  FILE *offerFile;
  int i=0; 
  //***************************以下打开文件******************************************
  input=fopen("input.txt","r");//open file

	if(input==NULL)//open file error
	{
		printf("can't not open input.txt!\n");
		exit(1);
	}

	offerFile=fopen("offer.txt","r");

	if(offerFile==NULL)//open file error
	{
		printf("can't not open offer.txt!\n");
		exit(1);
	}
//*******************************读取数据并初始化***********************************************

	//置0初始化
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

	//读入文件数据
	fscanf(input,"%d",&b);//实际商品种类

	for( i=0;i<b;++i)
	{
       fscanf(input,"%d %d %d",&purch[i].code,&purch[i].quatity,&purch[i].price);//商品编码 数量 单价
	   num[purch[i].code]=i;
	}

	
	fscanf(offerFile,"%d",&s);//实际组合数
	for(i=0;i<s;++i)
	{
		int pairs;//组合中的商品数
		fscanf(offerFile,"%d",&pairs);
		for(int j=0;j<pairs;++j)
		{
			int c;//商品编号
			int n;//组合i中c编号商品的数量
			fscanf(offerFile,"%d %d",&c,&n);
			offer[i][num[c]+1]=n;
		}

		fscanf(offerFile,"%d",&offer[i][0]);//组合的花费
	}

	//****************************以下关闭文件************************************************
	fclose(input);
	fclose(offerFile);
}

/**
*输出结果
*/
void printResult()
{
	FILE *out=fopen("output.txt","w");

	if(out==NULL)//open file error
	{
		printf("can't not open output.txt to write!\n");
		exit(1);
	}

	int mincost=cost[purch[0].quatity][purch[1].quatity][purch[2].quatity][purch[3].quatity][purch[4].quatity];
	printf("minCost=%d\n",mincost);
	fprintf(out,"%d",mincost);

}



/**
* 最小花费子问题求解
*/

void minCost()
{
	int mincost=0;

	int quatity1;//已经购买的第一种商品的量
	int quatity2;
	int quatity3;
	int quatity4;
	int quatity5;

	for(int i=0;i<b;++i)
	{
		mincost+=product[i]*purch[i].price;//将最小花费初始为没有优惠策略的花费
	}

	//对s种优惠政策依次讨论
	for(int j=0;j<s;++j)
	{
		 quatity1=product[0]-offer[j][1];//第一种商品扣除当前优惠组合下的购买量的其它购买量
		 quatity2=product[1]-offer[j][2];
		 quatity3=product[2]-offer[j][3];
		 quatity4=product[3]-offer[j][4];
		 quatity5=product[4]-offer[j][5];

		if(quatity1>=0&&quatity2>=0&&quatity3>=0&&quatity4>=0&&quatity5>=0
			&&cost[quatity1][quatity2][quatity3][quatity4][quatity5]+offer[j][0]<mincost)//在当前优惠组合下，购买的商品的总花费比没有优惠政策的少
			mincost=cost[quatity1][quatity2][quatity3][quatity4][quatity5]+offer[j][0];//购买组合前的总花费，加上这种组合的花费
	}

	cost[product[0]][product[1]][product[2]][product[3]][product[4]]=mincost;//子问题最优组合花费

}


void combination(int i)//i类商品
{
    if(i>=b){ minCost(); return;}//确定一个子问题，计算一次当前最小花费

	for(int j=0;j<=purch[i].quatity;++j)// 0 0， 0 1， 1 0， 1 1， 1 2 ，2 0 ，2 1， 2 2。。。
	{
       product[i]=j;
	   combination(i+1);
	}
}



int main()
{
	init();
	combination(0);//从第0种商品开始
	printResult();
 return 0;
}
