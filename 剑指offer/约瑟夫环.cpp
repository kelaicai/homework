#include<iostream>
#include<stdlib.h>
int N;
int M; 
using namespace std;

int main()
{
	int man[N]={0};
	int count=1;
	int i=0,pos=-1;
	int alive=0;
	while(count<=N)
	{
		do{
			pos=(pos+1)%N; //���δ���
			if(man[pos]==0)
			{
				i++;
				if(i==M)
				{
					//����Ϊ3
					i=0;
					break; 
				 } 
			 }
				 
			
		} while(1);
			 
			 man[pos]=count;
				 count++;
		 cout<<"Լɪ������"<<endl;
			 for(i=0;i<N;++i)
			 {
					man[i];
			  } 
			  
			  cout<<"����ȶ�����"<<endl;
			  cin>>alive;
			  cout<<endl<<"��ʾ��"<<alive<<"����Ҫ�ŵ�λ��"<<endl;
			  if(man[i]>alive) 
			  	cout<<"D"<<endl;
			  else
			  cout<<"L"<<endl;
			  if((i+1)%5==0)
			  cout<<" "<<endl; 
	 } 
}
