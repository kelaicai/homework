#ifdef SWAP_H
#define SWAP_H

template<typename T>
void swap(T arr[],int i,int j)
{
	T tmp=arr[i];
	arr[i]=arr[j];
	arr[j]=tmp;
}

template<typename T>
void display(T a[],T len)
{
	for(int i=0;i<len;++i)
	{
		cout<<a[i]<<" "<<endl;
	}
	cout<<endl;
}
#endif
