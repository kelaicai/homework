#include "Link.h"
/*
int value;
Node *pnext;
*/
//����ͷ���
Link::Link()
{
	phead->value=0;
	phead->pnext=NULL;
}
//�ͷ�����
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
		ptr->pnext=ptr->pnext;  //������һ���ڵ�ĵ�ַ
		delete  ptmp;
	}
}
//ͷ�巨
void Link::insertHead(int val)
{
	Node *snode=new Node
}
//β�巨
void Link::insertTail(int val)
{

}
//ɾ��Ԫ��
void Link::deleteNode(int val)
{
	Node* ptr=decltype phead; 
	Node* tmp=NULL;
	while(ptr->value!=val)
	{
		cout<<phead->value<<endl;
	}
	tmp=ptr;  //���浱ǰλ�� 
	ptr->pnext=tmp->pnext;  //���汻ɾ��Ԫ�ص�next
	delete tmp;
}
//��ӡ�����
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
