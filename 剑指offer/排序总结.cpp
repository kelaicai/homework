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
	//��ǰ��
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
��ѡ������ 
ͨ��n-i�αȽϣ��ӣ�n-(n-i)�����ó���С�Ĺؼ��֣����͵�i����¼���� 

����ÿ�ζ�����iС��ȷ���ˣ��������һ�˵����һ��Ԫ��һ�������� 
����ֻҪn-1�˾Ϳ����� 
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
		//���˵Index������i˵���ҵ������� 
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
	ֱ�Ӳ�������
	��һ����¼����һ���Ѿ�����ȴ����У��Ӷ��õ�һ���µ�,��¼����Ϊ1������� 
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
			arr[j+inc]=get;  //���ڲ���������ʱj���±��Ѿ��ǲ��ܲ���ģ�����ѡȡ�����
			//j+h��Ϊ����Ԫ�ش���±� 
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
		if(j<len && arr[j]>arr[j+1]) j++;  //���� 
		if(arr[j]>get) { arr[start]=arr[j]; start=j;}     //�Һ��� 
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
		if(arr[i]>temp) {arr[start]=arr[i];start=i;} //���Ϊ���������µ��� 
		else	{ break;}	
	}
	arr[start]=temp;
}

void iterator_heap_sort(int arr[],int len)
{
	int be;
	int temp;  //len-1-1��֤�Ǹ��׽ڵ� 
	for(be=(len-2)/2;be>=0;be--) adjust(arr,be,len);  //���� 
	
	for(int i=0;i<len-1;i++) { temp=arr[0]; arr[0]=arr[len-1-i]; 
	arr[len-i-1]=temp;
	adjust(arr,0,len-1-i-1);  //�ڴμ�һ��Ҫ���ĸ��׽ڵ� 
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


