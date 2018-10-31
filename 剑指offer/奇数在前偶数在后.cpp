#include<iostream>
using namespace std;

void swap(int &a,int &b)
{
	a=a^b;
	b=a^b;
	a=a^b;
}

bool isEvent(int val)
{
	return (val&0x1)==0;
}
void reOrdered(int arr[],int len)
{
	if(arr==NULL || len<=0)
	{
		return ;
	}
	/*
	int *pBegin=arr;
	int *pEnd=arr+len-1;
	while(pBegin<pEnd)
	{
		while(pBegin<pEnd &&  (*pBegin & 0x1)!=0) pBegin++;
		while(pBegin<pEnd && (*pEnd &0x1)==0)  pEnd--;
		if(pBegin<pEnd)
		{
			swap(*pBegin,*pEnd);
		}
	}
	*/

	int i=0;
	int j=len-1;
	while(i<j)
	{
		while(i<j && (arr[i]&0x1)!=0)  i++;//是偶数
		while(i<j && (arr[j]&0x1)==0)  j--; //是奇数
		if(i<j)
		{
			swap(arr[i],arr[j]);
		 } 
	}

	//优化
	/*
		int *pBegin=arr;
	int *pEnd=arr+len-1;
	while(pBegin<pEnd)
	{
		while(pBegin<pEnd &&  !isEvent(*pBegin)) pBegin++;
		while(pBegin<pEnd && isEvent(*pEnd))  pEnd--;
		if(pBegin<pEnd)
		{
			swap(*pBegin,*pEnd);
		}
	} 
	*/
	
} 


template<typename T>
void display(T a[],T len)
{
	for(int i=0;i<len;++i)
	{
		cout<<a[i]<<" "<<endl;
	}
}

int main()
{
    int a[]={1,2,3,4,5}; 
    reOrdered(a,sizeof(a)/sizeof(a[0]));
    display<int>(a,5);
	return 0;
} 
