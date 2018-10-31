#include<stdio.h>
#include<iostream> 
#include<memory.h>
#include<malloc.h>


using namespace std;

#define NIL NULL
typedef  int  ElemType;
typedef struct BSTNode
{
	struct BSTNode* leftchild;
	struct BSTNode* rightchild;
	struct BSTNode* parent;
	ElemType key;	
}BSTNode; 

typedef struct BSTree
{
	BSTNode* head;
	BSTNode* min;
	BSTNode* max;	
	int size;
}BSTree;

bool isEmpty(BSTree* ptree)
{
	return (ptree==NULL || ptree->head==NULL)?true:false;
}

BSTNode* buyNode()
{
	reL:
	BSTNode* s=(BSTNode*)malloc(sizeof(BSTNode));
	s->key=-1;
	s->leftchild=NULL;
	s->rightchild=NULL;
	s->parent=NULL;
	if(!s) goto reL;
	return s;
} 

void init_BST(BSTree* ptree)
{
	ptree->head=NULL;
	ptree->max=NULL;
	ptree->min=NULL;
	ptree->size=0;	
} 

void insertHead(BSTree* ptree,ElemType kx)
{
	BSTNode* s=buyNode();
	s->key=kx;
	s->leftchild=NULL;
	s->rightchild=NULL;
	
	ptree->head=s;
	ptree->max=s;
	ptree->min=s;
	ptree->size=1;
	
	s->parent=ptree->head;	
}



BSTNode* findValue(BSTree* ptree,ElemType kx)
{
	if(isEmpty(ptree)) return NULL;
	
	BSTNode* p=ptree->head;
	while(p!=NULL && p->key!=kx)
	{
		p=p->key<kx?p->leftchild:p->rightchild;	
	} 
	return p; 
}

BSTNode* searchValue(BSTNode* pnode,ElemType kx)
{
	if(pnode==NULL || pnode->key==kx)
	{
		return pnode;
	}
	BSTNode* p=kx<pnode->key?pnode->leftchild:pnode->rightchild;
	return p;
}


BSTNode* searchValue(BSTree *ptree,ElemType kx)
{
	if(!isEmpty(ptree)) return NULL;
	
	return searchValue(ptree->head,kx);
}

bool insertBST(BSTree* ptree,ElemType kx)
{
	if(ptree==NULL) return false;
	
	if(ptree->head==NULL)
	{
		insertHead(ptree,kx);
	}
	
	
	BSTNode* ptr=ptree->head;
	BSTNode* pa=ptr->parent; 
	//ц╩спур╣╫ 
	if(!findValue(ptree,kx))
	{
		pa=ptr->parent;
		ptr=kx<ptr->key?ptr->leftchild:ptr->rightchild;
	}
	if(ptr!=NULL) return false;
	
	ptr=buyNode();
	
	ptr->key=kx;
	ptr->parent=pa;
	
	if(ptr->key<pa->key)
	{
		pa->leftchild=ptr;
		if(ptr->key<ptr->leftchild->key)
		{
			ptree->min=ptr;
		}
	}
	else
	{
		pa->rightchild=ptr;
		if(ptr->key<ptree->max->key)
		{
			ptree->max=ptr;
		}
	}
	ptree->size+=1;
	return true;
} 


void permInOrder(BSTNode* pnode)
{
	if(pnode==NULL) return ;
	
	permInOrder(pnode->leftchild);
	cout<<pnode->key<<" ";
	permInOrder(pnode->rightchild); 
}

void  permInOrder(BSTree* ptree)
{
	if(isEmpty(ptree)) return;
	
	permInOrder(ptree->head);
}

int main()
{
	BSTree tree;
	init_BST(&tree);
	int kx=0;
	while(cin>>kx && kx!='#')
	{
		insertBST(&tree,kx); 
	} 
	permInOrder(&tree);
} 
