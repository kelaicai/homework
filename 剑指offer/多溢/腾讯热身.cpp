#include<iostream>
#include<stack>
#include<cstring>
using namespace std;


struct mypair
{
	int x;
	int y;
	bool flag;
};

void sumToK(int arr[],int len,int k,mypair& ipair)
{
	int left=0;
	int right=len-1;
	int sum=0;
	while(left<=right)
	{
		
		sum=arr[left]+arr[right];
		if(k==sum)
		{
			ipair.x=left;
			ipair.y=right;
			ipair.flag=true;
			break;	
		}
		if(sum<k)
		{
			left++;
		}
		else if(sum>k)
		{
			right--;
		}
		else
		{
			;
		}

	
	}

}
void sumToK_order(int arr[],int len,int k,mypair& ipair)
{
	if(arr==NULL || len<0)  return ;
	sumToK(arr,len,k,ipair);
}
void swap(int arr[],int left,int right)
{
	int c=arr[left];
	arr[left]=arr[right];
	arr[right]=c;
}
int partition(int arr[],int left,int right)
{
	int pivot=arr[right];
	int tail=left-1;
	for(;left<right;left++)
	{
		if(pivot>arr[left])
		{
			swap(arr,left,++tail);
		}
	}
	swap(arr,tail+1,right);
	return tail+1;
} 


void quiksort(int arr[],int left,int right)
{
	if(left>=right)  return ;
	
	
	int pivot_index=partition(arr,left,right);
	
	quiksort(arr,left,pivot_index-1);
	quiksort(arr,pivot_index+1,right);
} 

void quiksort(int arr[],int len)
{
	if(arr==NULL || len<0) return;
	quiksort(arr,0,len-1); 
}

void print(int arr[],int len)
{
	if(arr==NULL|| len<0)  return ;
	
	for(int i=0;i!=len;i++)
	{
		cout<<arr[i]<<endl; 
	} 
	cout<<endl;
} 

int myatoi(const char* str)
{
	if(str==NULL)
	{
		return -1; 
	}
	
	while(*str!='\0')
	{
		
	}
}

void primeBefore(int arr[],int left,int right)
{
	while(left<right)
	{
		while(left<right && (arr[left]&0x1)!=0) left++;
		while(left<right && (arr[right]&0x1)==0) right--;
		if(left<right)
		{
			swap(arr,left++,right--);
		}
	}
}
void primeBefore(int arr[],int len)
{
	if(arr==NULL || len<0)  return ;
	
	primeBefore(arr,0,len-1);	
}


typedef int (*PCmp)(void *vp1,void* vp2);

void BubbleSort(void* arr,int len,int Tsize,PCmp cmp)
{
	void* tmp=malloc(sizeof(Tsize));
	void *p1=NULL;
	void *p2=NULL;
	for(int i=0;i<len-1;i++)
	{
		for(int j=0;j+1<len-i;j++)
		{
			p1=(char*)arr+j*Tsize;
			p2=(char*)arr+(j+1)*Tsize;
			if(cmp(p1,p1)>0)
			{
				memcpy(tmp,p1,Tsize);
				memcpy(p1,p2,Tsize);
				memcpy(p2,tmp,Tsize);
			}
		}
	}
}

int Cmp_int(void* p1,void *p2)
{
	return *(int*)p1-*(int*)p2;
}

int Cmp_str(void* p1,void* p2)
{
	return strcmp(*(char**)p1,*(char**)p2);
}


bool IsSmallEnding()
{
	int a=1;
	return *(char*)&a==1;	
}


long htonl(long lval)
{
	if(!IsSmallEnding())  return lval;
	long b=0;
	for(int i=0;i<sizeof(long);i++)
	{
		b=(b<<8) | (lval& 0xff);
		lval=lval>>8;
	} 
	
	return b;
}


void SubSet(int n)
{
	const char *str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int maxnum = 1<<n;          //2^n
	for(int i=0;i<maxnum;i++)//处理0到2^n  -1之间的数字
	{
		for(int j=0;j<n;j++)//j表示二进制右数第几位
		{
			if( (i&(1<<j)) != 0)//表示当前位不为0,则需要打印相应的字母
			{
				cout<<"i="<<i<<"j="<<j<<endl;
				printf("%c ",str[j]);
			}
		}
		printf("\n");
	}
}


void Combination(char *string)  
{  
    assert(string != NULL);  
    vector<char> result;  
    int i , length = strlen(string);  
    for(i = 1 ; i <= length ; ++i)  
        Combination(string , i ,result);  
} 
			//字符串str 在组合长度为num时的结果vec 
void Combination(char *str,int num,vector<char>& vec)
{
	if(num==0)
	{
		vector<char>::iterator it=vec.begin();
		int len=vec.size();
		for(;it!=vec.end();++it)
		{
			cout<<*it<<endl;
		}
	}
	
	if(*str=='\0') return ;
	//把当前的*str包含在组合中 
	vec.push_back(*str);
	//在剩余的n-1个字符中选出长度为m-1的组合 
	Combination(str+1,num-1,vec);
	//找到包含*str本身的字符就将其去除 
	vec.pop_back();
	//将*str放在不放在组合中，在剩余的n-1个元素中找 
	Combination(str+1,num,vec); 
}

void iterator_quiksort(int arr[],int left,int right)
{
	if(arr==NULL || left>=right || left<0 || right<0 )	return ;
	stack<int> st;
	while(left<right)
	{
		int pviot_index=partition(arr,left,right);
		st.push(pviot_index-1);
		st.push(left);
		if()
	}
} 

int main()
{
//	printf("%x\n",htonl(0x12345678));
	SubSet(3);
	return 0;
}
/*
int main()
{
		int arr[]={43,78,47,56,23,12,86,77,44,45};
		int len=sizeof(arr)/sizeof(arr[0]);
	//	primeBefore(arr,len);
		quiksort(arr,len);
		mypair ipair={-1,-1,false}; 
		sumToK(arr,len,35,ipair);
		if(ipair.flag)
		{
			cout<<"find! x="<<ipair.x<<"y="<<ipair.y<<endl;
		}else
		{
			cout<<"not find"<<endl;
		}
		char *brr[] = {"abc","aaa","bcd","xyz","ccccc","hhh"};
	    BubbleSort(brr,sizeof(brr)/sizeof(brr[0]),sizeof(char *),Cmp_str);
		print(arr,len);
} 
*/
