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
			pos=(pos+1)%N; //环形处理
			if(man[pos]==0)
			{
				i++;
				if(i==M)
				{
					//报数为3
					i=0;
					break; 
				 } 
			 }
				 
			
		} while(1);
			 
			 man[pos]=count;
				 count++;
		 cout<<"约瑟夫环排序"<<endl;
			 for(i=0;i<N;++i)
			 {
					man[i];
			  } 
			  
			  cout<<"你想救多少人"<<endl;
			  cin>>alive;
			  cout<<endl<<"表示这"<<alive<<"个人要放的位置"<<endl;
			  if(man[i]>alive) 
			  	cout<<"D"<<endl;
			  else
			  cout<<"L"<<endl;
			  if((i+1)%5==0)
			  cout<<" "<<endl; 
	 } 
}
