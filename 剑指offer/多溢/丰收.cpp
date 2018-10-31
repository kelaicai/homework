#include<iostream>
#include<algorithm>
using namespace std; 

int heap[1024];

int lower_bounder(int arr[],int len,int kx)
{
	if(arr==NULL || len<0) return -1;
	int left=0,right=len;
	int pos;
	int mid;
	while(left<right)
	{
		mid=left+(right-left+1)/2;
		if(kx<arr[mid])
		{
			right=mid-1;
			pos=right;
		}
		else
		{  //kx>=arr[mid]
			left=mid;
			pos=left; 
		}
	}
	return pos+1;
}


int main()
{
	int n,m,que;
	while(cin>>n) 
	{
		for(int i=0;i<n;i++)
		{
			cin>>heap[i];
		}	
		for(int i=1;i<n;i++)
		{
			heap[i]=+heap[i-1];
		}
		cin>>m;
		while(m--)
		{
			cin>>que;
			int idx=lower_bound(heap,heap+n,que)-heap;
			cout<<idx<<endl; 
		}
	} 
}
