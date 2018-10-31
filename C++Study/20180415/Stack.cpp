#include "Stack.h"


/*    member vars
	int *mpstack;
	int mtop;
	int msize;

*/
SqStack::SqStack(int size = 10)
{
	 msize=size;
	 mtop=-1;
	 mpstack=new int[msize];
} 
SqStack::~SqStack()
{
	delete[] mpstack;
	mtop=-1;
	msize=0;
}
	//ÈëÕ»²Ù×÷
void SqStack::push(int val)
{
	if(full())
	{
		return;
	}
	mpstack[++mtop]=val;
}
	//³öÕ»²Ù×÷
void SqStack::pop()
{
	if(empty())
	{
		return;
	}
	--mtop;
}
	//»ñÈ¡Õ»¶¥ÔªËØ
int SqStack::top()
{
	if(empty())
	{
		throw "stack is empty"
	}
	return mpstack[mtop]
}
	
	//ÅÐ¶ÏÕ»¿Õ
bool SqStack::empty()
{
	return mtop==-1;
}
	//ÅÐ¶ÏÕ»Âú
bool SqStack::full()
{
	return mtop==msize-1;
}
