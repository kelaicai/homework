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
		 	int pivot=phead[right];  //选取最后一个元素为基准 
		 	int tail=left-1;  //tail为小于基准的子数组最后一个元素的索引 
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
		 	int tail=left-1;//tail表示小于基准的子数组中的最后一个元素的索引】
			 for(int i=left;i<right;++i)
			 {
			 	if(phead[i]<=pivot)
				 {
				 	swap(phead,++tail,i);//将小于基准的元素放入子数组末尾	
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
		//三部快排 
		int partition(int left,int right)
		{
			int pivot=phead[right];  //以最后一个元素作为基准 
			int tail=left-1;  //tail是小于pivot的子数组中的最后一个元素的下标
			for(int i=left;i<right;++i)
			{
				if(phead[i]<=pivot)  //将小于等于基准的元素放到前一个子数组末尾 
				{
					swap(phead,++tail,i);
				}
			 } 
			 swap(phead,tail+1,right); //最后将基准放到前一个子数组后面，剩下的子数组是大于基准的子数组
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
		
		/*改进一：中间为基准 
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
					while(phead[++i]<s);  //向右找
					while(phead[--j]>s); //向后找
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
		
		//普通快速排序 
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
					//向右找
					while(i+1<num && phead[++i]<s);
					while(j-1>-1 && phead[--j]>s);
					if(i>=j)
					{
						break;
					 } 
					 swap(phead,i,j);
				}
				 phead[left]=phead[j];  //交换基准 
				 phead[j]=s;
				QuikSort(left,j-1);
				QuikSort(j+1,right); 
			}
		}
		*/
	　　void QuikSort(int left,int right) 
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


