#include"display.h" 
#include<iostream>

#include<string.h>>
using namespace std;

const int len=10;
void bouble(int arr[],int len)
{
	for(int i=0;i<len-1;i++)
	{
		for(int j=i;j<len-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(arr,j,j+1);
			}
		}
	}
}

void bouble_improve(int arr[],int len)
{
	int left=0;
	int right=len-1;
	//向前走
	while(left<right)
	{
	  
		for(int i=left;i<right;i++)
		{
			if(arr[i]>arr[i+1]) swap(arr,i,i+1);
		}
		left++;
		for(int i=right;i>left;i--)
		{
			if(arr[i]<arr[i+1])  swap(arr,i,i+1);
		}
		right--;
	}
}

#if 0
int main()
{
	int arr[]={10,2,7,46,23,44,55,77,46};
	int len=sizeof(arr)/sizeof(arr[0]);
	bouble_improve(arr,len);
	display<int>(arr,len);	
} 
#endif


/*
简单选择排序 
通过n-i次比较，从（n-(n-i)）中拿出最小的关键字，并和第i个记录交换 

由于每次都将第i小都确定了，所以最后一趟的最后一个元素一定是最大的 
所以只要n-1趟就可以了 
*/
void simple_select_sort(int arr[],int len)
{
	for(int i=0;i<len-1;i++)
	{
		int index=i;
	
		for(int j=i+1;j<len;j++)	
		{
			if(arr[index]>arr[j])
			{
				index=j;
			}
		}
		//如果说Index不等于i说明找到了最大的 
		if(index!=i) swap(arr,i,index);
	} 	
}



#if 0 
int main()
{
	int arr[len];
	init_data(arr,len);
	simple_select_sort(arr,len);
	display<int>(arr,len);
} 
#endif

/*
	直接插入排序
	将一个记录插入一个已经有序等待表中，从而得到一个新的,记录计数为1的有序表 
*/

void insert_sort(int arr[],int len)
{
	for(int i=1;i<len;i++)
	{
		int get=arr[i];
		int j;
		for(j=i-1;j>=0 && get<arr[j];j--)
			arr[j+1]=arr[j];
		arr[j+1]=get;
	}	
} 

#if 0
int main()
{
	int arr[len];
	init_data(arr,len);
	insert_sort(arr,len);
	display<int>(arr,len);
}
#endif
void find_one(char str[])
{
	int ch[128]={0};
	int len=strlen(str);
	for(int i=0;i<len;i++)
	{
		ch[str[i]]++;
	}
	for(int i=0;i<len;i++)
	{
		if(ch[str[i]]==1)
		{
			printf("%c",str[i]);
			break;
		}	
	}
}

#if 0
int main()
{
	char str[]={"abceffcab"};
	find_one(str);
}
	
#endif
/*
void shell_sort_my(int arr[],int len)
{
	int h=0;
	while(h<=len) h=3*h+1;
	
	while(h>=1)
	{
		for(int i=h;i<len;i++)
		{
			int j=i-h;
			int get=arr[i];
			while(j>=0 && arr[j]>get)
			{
				arr[j+h]=arr[j];
				j=j-h;
				cout<<"int the while"<<endl;
				display<int>(arr,len);
				cout<<"i="<<i<<" j+h="<<j+h<<endl;
			 } 
			 cout<<endl;
			 arr[j+h]=get;
			 cout<<"update"<<endl;
			 	display<int>(arr,len);
			 	cout<<"h="<<h<<" i="<<i<<" j+h="<<j+h<<endl;
		}
		display<int>(arr,len);
		cout<<endl;
		h=(h-1)/3;
	}
} 
 */
 
void shell_sort_my(int arr[],int len)
{
	int inc=0;
	while(inc<len) inc=3*inc+1;
	
	while(inc>=1)
	{
		for(int i=inc;i<len;i++)
		{
			int j=i-inc;
			int get=arr[i];
			while(j>=0&&arr[j]>get)
			{
				arr[j+inc]=arr[j];
				j-=inc;
			}
			arr[j+inc]=get;  //由于不满足条件时j号下表已经是不能插入的，所以选取后面的
			//j+h作为插入元素大的下表 
		}
		inc=(inc-1)/3;
	}
}


void heap_motify(int arr[],int index,int size)
{
	int left=2*index+1;
	int right=2*index+2;
	int max=index;
	if(left<size && arr[left]>arr[max])  max=left;
	if(right<size && arr[right]>arr[max]) max=right;
	if(index!=max)
	{
		swap(arr,index,max);
		heap_motify(arr,max,size);
	}	
}



void adjsut(int arr[],int start,int len)
{
	int get=arr[start];
	int j=2*start+1;
	for(;j<len;j=2*start+1)
	{
		if(j<len && arr[j]>arr[j+1]) j++;  //左孩子 
		if(arr[j]>get) { arr[start]=arr[j]; start=j;}     //右孩子 
		else break;
	}	
	arr[start]=get;
} 
/*

void adjust(int arr[],int start,int end)
{
	int temp=arr[start];
	for(int i=2*start+1;i<=end;i=2*start+1)
	{
		if(i<end && arr[i]<arr[i+1]) i++;
		if(arr[i]>temp) {arr[start]=arr[i];start=i;} //大的为根，并向下调整 
		else	{ break;}	
	}
	arr[start]=temp;
}

void iterator_heap_sort(int arr[],int len)
{
	int be;
	int temp;  //len-1-1保证是父亲节点 
	for(be=(len-2)/2;be>=0;be--) adjust(arr,be,len);  //建堆 
	
	for(int i=0;i<len-1;i++) { temp=arr[0]; arr[0]=arr[len-1-i]; 
	arr[len-i-1]=temp;
	adjust(arr,0,len-1-i-1);  //在次减一是要它的父亲节点 
	 }
} 
*/
void build_heap(int arr[],int len)
{
	for(int i=len/2-1;i>=0;i--)
	{
		heap_motify(arr,i,len);
	}
}




void heap_sort(int arr[],int len)
{
	int size=len;
	while(size>1)
	{
		swap(arr,0,size);
	
	//	heap_adjust(arr,0,--size);
	}
}

int partiton(int arr[],int left,int right)
{
	int tail=left-1;
	int pivot=arr[right];
	for(;left<right;left++)
	{
		if(pivot<arr[left])
		swap(arr,++tail,left);
	}
	swap(arr,tail+1,right);
	return tail+1;
}

void quik_sort(int arr[],int left,int right)
{
	if(left<right)
	{
		int pivot_index=partition(arrm);			
	}
}
	
}
#if 0
int main()
{
	int arr[len]={9,1,5,8,3,7,6,2};
	//init_data(arr,len);
	
	shell_sort_my(arr,len);
	display<int>(arr,len);
}

#endif

#if 0
int main()
{
	int arr[len];
	init_data(arr,len);
	build_heap(arr,len);
	heap_sort(arr,len);
	display<int>(arr,len); 
}
#endif


int main()
{
	int arr[len];
	init_data(arr,len);
	iterator_heap_sort(arr,len);
	display<int>(arr,len); 
}


