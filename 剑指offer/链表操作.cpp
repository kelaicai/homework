#include<iostream>
using namespace std;

typedef struct LinkList
{
	int val;
	struct LinkList *pnext;	
} LinkList;

void addListTail(LinkList **head,int data)
{
	LinkList *node=new LinkList;
	node->pnext=NULL;
	node->val=data;
	
	if(*head==NULL)
	{
		*head=node;
	}
	else
	{
		LinkList* ptr=*head;
		while(ptr!=NULL)
		{
			ptr=ptr->pnext;
		}
		ptr->pnext=node;
	}
}

void removeNode(LinkList **phead,int value)
{
	if(phead==NULL && *phead==NULL)
	{
		return ;
	}
	LinkList *pRemoveNode=NULL;
	
	if((*phead)->val==value)
	{
		pRemoveNode=*phead;
		*phead=(*phead)->pnext;
	} 
	else
	{
		LinkList *node=*phead;
		while(node->pnext!=NULL 
		&& node->pnext->val!=value)
		{
			node=node->pnext;	
		} 
		
		if(node->pnext!=NULL
		 && node->pnext->val==value)
		{
			pRemoveNode=node->pnext;
			node->pnext=node->pnext->pnext;
	    }
	    
	    if(pRemoveNode!=NULL)
		{
			delete pRemoveNode;
			pRemoveNode=NULL;		
		}     
	} 
}
int main()
{
	LinkList *phead;
	phead->pnext=NULL;
	phead->val=0;
	
	addListTail(&phead,12);
	addListTail(&phead,15);
	addListTail(&phead,67);
	addListTail(&phead,89);
	
	removeNode(&phead,15);
	
	
	
	return 0;
}
