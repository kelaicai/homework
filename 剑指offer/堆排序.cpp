#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<stack>
#include<string.h>
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
		/*
	
		int partition(int left,int right)
		{
			int pivot=phead[right];  //�����һ��Ԫ����Ϊ��׼Ԫ�� 
			int tail=left-1;  //tail��С��piviot����������һ��Ԫ�ص��±� 
			for(int i=left;i<right;++i)
			{
				if(phead[i]<pivot)   
				{
					swap(phead,++tail,i);  //��С�ڻ�׼��Ԫ�طŵ�������ĺ��� 
				}
			}
			swap(phead,tail+1,right);
			return tail+1;
		}
		void quik_sort(int left,int right)
		{
			if(left>=right)
			{
				return ;	
			}
			int pivot_index=partition(left,right);
			quik_sort(left,pivot_index-1);
			quik_sort(pivot_index+1,right); 
		}*/
		
	void quik_sort(int left,int right)
	{
		int i,j,pivot;
		if(left<right)
		{
			pivot=phead[left]; 
			i=left;
			j=right+1;
			while(1)
			{
				while(i+1<num && phead[++i]<pivot);
				while(j-1<num && phead[--j]>pivot);
				if(i>=j)
				{
					break;
				 } 
				swap(phead,i,j);
			}
			phead[left]=phead[j];
			phead[j]=pivot;
			
			quik_sort(left,j-1);
			quik_sort(j+1,right);
		}
	} 
	
		void quik_sort_2(int left,int right)
		{
			int i,j,pivot;
			if(left<right)
			{
				pivot=phead[(left+right)/2];
				i=left-1;
				j=right+1;
				while(1)
				{
				  
					while(phead[++i]<pivot);
					while(phead[--j]>pivot);
					if(i>=j)
					{
						break; 
					} 
					swap(phead,i,j);
			      }
			    	quik_sort_2(left,i-1);
					quik_sort_2(j+1,right);  
			}
		
		}
		
		int partition(int left,int right)
		{
			int pivot=phead[right];
			int tail=left-1;
			for(int i=left;i<right;++i)
			{
				if(pivot<phead[i])
				{
					swap(phead,++tail,i); 
				}
			}
			swap(phead,tail+1,right);
			return tail+1; 
		}
		int build_heap()
		{
			int heap_size=num;
			for(int i=heap_size/2-1;i>=0;--i)
			{
				heap_pify(i,heap_size);  //�ӵ�i��Ԫ�ؽ��жѵ��� 
			}
			return heap_size;
		 }
		 
		 int heap_pify(int i,int size)
		 {
		 	int left_child=2*i+1;
			 int right_child=2*i+2;
			 int max=i;  //���Һ�ֽ�������±�
			 if(left_child <size&& phead[left_child]>phead[max] )
			 {
			 	max=left_child;
			  } 
			  if(right_child<size && phead[right_child]>phead[max])
			  {
			  	max=right_child;
			  }
			  if(max!=i)
			  {
			  		swap(phead,i,max);
			  		heap_pify(max,size);
			  }
			 	
		 } 
		 
		 void heap_sort()
		 {
		 	int heap_size=build_heap();
		 	while(heap_size>1)
			 {
			 	swap(phead,0,--heap_size);
				heap_pify(0,heap_size); 	
			} 
		 }
		 
		 /*
		 void quik_sort_un(int left,int right)
		 {
		 	stack<int> st;
		 	
		 	if(left<right)
		 	{
		 	
				 int pivot_index=partition(left,right);
				 if(left<pivot_index-1)
				 {
				 	st.push(left);
				 	st.push(pivot_index-1);
				 }
				 if(pivot_index+1<right)
				 {
				 	st.push(pivot_index+1);
				 	st.push(right);
				 }
				 
				 while(!st.empty())
				 {
				 	int right_1=st.top();
				 	st.pop();
				 	int left_1=st.top();
				 	st.pop();
				 	pivot_index=partition(left_1,right_1);
					 if(left_1<pivot_index-1)
					 {
					 	st.push(left_1);
				 		st.push(pivot_index-1);
					  } 
					  if(pivot_index+1<right_1)
					  {
				  		st.push(pivot_index+1);
				 		st.push(right_1);
				 	 }
				 	 
				 }
			 }
		 }
	
		 void quik_sort_un(int left,int right)
		 {
		 	stack<int> st;
		 	if(left<right)
		 	{
		 		int pivot_index=partition(left,right);
		 		if(left<pivot_index-1)
		 		{
		 			st.push(left,pviot_index-1);
			 		st.push(pivot_index+1,right);
				}
				if(pivot_index+1<right)
				{
					st.push(pivot_index+1);
					st.push(right);
				}
				while(!st.empty())
				{
					int right_1=st.top();
					st.pop();
					int left_1=st.top();
					st.pop();
					pivot_index=partition(left_1,right_1);
					right_1=st.top();
					if(left_1<pivot_index-1)
					{
						st.push(left_1);
						st.push(pivot_index-1);
					}
					if(pivot_index+1<right)
					{
						st.push(pivot_index+1);
						st.push(right); 
					}
				}		
			}
		 }
		 	 */
		 
		/*
		
		int build_heap()
		{
			int heap_size=num;
			for(int i=heap_size/2-1;i>=0;--i)
			{
				heap_pify(i,heap_size);
			}
			return heap_size;
		}
		
		void heap_pify(int i,int size)
		{
			int left_child=2*i+1;
			int right_child=2*i+2;
			int max=i;
			if(left_child<size && phead[left_child]>phead[max])
			{
				max=left_child;
			 } 
			 if(right_child<size && phead[right_child]>phead[max])
			 {
			 	max=right_child;
			 }
			 if(max!=i)
			{
				swap(i,max);
				heap_pify(max,size);	
			}
		}
		
		void heap_sort()
		{
			int heap_size=build_heap();
			while(heap_size>1)   
			{
				swap(0,--heap_size);  //�����Ԫ�طŵ�����С��Ԫ�ط�ǰ�� 
				heap_pify(0,heap_size);
			}
		}
		
		
		int build_heap()
		{
			int heap_size=num;  //��ȡ�Ѵ�С 
			for(int i=heap_size/2-1;i>=0;--i)  //��ÿһ����Ҷ�ӽڵ���жѵ��� 
			{
				heap_pify(phead,i,heap_size);
			 } 
			 return heap_size;
		} 
		
		void heap_pify(int i,int size)
		{
			int left=2*i+1;
			int right_child=2*i+2;
			int max=i;
			if(left_child<size && phead[left_child]>phead[max])
			{
				max=left_child;
			 } 
			 if(right_child<size && phead[right_child]>phead[max])
			 {
			 	max=right_child;
			 }
			 if(max!=i)
			 {
			 	swap(i,max);
			 	heap_pify(max,size);
			  } 
		} 
		
		void heap_sort()
		{
			int heap_size=build_heap(); 
			while(heap_size>0)
			{
				swap(phead,0,--heap_size);
				heap_pify(0,heap_size);  //���µĶѶ�Ԫ�ؿ�ʼ���½��жѵ�����ʱ�临�Ӷ�0(logn) 
			}
		 } 
		
		int BuildHeap(int a[],int n)
		{
			int heap_size=num;
			for(int i=heap_size/2-1;i>=0;--i) //��ÿһ����Ҷ�ӽڵ㿪ʼ���½��жѵ��� 
			{
				heap_pify(a,i,heap_size);	
			}	
			return heap_size ;
		} 
	   //�Զѽ��е���	
		void heap_pify(int a[],int i,int size)
		{
			int left_child=2*i+1;  //����
			int right_child=2*i+2;  //�Һ���
			int max=i;  //ѡ����ǰ�ڵ����������Һ��ӽڵ�����֮�е����ֵ
			if(left_child<size && a[left_child]>a[max]) 
			{
				max=left_child;
			}
			if(right_child<size && a[right_child]>a[max])
			{
				max=right_child;
			}
			if(max!=i)
			{
				swap(a,i,max);  //�ѵ�ǰ�ڵ���������ֵ��ֱ�ӣ��ӽڵ���н��� 
				heap_pify(a,max,size);  //�������½��е��� 
			}
		}
		
		void heap_sort()
		{
			int heap_size=BuildHeap(phead,num);  //����һ������ 
			while(heap_size>1) //�ѣ���������Ԫ�ظ�������1��δ������� 
			{
				swap(phead,0,--heap_size);
				heap_pify(phead,0,heap_size); //���¶�Ԫ�ؿ�ʼ���½��жѵ�����ʱ�临�Ӷ�
				 
			}
			
			
		} */
		void swap(int arr[],int i,int j)
		{
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
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
	Sort st;
	st.show();
	//st.quik_sort(0,9);
	st.quik_sort_2(0,9);
    // st.heap_sort();
    //st.quik_sort_un(0,9);
	st.show();
	return 0; 
 } 
