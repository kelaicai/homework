#include<iostream>

using namespace std;
bool findNum(int *matrix,int rows,int cols,int num)
{
	bool find=false;
	
	if(matrix!=NULL && rows>0 && cols>0) 
	{
		int row=0;
		int col=cols-1;
		
		while(row<rows && col>=0) 
		{
			if(matrix[row*col+col]==num)
			{
				find=true;
				break;
			} 
			else if(matrix[row*col+col]>num)
			{
				col=col-1;
			}else
			{
				row+=1;
			}
		
		}
	}
	return find;
} 

int main()
{
	int a[4][4]={{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,16}};
    bool iii=findNum((int*)a,4,4,7);
	cout<<iii<<endl;
}
