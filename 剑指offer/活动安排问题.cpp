#include<iostream>


using namespace std;

const int NUM=50;
void GreedySelector(int n,int s[],int f[],bool b[])
{
	b[1]=true; //Ĭ�ϻ����һ����Ȱ��� 
	int j=1; //��¼���һ�μ���b�еĻ
	
	
	//һ�μ��I�͵�ǰѡ���Ƿ����� 
	for(int i=2;i<n;i++)
	{
		if(s[i]>f[j])
		{
			b[j]=true;
			j=i;
		}else b[i]=false;
	 } 
	 
		
} 
int main()
{
	int s[]={0,1,3,0,5,3,6,8,8,2,12};//��ʼʱ�� 
	int f[]={0,4,5,6,7,8,9,10,11,12,13,14};//����ʱ�� 
	bool b[NUM];  //�洢�����ŵı�� 
	int n=sizeof(s)/sizeof(s[0])-1;
	
	GreedySelect(n,s,f,b);  
	for(int i = 1; i <= n; i++)      //��������ŵĻ��ź����Ŀ�ʼʱ��ͽ���ʱ�� 
    {  
         if(b[i]) cout << "� " << i << " :" << "(" << s[i] << "," << f[i] << ")" <<endl;  
     }  
     return 0;  
} 
