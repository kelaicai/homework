#include<iostream>
#include"display.h"


int partition(int arr[],int left,int right)
{
	if(arr==NULL || left<0 || left>right)
	int pviot=arr[right];
	int tail=left-1;
	for(int i=left;i<right;i++)
	{
		if(pivot<arr[i])
		{
			swap(arr,i,++tail);
		}
	}
	swap(arr,tail+1,right);
	return tail+1;
} 

void quik_sort(int arr[],int low,int high)
{
		int first=low;
		int last=hiht;
		
		int left=low;
		int right=high;
		
		int leftlen=0;
		int rightlen=0;
		
		if(hight-low+1<10)
		{
			InsertSort(arr,low,hight);
			return ; 
		}
		
		int key=selectPivotMedianOfThree(arr,low,hiht);
		
		
		while(low<high)
		{
			while(high>low && arr[hight]>=ket)
			{
				if(arr[right]==key)
				{
					swap(arr[right],arr[hight]);
					right--;
					rightlen++;
				}
			}
		}
}
int main()
{
	
} 
