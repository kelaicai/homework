#include"Queue.h" 
/*
    int *mpQue;
	int msize;
	int mfront;
	int mrear;
*/



CircleQue::CircleQue(int size=10)
{
	msize=size;
	mfront=0;
	mrear=msize-1;
	mpQue=new int[msize];	
} 



CircleQue::CircleQue(const CircleQue &src)
{
	
}

CircleQue::~CircleQue()
{
	delete[] mpQue;
	mfront=0;
	mrear=0;
}

bool CircleQue::full()
{
	return mfront==(mrear+1)%msize;
}

bool CircleQue::empty()
{
	return (mrear+1)%msize==mfront;
}

void CircleQue::addQue(int val)
{
	if(full())
	{
		return ;
	}
	mpQue[(++mfront)%msize]=val;
} 

void CircleQue::delQue()
{
	if(empty())
	{
		return;
	} 
	mfront=mrear;
}

int CircleQue::front()
{
	int tmp=0;
	if(empty())
	{
		return;
	}
	tmp=mpQue[(front)%msize]
} 



int CircleQue::rear()
{
	
}

CircleQue::operator=(const CircleQue &src)
{
	
}


