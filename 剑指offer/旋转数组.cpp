
#include"display.h"






int MinInOrder(int num[],int idx1,int idx2)
{
	int result=num[idx1];
	for(int i=idx1+1;i<=idx2;++i)
	{
		if(result>num[i])
		{
			result=num[i];
		}
	}
	return result;
 } 
//二分查找的特例  但是当idx1,idx2,idxmid相同时，会无法处理 
/*
int Min1(int num[],int length) 
{
	if(num==NULL && length<=0)
	{
		throw exception("Invalid parameters");
	}
	int idx1=0;
	int idx2=length-1;
	int idxmid=index1;
	while(num[idx1]>=num[idx2])
	{
		if(idx2-idx1==1)
		{
			idxmid=indx2;
			break;
		}
		idxmid=(idx1+idx2)/2;
		if(num[idxmid]>=num[idx1])
		{
			idx1=idxmid;
		}
		else if(num[idxmid]<=idx2)
		{
			idx2=idxmid;
		}
	}


}

*/
int Min(int num[],int length)
{
	if(num==NULL && length<=0)
	{
	//	throw new std::exception("Inalid parameters");
	}
		int idx1=0;
	int idx2=length-1;
	int idxmid=idx1;
	while(num[idx1]>=num[idx2])
	{
		if(idx2-idx1==1)
		{
			idxmid=idx2;
			break;
		}
		idxmid=(idx1+idx2)/2;
		
		if(num[idx1]==num[idx2] && num[idx1]==num[idxmid])
		{
			return MinInOrder(num,idx1,idx2);
		}
		if(num[idxmid]>=num[idx1])
		{
			idx1=idxmid;
		}
		else if(num[idxmid]<=idx2)
		{
			idx2=idxmid;
		}
	}
	return num[idxmid];
 } 
int main()
{
//	int a[]={3,4,5,1,2};
	int a[]={1,1,0,1,1}; 
	cout<<Min(a,sizeof(a)/sizeof(a[0]))<<endl;
	return 0;
	
	
}
