#include<stdio.h>
#include<malloc.h>
#include<fstream>
#include<iostream>
#include<string.h> 

using namespace std;
#define MAX 10000000
//��Ʒ�����0,1,2,3,4����
typedef struct{
//ÿ����Ʒ�ĵ���
  int price;
  //���蹺�����Ʒ������,1=<amount<=5
  int amount;
}Goods;


typedef struct{
  //��ϴ��������е���Ʒ������
  int kinds_num;
  //�����Ʒ���ܵ��Żݼ۸�
  int price;
  //��Ϸ����У�ÿ����Ʒ�ĵı�ź����� 
  int amount[5];
}Promote;


 int s;
 Goods goods[5];
 Promote *promote;
 int cost[6][6][6][6][6];


int mincost(int A,int B,int C,int D,int E);
int find_match(int c[],int num)
{
  int i=0;
  for(i=0;i<5;i++)
  {
    if(c[i]==num)
    return i;
  }
    return -1;
}


int main()
{ 
  int b;
  int i,j;
  int c[5];

  ifstream in("C:\\Users\\Lenovo\\Desktop\\CC++\\input.txt"); //���ʾ���ǲ����������ļ���input.txt)
  in>>b;
  for(i=0;i<5;i++)
  {
   if(i<b)
   {
    in>>c[i];
    in>>goods[i].amount;
    in>>goods[i].price;
   }
   else
   {
    c[i]=0;
    goods[i].amount=0;
    goods[i].price=0;
   }
   }

   ifstream in1("offer.txt");
   in1>>s;
   promote=new Promote[s];
   for(j=0;j<s;j++)
  {
   memset(&promote[j],0,sizeof(Promote));  //������promote[]�����Ա��һ��ֵ 
   in1>>promote[j].kinds_num;
   int num;
   for(i=0;i<promote[j].kinds_num;i++)
   {
   in1>>num;
   int index=find_match(c,num);
   if(index>=0)
   in1>>promote[j].amount[index];
   else {
   cout<<"data err"<<endl;
   exit(1);
   }
  }
   in1>>promote[j].price;
  }

  int res=mincost(goods[0].amount,goods[1].amount,goods[2].amount,goods[3].amount,goods[4].amount);
  cout<<"res is "<<res<<endl;
}


//����¼�����еݹ����
int mincost(int A,int B,int C,int D,int E)
{
  int i=0;
  int min=MAX;
  for(i=0;i<s;i++)
  {
  int A1=promote[i].amount[0];
  int B1=promote[i].amount[1];
  int C1=promote[i].amount[2];
  int D1=promote[i].amount[3];
  int E1=promote[i].amount[4];
  if(A>=A1&&B>=B1&&C>=C1&&D>=D1&&E>=E1)
   {
   if(min>cost[A-A1][B-B1][C-C1][D-D1][E-E1]+promote[i].price)
   {
      if(cost[A-A1][B-B1][C-C1][D-D1][E-E1]>0)
      min=cost[A-A1][B-B1][C-C1][D-D1][E-E1]+promote[i].price;
      else min=mincost(A-A1,B-B1,C-C1,D-D1,E-E1)+promote[i].price;
   }
  }else{

  if(min>A*goods[0].price+B*goods[1].price+C*goods[2].price+D*goods[3].price+E*goods[4].price)
  min=A*goods[0].price+B*goods[1].price+C*goods[2].price+D*goods[3].price+E*goods[4].price;
  }
  }
  cost[A][B][C][D][E]=min;
  return cost[A][B][C][D][E];
}


