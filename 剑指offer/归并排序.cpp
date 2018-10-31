#include<iostream>
#include<stdlib.h>
#include<time.h>
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
		void Merge(int left,int mid,int right)
		{
			int len=right-left+1;
			int *temp=new int[len];
			int index=0;
			int i=left;
			int j=mid+1;
			while(i<=mid && j<=right)  //带等号保证了归并的稳定性 
			{
				temp[index++]=phead[i]<=phead[j]?phead[i++]:phead[j++];
			}
			while(i<=mid)
			{
				temp[index++]=phead[i++]; 
			
		 	}
		 	while(j<=right)
			 {
			 	temp[index++]=phead[j++];
			}
			for(int k=0;k<len;++k)
			{
				phead[left++]=temp[k];
			 } 
			 delete temp;
			 temp=NULL;
		 } 
		 */
		/*		 
		 void Merge(int left,int mid,int right)
		 {
		 	int len=right-left+1;
		 	int *temp=new int[len];//辅助空间o(n) 
		 	int i=left;  //前一个数组的起始下标 
		 	int j=mid+1; //后一个数组的起始下标 
		 	int index=0;
			 while(i<=mid && j<=right)
			 {
				temp[index++]=phead[i]<=phead[j]?phead[i++]:phead[j++]; 	
			} 
			while(i<=mid)
			{
				temp[index++]=phead[i++];
			}
			while(j<=right)
			{
				temp[index++]=phead[j++];
			}
			for(int k=0;k<len;++k)
			{
			phead[left++]=temp[k];
			}
			 delete temp;
			 temp=NULL;
		 }
		 void MergeSortIteration()
		 {
		 	int left,mid,right;
		 	for(int i=1;i<num;++i)
		 	{
		 		left=0;
				 while(left+i<num)
				 {
				 	mid=left+i-1;
				 	right=(mid+i)<num?mid+i:num-i;  //后一个子数组的大小可能不够
					 Merge(left,mid,right); 
					 left=right+1;  //前一个子数组索引向后移动 
				  } 
			} 
			  
		 }*/
		 
		 void Merge(int a[],int left,int mid,int right)
		 {
		 	int index=0;
		 	int i=left;
		 	int j=right;
		 	int len=rigth-left+1;
		 	int *temp=new int[len];
		 	while(i<mid && j<right)
		 	{
		 		temp[index++]=a[i]>a[j]?a[i]:a[j];	
			}
			while(i<len)
			{
				temp[index++]=a[i++];
			 } 
			 
			 while(j<len)
			 {
			 	temp[index]=a[j++];
			  } 
			  for(int i=left;i<len;i++)
			  {
			  	a[left++s]=temp[i];
			  }
		 }
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 
		 void Merge(int a[],int left,int mid,int right)
		 {
		 	int len=right-left+1;
		 	int *temp=new int[len];
		 	int index=0;
		 	int i=left;
		 	int j=mid+1;
		 	while(i<=mid&& j<=right)
		 	{
		 		temp[index++]=a[i]>a[j]?a[i++]:a[j++];	
			}
			while(i<=mid)
			{
				temp[index++]=a[i++];	
			}
			while(j<=right)
		 	{
				temp[index++]=a[j++];			 		
			} 
			for(int i=0;i<len;i++)
			{
				a[left++]=temp[i];
			}
		 }
		 
		 void Merge(int a[],int left,int mid,int right)
		 {
			int i=left;
			int j=right;
			int index=0	;
			int len=left-right+1;
			int *temp=new int[len];
			while(i<mid && j<right)
			{
				temp[index++]=a[i]<a[j]?a[i++]:a[j++];		
		    } 	
		    while(i<len)
		    {
		    	temp[index++]=a[i++];
			}
			while(j<len)
			{
				temp[index++]=a[j++];
			}
			for(int k=0;k<len;k++)
			{
				a[left++]=temp[k];
			}
		 }
		 
		 void MergeSort(int left,int right)
		 {
		 	if(left>=right)
		 	{
		 		return;
			 }
			 int mid=(left+right)/2;
			 MergeSort(left,mid);
			 MergeSort(mid+1,right);
			 Merge(phead,left,mid,right); 
		 }
		 
		 void MerSortIteration(int a[],int len)
		 {
		 	int left,mid,right;
		 	for(int i=1;i<len;i*=2)
		 	{
		 		left=0;
		 		while(left+i<len)  //后一个数组存在 
		 		{
		 			mid=left+i-1;
		 			right=mid+i<len?mid+i:len-1;
					 Merge(a,left,mid,right);
					 left=right+1; 
				 }
			 }
		 }
		 
		 
		 void MergeSort(int left,int right)
		 {
		 	if(left==right)
		 	{
		 		return ;
			 }
			 int mid=(left+right)/2;
			 MergeSort(left,mid);
			 MergeSort(mid+1,right);
		 	Merge(phead,left,mid,right);
		 }
		 
		~Sort()
		{
			if(phead!=NULL)
			{
				delete phead;
			}
			phead=NULL;
		}
		
		void MergeSortRecursion(int left,int right)  //递归实现归并排序
		{
			if(left==right)  //当待排序长度为1时，递归开始回溯，进行merge操作 
			{
				return ;
			 } 
			 int mid=(left+right)/2;
			 MergeSortRecursion(mid+1,right);
			 Merge(left,mid,right);
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
	Sort st;
	st.show();
//	st.MergeSortRecursion(0,9);
	st.MergeSortIteration();
	st.show();
	return 0; 
 } 
