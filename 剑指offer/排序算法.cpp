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
	 			int get=data[i];  //�õ�һ���� 
	 			int j=i-1; //��ߵ������Ǳ��ź� 
	 			while(j>=0 && data[j]>get)  //���õ����ƴ������� ���бȽ� 
				 {
				 	data[j+1]=data[j];//��������Ʊ�ץ����Ҫ�󣬾ͽ������� 
					 --j; 
				 } 
				 data[j+1]=get;  //ֱ�������Ʊ�׽����С����ץ�����Ƴ����ȥ 
		}
	 }
	 
	 //��������ĸĽ������ֲ�������
	 void InsertionSortDichotomy()
	 {
	 	for(int i=1;i<n;i++)
		 {
			int get=data[i];  //�����õ�һ���� 
			int left=0;  //���������ϵ��������ź�˳��ģ�����ʹ�ö��ַ� 
			int right=i-1;  //�ұ߽߱��ʼ�� 
			while(left<=right)  //���ֶ�λ����λ�� 
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
		 	h=3*h+1;	//���ɳ�ʼ���� 
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
			h=(h-1)/3;  //�ݼ����� 
		  } 	 
	 } 
	 
	 void heap_pify(int _data[],int i,int size)
	 {
	 	int left_child=2*i+1;  //��������
		int right_child=2*i+2; //�Һ�������
		int max=i;  //ѡ����ǰ�ڵ��������Һ��������е����ֵ 
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
	 int build_heap()  //���� ʱ�临�Ӷ�o(n) 
	 {
	 	int heap_size=n;
	 	for(int i=heap_size/2-1;i>=0;i--)  //��ÿһ����Ҷ�ӽڵ㿪ʼ���½��жѵ��� 
	 	{
	 			heap_pify(data,i,heap_size); 
    	} 
    	return heap_size;
	 }
	 
	 void heap_sort()
	 {
	 	int heap_size=build_heap();  //����һ������ 
	 	while(heap_size>1)  //�ѣ���������Ԫ�ظ�������һ��δ������� 
	 	{
	 		//���Ѷ�Ԫ����ѵ����һ��Ԫ�ػ��������Ӷ���ȥ�����һ��Ԫ�� 
	 		//�˴����������Ͻ�����Ԫ�ص��ȶ��Դ��ң����Զ������Ĳ��ȶ��������㷨 
	 		swap(data,0,--heap_size);
			 heap_pify(data,0,heap_size);  	//���µĶѶ�Ԫ�ؿ�ʼ���½��жѵ�����ʱ�临�Ӷ�Ϊo(logn) 
		}
	 }
	 
	 int partition(int left,int right)
	 {
	 	int pivot=data[right];  //ÿ��ѡ�����һ��Ԫ����Ϊ��׼
		int tail=left-1;
		for(int i=left;i<right;++i) 
		{
			if(data[i]<pivot)
			{
				swap(data,++tail,i);  //��С�ڵ��ڻ�׼��Ԫ�طŵ��������ĩβ 
			}
		}
		swap(data,tail+1,right);  //���ѻ�׼�ŵ�ǰһ��������ĺ��棬ʣ�µ������鼼�����ڻ�׼��������
		//�ò������ܻὫ����Ԫ�ص��ȶ��Դ��ң����Կ��������ǲ��ȶ��������㷨
		 
		return tail+1;  //���ػ�׼������ 
	 }
	 
	 void quik_sort(int left,int right)
	 {
	 	if(left>right)
	 	{
	 		return;
		 }
		 int pivot_index=partition(left,right);  //��׼������
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
