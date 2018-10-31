#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;

class Sort
{
	public:
		Sort(int _num=10):num(_num)
		{
			phead=new int[num];	
			
			srand(NULL);
			for(int i=0;i<num;++i)
			{
				phead[i]=rand()%100;	
			}		
		}
		
		void swap(int arr[],int i,int j)
		{
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		 } 
		 
		 /*
		 int partition(int left,int right)
		 {
		 	int pivot=phead[right];  //ѡȡ���һ��Ԫ��Ϊ��׼ 
		 	int tail=left-1;  //tailΪС�ڻ�׼�����������һ��Ԫ�ص����� 
		 	for(int i=left;i<right;++i)
			 {
			 	if(phead[i]<=pivot)
				 {
				 	swap(phead,++tail,i);	
				 }	
			 } 
			 swap(phead,tail+1,right); 
			 return tail+1;
		 }
		 
		 void QuikSort(int left,int right)
		 {
		 	if(left>=right)
		 	{
		 		return; 
			 }
			 int pivot_index=partition(left,right);
			 QuikSort(left,pivot_index-1);
			 QuikSort(pivot_index+1,right); 
		 }
		
		 
		 int partition(int left,int right)
		 {
		 	int pivot=phead[right];
		 	int tail=left-1;//tail��ʾС�ڻ�׼���������е����һ��Ԫ�ص�������
			 for(int i=left;i<right;++i)
			 {
			 	if(phead[i]<=pivot)
				 {
				 	swap(phead,++tail,i);//��С�ڻ�׼��Ԫ�ط���������ĩβ	
				 }	
				 swap(phead,tail+1,right);
				 return tail+1; 
			 } 
		 }
		 
		void QuikSort(int left,int right)
		{
			if(left>=right)
			{
				return;
			}
			int pivot_index=partition(left,right);
			QuikSort(left,pivot_index-1);
			QuikSort(pivot_index+1,right); 
		} 
		//�������� 
		int partition(int left,int right)
		{
			int pivot=phead[right];  //�����һ��Ԫ����Ϊ��׼ 
			int tail=left-1;  //tail��С��pivot���������е����һ��Ԫ�ص��±�
			for(int i=left;i<right;++i)
			{
				if(phead[i]<=pivot)  //��С�ڵ��ڻ�׼��Ԫ�طŵ�ǰһ��������ĩβ 
				{
					swap(phead,++tail,i);
				}
			 } 
			 swap(phead,tail+1,right); //��󽫻�׼�ŵ�ǰһ����������棬ʣ�µ��������Ǵ��ڻ�׼��������
			 return tail+1; 
		}
		void QuikSort(int left,int right)
		{
			if(left>=right)
			{
				return;
			}
			show();
			int pivot_index=partition(left,right);
			QuikSort(left,pivot_index-1);
			QuikSort(pivot_index+1,right);
		}
		*/
		
		/*�Ľ�һ���м�Ϊ��׼ 
		QuikSort(int left,int right)
		{
			int i,j,s;
			if(left<right)
			{
				s=phead[(left+right)/2];
				i=left-1;
				j=right+1;
				while(1)
				{
					while(phead[++i]<s);  //������
					while(phead[--j]>s); //�����
					if(i>=j)
					{
						break;
					}
					swap(phead,i,j);		 
				} 
			    QuikSort(left,i-1);
			    QuikSort(j+1,right);
			}
			
		}
		
		//��ͨ�������� 
		void QuikSort(int left,int right)
		{
			int i,j,s;
			if(left<right)
			{
				s=phead[left];
				i=left;
				j=right+1;
				while(1)
				{
					//������
					while(i+1<num && phead[++i]<s);
					while(j-1>-1 && phead[--j]>s);
					if(i>=j)
					{
						break;
					 } 
					 swap(phead,i,j);
				}
				 phead[left]=phead[j];  //������׼ 
				 phead[j]=s;
				QuikSort(left,j-1);
				QuikSort(j+1,right); 
			}
		}
		*/
	����void QuikSort(int left,int right) 
		{ 
			int s,i,j;
			if(left<right)
			{
				s=phead[left];
				i=left;
				j=right+1;
				while(1)
				{
					while(i+1<num && phead[++i]<s);
					while(j-1>-1 && phead[--j]>s);
					if(i>=j)
					{
						break;
					}
					swap(phead,i,j);
				}		
				phead[left]=phead[j];
				phead[j]=s;
				QuikSort(left,j-1);
				QuikSort(j+1,right); 
			}	
		} 
		
		void QuikSort1(int left,int right)
		{
			if(left>=right)
			{
				return;
			}
			int s=phead[(left+right)/2];
			int i=left-1;
			int j=right+1;
			while(1)
			{
				while(phead[++i]<s);
				while(phead[--j]>s);
				if(i>=j)
				{
					break;
				}
				swap(phead,i,j);
			}
			QuikSort(left,j-1);
			QuikSort(j+1,right);
			
		}
		~Sort()
		{
			if(phead!=NULL)
			{
				delete phead;
			}
			phead=NULL;
		}
		void show()
		{
			for(int i=0;i<num;i++)
			{
				cout<<phead[i]<<" ";
			}
			cout<<endl;
		}
		private:
			int *phead;
			int num;
};
int main()
{
	Sort  st(10);
	st.show();
	st.QuikSort(0,9);
	st.show();
}


