#include"display.h"


int partition(int data[],int left,int right)
{
	int pviot=data[right];  //ÿ��ѡ�����һ��Ԫ����Ϊ��׼ 
	int tail=left-1;  //tailΪС�ڻ�׼�����������һ��Ԫ�ص����� 
	for(int i=left;i<right;i++)  //������׼���������Ԫ�� 
	{
		if(data[i]<=pviot)   //��С�ڵ��ڻ�׼��Ԫ�طŵ�ǰһ���������ĩβ 
		{
		//	swap(data,++tail,i);
		++tail;
			swap(data[tail],data[i]);
		}	
	}
	swap(data[tail+1],data[right]);
	return tail+1;
}


int partition(int data[],int left,int right)
{
	 
	int pviot,i,j;	
	if(left<right)
	{
		 pviot=data[left];
		 i=left;
		 j=right;
		 while(1)
		 {
		 	//������
			 while(i+1<len && data[++i<pviot]) ;
			 while(j-1>-1 && data[--j]>pviot);
			 if(i>=j)
			 {
			 	break;
			 }
			 swap(data,i,j);
		 }
		 data[left]=data[j];
		 data[j]=pviot;
		quik_sort(data,left,j-1);
		quik_sort(data,j+1,right);		 
	} 

}
void quik_sort(int data[],int left,int right)
{
	if(left>=right)
	{
		return ;
	}
	int pivot_index=partition(data,left,right);
//	cout<<"pviot inedx="<<pivot_index<<endl;
	quik_sort(data,left,pivot_index-1);
	quik_sort(data,pivot_index+1,right);
}
int main()
{
	
	int data[10]={0};
	int len=sizeof(data)/sizeof(data[0]);
	init_data(data,len);
	cout<<"original data"<<endl; 
	display(data,len);
	cout<<"after sort"<<endl;
//	shell_sort(data,0,len);
   quik_sort(data,0,len-1)	;
	display(data,len);
 
	return 0;
}
