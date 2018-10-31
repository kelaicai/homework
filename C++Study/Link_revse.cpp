#include<stdio.h>
#include<stdlib.h>
typedef struct Linked
{
	int data;
	struct Linked* next;
}Linked;

typedef Linked* Link_ptr;

void init_Link(Link_ptr head)
{
	head->next=NULL;
}

bool inset_head(Link_ptr head,int val)
{
	Link_ptr s=(Link_ptr)malloc(sizeof(val));
	s->data=val;
	s->next=head->next;
	head->next=s;
}

bool insert_tail(Link_ptr head,int val)
{
	Link_ptr s=(Link_ptr )malloc(sizeof(val)); 
	s->data=val;
	s->next=NULL; 
	if(head->next==NULL)
	{
		head->next=s;
		return true;
	}
	else
	{
		Link_ptr ptr=head->next;
		while(ptr->next)
		{
			ptr=ptr->next;
		}
		ptr->next=s;
		return true;
	}
}

void Linked_show(Link_ptr head)
{
	if(head->next==NULL)
	{
		printf("空表\n");
		return;
	}
	else
	{
		Link_ptr ptr=head->next;
		while(ptr)
		{
			printf("  %d",ptr->data); 
			ptr=ptr->next;
		}
	}
}
void Destory(Link_ptr head)
{
	if(head->next==NULL)
	{
		return;
	}
	Linked* ptr=head->next;
	while(ptr)
	{
		head->next=ptr->next;
		free(ptr);
		ptr=head->next;
	}
	printf("destory success!\n");
}

void ReverseLink(Link_ptr head)
{

	Link_ptr pre=head->next;  //保存下一个节点的地址 
	Link_ptr cur=NULL;   //当前要反转的节点 
	Link_ptr nx_tmp=pre->next; //在相邻两个节点逆转的时候保存下一节点的地址 
	
	while(pre->next)  //pre->next最后将直接被head->next指向 
	{
		nx_tmp=pre->next;   //当前要修改的节点的next值，把当前要反转的节点的下一个节点地址保存下来 
		pre->next=cur;  //后面节点的next指向前面节点 
		cur=pre;  //当前节点成了下一待反转的节点 
		pre=nx_tmp;  //pre指向下一个剩余未反转链表中的元素 
	}
	pre->next=cur;  //最后一个节点的next指向倒数第二个节点 
	cur=pre;  //当前节点成了下一待反转的节点  
	while(cur)  //使用cur是找原来的第一个节点 
	{
		if(cur==head->next)
		{
			cur->next->next==NULL;
		}
		cur=cur->next;
	}
    head->next=pre;
    
}

/*优化反转*/
void  ReverseLink_ex(Link_ptr head)
{
	Link_ptr newHead=NULL;
	Link_ptr cur=head->next;
	Link_ptr pre=NULL;
	while(cur)
	{
		Link_ptr nx_tmp=cur->next;
		if(nx_tmp==NULL)
		{
				newHead=cur;
		}
		cur->next=pre;   //当前节点的next指向前一个节点
		pre=cur;
		cur=nx_tmp; 
	}
	head->next=newHead;
}
int main()
{
	Linked s={0,NULL};
	Link_ptr head=&s;
	init_Link(head);
	insert_tail(head,10);
	insert_tail(head,11);
	insert_tail(head,12);
	insert_tail(head,13);
	
	printf("反转前\n"); 
	Linked_show(head);
	printf("\n");
	/*
	ReverseLink(head);
	printf("反转后\n");
	*/
	ReverseLink_ex(head);
	printf("反转后\n");
	
	Linked_show(head);
	return 0;	
} 
