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
	//��ջ����
void SqStack::push(int val)
{
	if(full())
	{
		return;
	}
	mpstack[++mtop]=val;
}
	//��ջ����
void SqStack::pop()
{
	if(empty())
	{
		return;
	}
	--mtop;
}
	//��ȡջ��Ԫ��
int SqStack::top()
{
	if(empty())
	{
		throw "stack is empty"
	}
	return mpstack[mtop]
}
	
	//�ж�ջ��
bool SqStack::empty()
{
	return mtop==-1;
}
	//�ж�ջ��
bool SqStack::full()
{
	return mtop==msize-1;
}
