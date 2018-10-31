void binarysort(int a[],int n)  //a是数组名，n是元素个数
{
	int i=0;
	int j=0;
	for(i=2;i<n;i++)
	{
		a[0]=a[i];
		int low=1;
		int high=i-1;
		while(low<high)
		{
			int mid=(low+high)/2;
			if(a[i]<a[mid])
			{
				high=mid-1;
			}
			else{
				low=high+1;
			}
		}
		for(j<i-1;j>=high+1;--j)
		{
			a[high+1]=a[0];
		}
	}
}
void insertsort(int a[],int n)
{
	int i=0;
	int j=0
	for(i=2;i<n;i++)
	{
		j=i-1;
	    while(a[0]<a[j])
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=a[0];
	}
}
void binaysort(int a[],int n)
{
	int i=0;
	int j=0;
	for(i=2;i<n;i++)
	{
		int x=a[i];
		int low=1;
		int high=i-1;
		while(low<high)
		{
			int mid=(low+high)/2;
			if(x<a[mid])
			{
				high=mid-1;
			}
			else
			{
			low=mid+1;	
		    }
		}
		for(j=i-1;j>=low;j--)
		{
			a[j+1]=a[j];
		}
		a[low]=x;
	}
}