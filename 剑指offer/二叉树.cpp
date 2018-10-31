#include<iostream> 
#include<stack> 
#include<queue> 
using namespace std;


namespace BinaryTreeS{
struct Node;
void init();
static Node* buyNode(int val);
struct Node
{
	int  val;
	struct Node* leftchild;
	struct Node* rightchild;
	struct Node* parent;	
}; 

struct BinaryTree{
	Node* head;
	int count;
};

static void init(BinaryTree* tree)
{
	tree->head=buyNode(0);
	tree->head=NULL;
	tree->count=0;
}

static Node* buyNode(int val)
{
	Node* s=(Node*)malloc(sizeof(Node));
	s->leftchild=NULL;
	s->rightchild=NULL;
	s->parent=NULL;
	s->val=val;
	return s;
}


static Node* insert()
{
	
	Node* p=NULL;
	int x;
	cin>>x;
	if(x!=-1)
	{
		p=buyNode(x);
		p->leftchild=insert();
		p->rightchild=insert();
	}
	return p;
}

static void perm_pre_real(Node* tnode)
{
	if(tnode==NULL) return ;
	
	cout<<tnode->val<<" ";
	perm_pre_real(tnode->leftchild);
	
	perm_pre_real(tnode->rightchild);
}

static void perm_pre(BinaryTree *tree){
	if(tree==NULL || tree->head==NULL)  return ;
	cout<<"permutation"<<endl;
	perm_pre_real(tree->head); 
	cout<<endl;
	
}

static void per_in_real(Node* node)
{
	if(node==NULL)  return; 
	
	per_in_real(node->leftchild);
	cout<<node->val<<" ";
	per_in_real(node->rightchild);
	
} 
static void perm_in(BinaryTree* tree)
{
	if(tree==NULL)  return ;
	cout<<"Permutation in"<<endl;
	per_in_real(tree->head);
	cout<<endl;
}

static void perm_last_real(Node* tnode)
{
	if(tnode==NULL)  return;
	
	perm_last_real(tnode->leftchild);
	perm_last_real(tnode->rightchild);	
	cout<<tnode->val<<" ";
}

static void perm_last(BinaryTree* tree)
{
	if(tree==NULL)  return ;
	
	cout<<"Permutation last"<<endl;
	perm_last_real(tree->head);
	cout<<endl;
}

static void iterator_pre()
{
	
}

static void iterator_in()
{
	
}

static void iterator_last()
{
	
}

};

using namespace BinaryTreeS;
int main()
{
	BinaryTree tree;
	init(&tree);
	tree.head=insert();
	perm_pre(&tree);
	perm_in(&tree);
	perm_last(&tree);
}
