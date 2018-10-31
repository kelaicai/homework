#include<iostream>
using namespace std;

template<typename T>
class CGrid
{
	public:
	CGrid(int width=10,int height=10):mwidth(width),mheight(height)
	{
		mpCell=new T*[mwdith]; 
		for(int i=0;i<mdith;i++)
		{
			mpCell[i]=new T[mheight];
		}
		for(int i=0;i<wdith;i++)
		{
			for(int j=0;j<mheight;j++)
			{
				mpCell[i][j]=T();
			}
		}
	}
	
	~CGrid()
	{
		for(int i=0;i<mwidth;i++)
		 {
		 	delete[] mpCell[i];
		 }
		 delete[] mpCell;
		 
	}
	
	CGrid(const CGrid<T> &val)
	{
	   	mwidth=val.mwidth;
		 mheight=val.mheight;
		 
		 
		 mpCell=new T*[mwith];
		 for(int i=0;i<mwidth;i++)
		 {
		 	mpCell[i]=new T[mheight];
		 }
		 
		 for(int i=0;i<mwidth;i++)
		 {
		 	for(int j=0;j<mheight;j++)
		 	{
		 		mpCell[i][j]=val.mpCell[i][j];
			 }
		 }
	}
	
	void operator=(const CGrid<T> &val)
	{
		if(this==&val)
		{
			return ;
		 } 
		 
		 for(int i=0;i<mwidth;i++)
		 {
		 	delete[] mpCell[i];
		 }
		 delete[] mpCell;
		 
		 mwidth=val.mwidth;
		 mheight=val.mheight;
		 
		 mpCell=new T[mwith]
		 for(int i=0;i<mwidth;i++)
		 {
		 	mpCell[i]=new T[mheight];
		 }
		 
		 for(int i=0;i<mwidth;i++)
		 {
		 	for(int j=0;j<mheight;j++)
		 	{
		 		mpCell[i][j]=val.mpCell[i][j];
			 }
		 }
	}
	

	
	template<typename E>
	void operator=(const CGrid<E> &val)
	{
		/*
		if(this==&val)   是不同类型 
		{
			return ;
		 } 
		 */
		 for(int i=0;i<mwidth;i++)
		 {
		 	delete mpCell[i];
		 }
		 delete mpCell;
		 
		 mwidth=val.mwidth;
		 mheight=val.mheight;
		 
		 mpCell=new T*[mwith]
		 for(int i=0;i<mwidth;i++)
		 {
		 	mpCell[i]=new T[mheight];
		 }
		 
		 for(int i=0;i<mwidth;i++)
		 {
		 	for(int j=0;j<mheight;j++)
		 	{
		 		mpCell[i][j]=val.mpCell[i][j];
			 }
		 }
	}
	
	template<typename E>
	CGrid(const CGrid<E> &val)
	{
		mwidth=val.mwidth;
		 mheight=val.mheight;
		 
		 
		 mpCell=new T*[mwith];
		 for(int i=0;i<mwidth;i++)
		 {
		 	mpCell[i]=new T[mheight];
		 }
		 
		 for(int i=0;i<mwidth;i++)
		 {
		 	for(int j=0;j<mheight;j++)
		 	{
		 		mpCell[i][j]=val.mpCell[i][j];
			 }
		 }
	}
	
	private :
		int mwidth;
		int mheight;
	
		T **mpCell;
	template<typename E>
	class friend CGrid;	
}; 

int main()
{
	
}
