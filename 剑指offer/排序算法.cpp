#include<iostream>
#include<vector>
#include<ctime>
#include<stdlib.h> 
using namespace std;

/*
int Partition(int data[],int length,int start,int end)
{
	if(data==NULL || length<=0 || start <0 || end>=length)
	{
		throw new std::exception("Invalid Parameters");
	}
	
	int index=RandomIntRange(start,end);
	Swap(&data[index],&data[end]);
	int small=start-1;
	for(index=start;index<end;++index)
	{
		if(data[index]<data[end])
		{
			++small;
			if(small!=index)
			{
				Swap(&data[index],&data[small]);
			}
		}	
	}
	++small;
	Swap(&data[small],&data[end]);
	return small;
}

void QuickSort(int data[],int length,int start,int end)
{
	if(start==end)
	return;
	int index=Partition(data,length,start,end);
	if(inddx>start)
	{
		QuickSort(data,length,start,end);
	}
	if(index<end)
	{
		QuickSort(data,length,index+1,end);shu 
	} 
}*/

class Sort
{
	public:
		void swap(int a[],int i,int j)
		{
			int temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		}

		void BubbleSort()
		{
			for(int i=0;i<n;++i)
			{
				for(int j=0;j<n-i-1;++j)
				{
					if(data[j]>data[j+1])
					{
						swap(data,j,j+1);
					}
			   	}
		  	}
	    }
	    
	    void show()
	    {
	    	for(int i=0;i<n;i++)
	    	{
	    		cout<<data[i]<<" ";
			}
			cout<<endl;
		}
	 Sort(int _num):n(_num)
	 {
		srand(NULL);
		data=new int[n];
		for(int i=0;i<n;i++)
		{
			data[i]=rand()%1000;	
		} 		
	 }  
	 ~Sort()
	 {
	 	if(data!=NULL)
	 	{
	 		delete[] data;
		}
		data=NULL;
	 }
	 void CooktailSort()
	 {
	 	int left=0;
		int right=n-1;
		while(left<right)
		{
			for(int i=left;i<right;++i)
			
			{
				if(data[i]>data[i+1])
				{
					swap(data,i,i+i);	
				}
			}
			right--;
			for(int i=right;i>left;--i)
			{
				if(data[i-1]>data[i])	
				{
					swap(data,i-1,i);
				}
			} 
			left++;	
		}	
	 } 
	 
	 
	 /*
	 	for(int i=0;i<n;++i)
	 	{
	 		int min=i;
			 for(int j=i+1;j<n;++j)
			 {
			 	if(data[j]<data[min])
			 	{
			 		min=j;
			 	}
			 }
			 if(min!=i)
			 {
			 	swap(data,min,i);
			 }
	 	}
	 */
	 void SelectionSort(	)
	 {
	 	for(int i=0;i<n-1;++i)
	 	{
	 		int min=i;
			 for(int j=i+1;j<n;++j)
			 {
			 	if(data[j]<data[min])
				 {
				 	min=j;	
				 }	
			 }
			 if(min!=i)
			 {
			 	swap(data,min,i);	
			 }	
		}
	 }
	 void InsertSort()
	 { 
	 	for(int i=1;i<n;++i)
	 	{
	 			int get=data[i];  //拿到一张牌 
	 			int j=i-1; //左边的牌总是被排好 
	 			while(j>=0 && data[j]>get)  //将拿到的牌从右往左 进行比较 
				 {
				 	data[j+1]=data[j];//如果该手牌比抓到的要大，就将其右移 
					 --j; 
				 } 
				 data[j+1]=get;  //直到该手牌比捉到的小，将抓到的牌出入进去 
		}
	 }
	 
