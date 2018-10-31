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
		printf("�ձ�\n");
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

	Link_ptr pre=head->next;  //������һ���ڵ�ĵ�ַ 
	Link_ptr cur=NULL;   //��ǰҪ��ת�Ľڵ� 
	Link_ptr nx_tmp=pre->next; //�����������ڵ���ת��ʱ�򱣴���һ�ڵ�ĵ�ַ 
	
	while(pre->next)  //pre->next���ֱ�ӱ�head->nextָ�� 
	{
		nx_tmp=pre->next;   //��ǰҪ�޸ĵĽڵ��nextֵ���ѵ�ǰҪ��ת�Ľڵ����һ���ڵ��ַ�������� 
		pre->next=cur;  //����ڵ��nextָ��ǰ��ڵ� 
		cur=pre;  //��ǰ�ڵ������һ����ת�Ľڵ� 
		pre=nx_tmp;  //preָ����һ��ʣ��δ��ת�����е�Ԫ�� 
	}
	pre->next=cur;  //���һ���ڵ��nextָ�����ڶ����ڵ� 
	cur=pre;  //��ǰ�ڵ������һ����ת�Ľڵ�  
	while(cur)  //ʹ��cur����ԭ���ĵ�һ���ڵ� 
	{
		if(cur==head->next)
		{
			cur->next->next==NULL;
		}
		cur=cur->next;
	}
    head->next=pre;
    
}

/*�Ż���ת*/
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
		cur->next=pre;   //��ǰ�ڵ��nextָ��ǰһ���ڵ�
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
	
	printf("��תǰ\n"); 
	Linked_show(head);
	printf("\n");
	/*
	ReverseLink(head);
	printf("��ת��\n");
	*/
	ReverseLink_ex(head);
	printf("��ת��\n");
	
	Linked_show(head);
	return 0;	
} 
