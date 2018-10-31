#include "Link.h"
/*
int value;
Node *pnext;
*/
//构造头结点
Link::Link()
{
	phead->value=0;
	phead->pnext=NULL;
}
//释放链表
Link::~Link()
{
	if(empty())
	{
		return;
	}
	Node* ptr=phead->pnext;
	Node* tmp=phead->pnext;
	while(ptr)
	{
		ptmp=ptr;
		ptr->pnext=ptr->pnext;  //保存下一个节点的地址
		delete  ptmp;
	}
}
//头插法
void Link::insertHead(int val)
{
	Node *snode=new Node
}
//尾插法
void Link::insertTail(int val)
{

}
//删除元素
void Link::deleteNode(int val)
{
	Node* ptr=decltype phead; 
	Node* tmp=NULL;
	while(ptr->value!=val)
	{
		cout<<phead->value<<endl;
	}
	tmp=ptr;  //保存当前位置 
	ptr->pnext=tmp->pnext;  //保存被删除元素的next
	delete tmp;
}
//打印链表的
void Link::show()
{
	Node* ptr=phead->pnext; 
	while(ptr->pnext)
	{
		cout<<phead->value<<endl;
	}
}

bool Link::empty()
{
	return phead->pnext==NULL;	
} 
