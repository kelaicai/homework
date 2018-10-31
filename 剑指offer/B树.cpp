#include<iostream>
#include<stack>
#include<queue>
#include<stdlib.h> 
#include<string.h>
using namespace std;
#define M 5
#define MAXSIZE (M-1) // ELEM 
#define MINSIZE (M/2)
typedef char KeyType;
typedef struct{ }Record;
typedef struct 
{
	KeyType key;
	Record  *recptr;
}ElemType; // key - value;
typedef struct BTNode
{
	int num;
	BTNode *parent;
	ElemType data[M+1];// 0 1 2 3 4 5
	BTNode *sub[M+1];  //  0 1 2 3 4 5
}BTNode;
typedef struct
{
	BTNode *root;
	int total;
}BTree;

typedef struct
{
	BTNode *pnode;
	int index;
	bool tag; // true; false;
}Result;

BTNode * Buynode()
{
	BTNode *s = (BTNode*)malloc(sizeof(BTNode));
	if(NULL == s) exit(1);
	memset(s,0,sizeof(BTNode));
	return s;
}
void Freenode(BTNode *p)
{
	free(p);
}
void Init_BTree(BTree *ptree)
{
	if(ptree == NULL) exit(1);
	ptree->root = NULL;
	ptree->total = 0;
}

Result FindValue(BTree *ptree,KeyType kx)
{
	Result res ={NULL,-1,false};
	if(ptree == NULL || ptree->root == NULL)
	{
		return res;
	}
	BTNode *p = ptree->root;
	while(p != NULL)
	{
		p->data[0].key = kx;
		int i = p->num;
		while(kx < p->data[i].key) --i;
		res.pnode = p;
		res.index = i;
		if(i>0 && p->data[i].key == kx)
		{
			res.tag = true;
			break;
		}
		p = p->sub[i];
	}
	return res;
}
Result Search(BTNode *ptr,KeyType kx)
{
	Result res ={NULL,-1,false};
	if(ptr != NULL)
	{
		ptr->data[0].key = kx;
		int i = ptr->num;
		while(kx < ptr->data[i].key) --i;
		res.pnode = ptr;
		res.index = i;
		if(i > 0 && ptr->data[i].key == kx)
		{
			res.tag = true;
		}
		else if(ptr->sub[i] != NULL)
		{
			res = Search(ptr->sub[i],kx);
		}
	}
	return res;
}
Result SearchValue(BTree *ptree,KeyType kx)
{
	Result res ={NULL,-1,false};
	if(ptree != NULL && ptree->root != NULL)
	{
		res = Search(ptree->root,kx);
	}
	return res;
}

BTNode * MakeRoot(ElemType x,BTNode *left,BTNode *right)
{
	BTNode *s = Buynode();
	s->parent = NULL;
	s->num = 1;
	s->data[1] = x;
	s->sub[0] = left;
	if(left != NULL) left->parent = s;
	s->sub[1] = right;
	if(right != NULL) right->parent = s;
	return s;
}

void Insert_Item(BTNode *ptr,int pos,ElemType x,BTNode *right)
{
	for(int i = ptr->num;i>pos;--i)
	{
		ptr->data[i+1] = ptr->data[i];
		ptr->sub[i+1] = ptr->sub[i];
	}
	ptr->data[pos+1] = x;
	ptr->sub[pos+1] = right;
	if(right != NULL) 
		right->parent = ptr;
	ptr->num+=1;
}
ElemType Move_Item(BTNode *ptr,BTNode *s,int pos)
{
	for(int i = pos,j = 0;i<=ptr->num;++i,++j)
	{
		s->data[j] = ptr->data[i];
		s->sub[j] = ptr->sub[i];
		if(s->sub[j] != NULL)// BRCH LEAF
		{
			s->sub[j]->parent = s;
		}
	}
	ptr->num = MINSIZE;
	s->num = MINSIZE;
	s->parent = ptr->parent;
	return s->data[0];

}
BTNode *Splice(BTNode *ptr)
{
	BTNode *s = Buynode();
	ElemType x = Move_Item(ptr,s,MINSIZE+1);
	if(ptr->parent == NULL)
	{
		return MakeRoot(x,ptr,s);
	}
	///////////////////////////
	ptr = ptr->parent;
	int pos = ptr->num;
	ptr->data[0] = x;
	while(x.key < ptr->data[pos].key) --pos;
	Insert_Item(ptr,pos,x,s);
	if(ptr->num > MAXSIZE)
	{
		return Splice(ptr);
	}
	else
	{
		return NULL;
	}
}
bool Insert(BTree *ptree,ElemType x)
{
	if(ptree == NULL)
		return false;
	if(ptree->root == NULL)
	{
		ptree->root = MakeRoot(x,NULL,NULL); // root left;
		ptree->total+=1;
		return true;
	}
	Result res = FindValue(ptree,x.key);
	if(res.pnode == NULL || res.tag)
		return false;
	BTNode *ptr = res.pnode;
	int pos = res.index;
	Insert_Item(ptr,pos,x,NULL);
	ptree->total +=1;
	if(ptr->num > MAXSIZE)
	{
		BTNode *newroot = Splice(ptr);
		if(newroot != NULL)
		{
			ptree->root = newroot;
		}
	}
	return true;
}


void Print_T(BTNode* pnode)
{
	if(pnode==NULL)
	{
		Print_T(pnode->sub[0]);
		for(int i=0;i<pnode->num;i++)
		{
			cout<<pnode->data[i].key<<endl;
			Print_T(pnode->sub[i]);
		}
		
	}
}
void Print(BTree *ptree)
{
	if(ptree==NULL)
	return ;
	
	Print_T(ptree->root); 
}

BTNode* prev_T(BTNode * ptr,BTNode* node)
{
	if(ptr!=NULL && ptr->sub[node->num]!=NULL)
} 
BTNode* Prev(BTree *ptree,BTNode* node)
{
	if(ptree==NULL || ptree->root==NULL )  return NULL;
	
	Prev_T();
}

BTNode* Next(BTree *ptree,BTNode* node)
{
	
}
bool Remove(BTree *ptree,KEYTYPE kx)
{
	if(ptree==NULL || ptree->root==NULL)
	return flase;
}

int main()
{
	KeyType ar[]={"qwertyuiopasdfghjklzxcvbnm"};
	int n = sizeof(ar)/sizeof(ar[0]) - 1;
	ElemType x;
	BTree myt;
	Init_BTree(&myt);
	for(int i = 0;i<n;++i)
	{
		x.key = ar[i];
		x.recptr = NULL;
		cout<<Insert(&myt,x);
	}                                                                                      
	return 0;
}

