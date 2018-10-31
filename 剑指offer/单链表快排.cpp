#include<iostream>

using namespace std;


typedef struct node
{
	int key;
	struct node* next; 
};

node* partition(node* left,node* right)
{
	if(left==NULL || right==NULL)
	{		return NULL;
	}
	
	int data=left->key;
	node* p=left;
	node* q=p->next;
	for(;q!=NULL;q=q->next)
	{
		if(q->key<data)
		{
			swap(p->key,q->key);
			p=p->next; 
		}
	}
}
int main()
{
	
} 
