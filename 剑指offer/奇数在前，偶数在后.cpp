#include<stdio.h>
#include"display.h" 
using namespace std;

void before(int arr[],int len)
{
	if(arr==NULL || len<0) return;
	
	int i=0;
	int j=0;
	
	while(i<len)
	{
		if(arr[i]%2==0)
		{
			swap(arr,i,j); 
			i++;
			j++;
		}
		i++;
	}
}

int main()
{
		int arr[]={1,2,3,4,5,6,7,8,9};
		before(arr,sizeof(arr)/sizeof(arr[0]));
		display<int>(arr,sizeof(arr)/sizeof(arr[0]));
}