	 //插入排序的改进：二分插入排序
	 void InsertionSortDichotomy()
	 {
	 	for(int i=1;i<n;i++)
		 {
			int get=data[i];  //右手拿到一张牌 
			int left=0;  //拿在左手上的牌总是排好顺序的，所以使用二分法 
			int right=i-1;  //右边边界初始化 
			while(left<=right)  //二分定位新牌位置 
			{
				int mid=(left+right)/2;
				if(data[mid]>get)
				{
					right=mid-1;	
				}
				else
				{
					left=mid+1;
				}
			}	
			for(int j=i-1;j>=left;j--)
				{
					data[j+1]=data[j] ;
				} 
				data[left]=get;
		 }	
	 } 
	 
	 void shell_sort()
	 {
	 	int h=0;
		 while(h<=n)
		 {
		 	h=3*h+1;	//生成初始增量 
		 }	
		 while(h>=1)
		 {
		 	for(int i=h;i<n;++i)
		 	{
		 		int j=i-h;
		 	
		 		int get=data[i];
		 			cout<<"i="<<i<<"j="<<j<<"get="<<get<<endl;
				 while(j>=0 && data[j]>get)
				 {
				 	data[j+h]=data[j];	
				 	j=j-h;
				 	show();
				 }	
				 cout<<endl;
				 data[j+h]=get;
			}
			h=(h-1)/3;  //递减增量 
		  } 	 
	 } 
	 
	 void heap_pify(int _data[],int i,int size)
	 {
	 	int left_child=2*i+1;  //左孩子索引
		int right_child=2*i+2; //右孩子索引
		int max=i;  //选出当前节点与其左右孩子三者中的最大值 
		if(left_child<size && _data[left_child]>data[max]) 
		{
			max=left_child; 
		}
		if(right_child<size && _data[right_child]>data[max])
		{
			max=right_child;
		}
		if(max!=i)
		{
			swap(data,i,max);
			heap_pify(_data,max,size);
		}
	 }
	 //para int data[],int n
	 int build_heap()  //建堆 时间复杂度o(n) 
	 {
	 	int heap_size=n;
	 	for(int i=heap_size/2-1;i>=0;i--)  //从每一个非叶子节点开始向下进行堆调整 
	 	{
	 			heap_pify(data,i,heap_size); 
    	} 
    	return heap_size;
	 }
	 
	 void heap_sort()
	 {
	 	int heap_size=build_heap();  //创建一个最大堆 
	 	while(heap_size>1)  //堆（无序区）元素个数大于一，未完成排序 
	 	{
	 		//将堆顶元素与堆的最后一个元素互换，并从堆中去掉最后一个元素 
	 		//此处交换操作肯将后面元素的稳定性打乱，所以堆排序四不稳定的排序算法 
	 		swap(data,0,--heap_size);
			 heap_pify(data,0,heap_size);  	//从新的堆顶元素开始向下进行堆调整，时间复杂度为o(logn) 
		}
	 }
	 
	 int partition(int left,int right)
	 {
	 	int pivot=data[right];  //每次选择最后一个元素最为基准
		int tail=left-1;
		for(int i=left;i<right;++i) 
		{
			if(data[i]<pivot)
			{
				swap(data,++tail,i);  //将小于等于基准的元素放到子数组的末尾 
			}
		}
		swap(data,tail+1,right);  //最后把基准放到前一个子数组的后面，剩下的子数组技术大于基准的子数组
		//该操作可能会将后面元素的稳定性打乱，所以快速排序是不稳定的排序算法
		 
		return tail+1;  //返回基准的索引 
	 }
	 
	 void quik_sort(int left,int right)
	 {
	 	if(left>right)
	 	{
	 		return;
		 }
		 int pivot_index=partition(left,right);  //基准的索引
		 quik_sort(left,pivot_index-1); 
		 quik_sort(pivot_index+1,right);
	  } 
	  private:
	  int *data;
	  int n;
};

int main()
{
	Sort bt(10);
	bt.show();
//	bt.BubbleSort();
//	bt.CooktailSort();
//bt.SelectionSort();
//	bt.InsertSort();
//bt.InsertionSortDichotomy();
//bt.shell_sort();
//bt.heap_sort();
   bt.quik_sort(0,9);
	bt.show();	
	
	
} 
