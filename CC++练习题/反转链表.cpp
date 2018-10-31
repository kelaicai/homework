#include<iostream>

using namespace std;

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

class  Linked
{
	public :
		Linked()
		{
			head.data=0;
			head.next=NULL;
		}
		
		
		void add(int data)
		{
			Node *ptr=head.next;
			if(ptr==NULL)
			{
				ptr=new Node;
				ptr->data=data;
				ptr->next=head.next;
				head.next=ptr;
			}
			else
			{
				while(ptr->next!=NULL)
				{
					ptr=ptr->next;
					cout<<"hel"<<endl;
				}
			
				Node *s=new Node;
				s->data=data;
				ptr->next=s;
				s->next=NULL;	
				
			} 
			
		
		}
		 
				 
		~Linked()
		{
			if(head.next==NULL)
			{
				;
			}
			else
			{
				 	cout<<"lik"<<endl; 
				    Node* ptr=head.next;
					while(ptr!=NULL)
					{
						head.next=ptr->next;
						if(ptr->next!=NULL)
						{
							delete ptr;
						}
						ptr=head.next;
					}
					ptr->next=NULL;
					ptr=NULL;
			}
		 
		} 
		
		Node* reverse()
		{
			if(head.next==NULL)
			{
				return head.next;
			}
			
				Node *cur=head.next;
				Node *pre=&head;
				Node *tmp=NULL;
				
				pre->next=NULL;
				while(NULL!=cur->next)
				{
					tmp=cur;
					tmp->next=pre;
					pre=tmp;
					
					cur=cur->next;
				}
				return tmp;	
		}
		
		void display()
		{
			if(head.next==NULL)
			{
				cout<<"endl"<<endl;
				return ;
			}
			
			Node *ptr=head.next;
			while(NULL!=ptr)
			{
				cout<<" "<<ptr->data; 
				ptr=ptr->next;
			}
			cout<<endl; 
		}
	private:
		Node head;
}; 


int main()
{
	Linked link;
	link.add(1);
	link.add(2);
	link.add(3);

	link.display();
		cout<<"hello"<<endl;
  /*Node *p=link.reverse();
	
	while(p)
	{
		cout<<" "<<p->data;
		p=p->next;
	}
	*/
	return 0;
}
