
/*
����ƽ̨  dev C++,��ɶ���ⲩ��ֱ����� 
*/
#include<iostream>
#include<ctime>
#include<stdlib.h> 
using namespace std; 
struct Node
{
	int data;
	Node* next;
};



class Linked
{
	private:


	Node *plist;
	int len;
	public :  
	//Linked���캯����ɶ��ڵ�����ĳ�ʼ�� 
	Linked(int _data=0,Node* _next=NULL):plist(NULL),len(0)
	{
		
	}
	/*
	void InitList()
	{
		
	}
	*/
	
	bool Insert_head(int val)
	{
		Node* tmp=new Node;
		tmp->data=val;
		tmp->next=NULL;
		if(!plist)
		{
			plist=tmp;
		}
		else
		{
			tmp->next=plist;  
			plist=tmp;
		} 
		
		return true;
	} 
	
	bool Insert_tail(int val)
	{
		Node* tmp=new Node;
		tmp->data=val;
		tmp->next=NULL;
		if(plist==NULL)
		{
			plist=tmp;	
		}
		else
		{
			Node* ptr=plist;
			while(ptr->next)
			{
				ptr=ptr->next;
			} 
			
			ptr->next=tmp;
		}
		return true;
	}		
	
	bool Insert_pos(int pos,int val)
	{
		if(pos<0)
		{
			return false;
		}
		
		Node* tmp=new Node;
		tmp->data=val;
		if(isEmpty() || pos==0)
		{
			cout<<"��ǰΪ�ձ�,���Ѹýڵ���Ϊ�׽ڵ�"<<endl;
			plist=tmp;
			return true;
		}
		
		int len=Length();
		if(pos>len)
		{
			cout<<"����λ�ô��������ȣ����ǽ������β��"<<endl; 
			Node* ptr=plist;
			while(ptr->next)
			{
				ptr=ptr->next;
			}
			ptr->next=tmp;
			return true;
		}
		//Linked��������Ԫ�� 
		Node* ptr=plist;
		for(int i=0;i<pos-1 && ptr->next!=NULL;i++)
		{
			ptr=ptr->next;
		}
		
		tmp->next=ptr->next;
		ptr->next=tmp;
		 
		return true;
	}
	
	Node* Search_pre(int key)
	{
		if(isEmpty())
		{
			return NULL;
		}
		
		Node* ptr=plist;
		while(ptr->next)
		{  //ptr->next��Ϊ�� ���������Ȼ�������NULL 
			if(ptr->next->data==key)
			{
				return ptr;
			}
			ptr=ptr->next;
		}
		//ѭ�����˻�û�У�����key���������� 
		return NULL; 
	}
	
	bool Delete(int key)
	{
		if(isEmpty())
		{
			return false;
		}
		
		
		//Ҫɾ����Ԫ��Ϊ��һ��Ԫ�� 
		if(plist->data==key)
		{
			Node* ptr=plist->next;
			delete plist;
			plist=ptr;
			return true;
		}
		
		Node* ptr_pre=plist->next;
		Node* ptr_cur=plist;
		
	
		while(ptr_pre)
		{
			if(ptr_pre->data==key)
			{
				Node *tmp=ptr_pre->next;
				delete ptr_cur->next;
				ptr_cur=tmp;
				return true;
			}
			ptr_pre=ptr_pre->next;
			ptr_cur=ptr_cur->next; 
		}
		//������û�нڵ� 
		return false;
		
	} 
	
	bool isEmpty()
	{
		return plist==NULL;
	}
	~Linked()
	{
		Destroy();
	}
	
	void Destroy()
	{
		if(isEmpty())
		{
			return;
		}
		
		Node* ptr=plist;
		Node* tmp=plist;  //������һ����ɾ���ڵ��λ��
		while(tmp)
		{
			tmp=tmp->next;
		/*	if(ptr==NULL)
			{
				return;
	    	} */
			delete ptr;
			ptr=tmp;	
			cout<<"hello"<<endl;
		}	
		plist=NULL;  //��������֮��plist�ÿգ���ֹҰָ�� 
	}
	
	
	
	int Length()
	{
		if(isEmpty())
		{
			return 0;
		} 
		
		Node* ptr=plist;
		int count=0;
		while(ptr)
		{
			ptr=ptr->next;
			count++;
		}
		return count;	
	} 
	
	void Show()
	{
		if(isEmpty())
		{
			cout<<"�ձ�"<<endl; 
			return;	
		} 
		//����л�����Ϊ�޻� 
		if(isLoop())
		{
			loop2unloop();
		}
		Node* ptr=plist;
		while(ptr)
		{
			cout<<ptr->data<<" ";
			ptr=ptr->next; 
		}
		cout<<endl;
	}
	
	void Reverse()
	{
		if(isEmpty())
		{
			cout<<"�ձ�"<<endl; 
			return ;	
		} 
		Node* pre=plist;
		Node* cur=NULL;
		while(pre)
		{
		 	Node *pNext=pre->next;
			 if(!pNext)  //pNext==NULL 
			 {
			 	plist=pre; 
		     }
		     
		     pre->next=cur;  //pre�ǵ�������ָ�� 
		     cur=pre;   //���µ�ǰ������ƶ����Ѿ�������½ڵ� 
		     pre=pNext;  //preָ����һ��Ҫ����Ľڵ� 
		}		 
	}
	
	bool create_3LoopLink()
	{
		if(isEmpty())
		{
			cout<<"�ձ�"<<endl;
			return false;	
		}		
		
		Node* ptr=plist;
		while(ptr->next)
		{
			ptr=ptr->next;	
		}
		
		Node* step=plist;
		int len=Length();
		cout<<"len="<<len<<endl;
		for(int i=1;i<len-3 && step!=NULL ;i++)  //
		{ 
			step=step->next;	//һ��Ԫ�����Ի� 
		} 
		
		ptr->next=step;  //�����һ��Ԫ�ص�Nextָ����Ԫ�� 
		return true;  
	} 
	
	bool isLoop()
	{
		if(isEmpty())
		{
			cout<<"�ձ�"<<endl;	
			return false;
		} 
		
		//����Ԫ�سɻ� 
		if( plist->next!=NULL && plist==plist->next )
		{
			return true;
		}
		else if(plist->next==NULL)
		{
			return false;
		}
		
		for(Node *fast=plist->next->next,*low=plist;
		fast && fast->next ;
		fast=fast->next->next,low=low->next)
		{
			if(fast==low)
			{
				return true;	
			}	
		}	
		return false;
	} 
	
	int GetLoopLen()
	{
		if(isEmpty())
		{
			cout<<"�ձ�"<<endl;
			return 0;
		}
		
		if(!isLoop())
		{
			return -1;
		}
				
		//����Ԫ�سɻ� 
		if(plist==plist->next)
		{
			return 0;
		}
		int len=1;  //����Ԫ���Ի����� 
		for(Node *fast=plist->next->next,*low=plist;
		fast && fast->next ;
		fast=fast->next->next,low=low->next)
		{
			if(fast==low)
			{
				low=low->next;
				while(low!=fast)
				{
					low=low->next;
					len++;
				}
				break;
			}	
		}	
		return len;
		
	}
	
	bool loop2unloop()
	{
		if(isEmpty())
		{
			cout<<"�ձ�"<<endl; 
			return false;
		}
		
		if(!isLoop())
		{
			return false;
		}
		//��Ԫ���Ի� 
		if(plist==plist->next)
		{
			plist->next=NULL;
			return true;
		}
		
		
		//���ڿ�ʼ�������������ڵ� 
		Node* fast=plist->next->next,*low=plist;
		for(;fast!=low;fast=fast->next->next,low=low->next)
		{
			; //�ҳ����� 
		}
		
		low=low->next;//�������ƶ�һ�� 
		for(;low->next!=fast;low=low->next)
		{
							
		} 
		low->next=NULL;
	}
	//�����ӡ������
	void rePrintLink(Node *ptr)
	{
		if(!ptr)
		{
			return;
		}
		else
		{
		    rePrintLink(ptr->next);
		    cout<<ptr->data<<" ";
		}	
	} 
	
	Node* GetPList()
	{
		return plist;
	}
	/*
	
	Linked& mk2unionLink(Linked& link)
	{
		if(link.isEmpty())
		{
			return *this;
		}
		
		Node* ptr=link.GetPList();
		
		for() 
		
	*/
	/*
		�����󽻵�
		 
	*/
	
	bool isUnionLink(Linked& link)
	{
		
		//�п� 
		if(isEmpty() || link.isEmpty())
		{
			return false;
		}
		
		int len=Length()-link.Length();
		Node* this_ptr=plist;
		Node* other_ptr=link.GetPList();
		if(len=0)    //������ȣ�����Ƚ� 
		{
			for(;this_ptr;
			this_ptr=this_ptr->next,other_ptr=other_ptr->next)
			{
				if(this_ptr==other_ptr)
				{
					return true;	
				} 
			}	
			//����������δ�ȣ�˵���޽��� 
			return false;
		}
		else if(len>0)  //��ǰ����ȴ��ƽ����� 
		{                  //int index=0;   �󽻵� 
			for(int i=0;i<len;i++)
			{
				this_ptr=this_ptr->next;	
			} 
			//
			for(;other_ptr;   //����other_ptr�ĳ���С��this_ptr������other_ptr�ĳ���Ϊ�޶� 
			this_ptr=this_ptr->next,other_ptr=other_ptr->next)
			{
				if(this_ptr==other_ptr)
				{
					return true;	//return this_ptr 
				} 
			}	
			//����������δ�ȣ�˵���޽��� 
			return false;
		} 
		else             //other_ptr�ĳ��ȴ���this_ptr�ĳ��� ��������������� 
		{
			for(int i=0;i<len;i++)
			{
				other_ptr=other_ptr->next;	
			} 
			//
			for(;this_ptr;   //����other_ptr�ĳ���С��this_ptr������other_ptr�ĳ���Ϊ�޶� 
			this_ptr=this_ptr->next,other_ptr=other_ptr->next)
			{
				if(this_ptr==other_ptr)
				{
					return true;	//return this_ptr 
				} 
			}	
			//����������δ�ȣ�˵���޽��� 
			return false;           //return NULL 
		} 
	}
	
	//��ȡ������k���ڵ� 
	Node* getReK(int k)
	{
 
		//�Ϸ��ж� 
		if(isEmpty() || k<=0 || Length()-k<0 )  //k����С�ڱ� 
		{
			return NULL;  
		}

    	if(plist->next==NULL || k-Length()==0)  //��һ���ڵ� 
		{
			return plist; 
		}
	
		
		//���������ڵ� 
		Node* ptr=plist;
		Node* low=plist;
		int tmp=k;
		/*
		1+k <=> len-k �����������len/2�ǶԳƵ� 
		*/
		for(; ptr && ptr->next && tmp--;ptr=ptr->next);  //����K�� 
		for(;ptr;ptr=ptr->next,low=low->next); //һ���� 
		return low;
		
	} 
		
#if 0		//��Ȼ���ϱ�������׿� ,��������ĳ����ڴ˻��������Ϊ�ҷ���֮��ֱ�ӷ����ˣ��ڴ����
//����NULL���϶�������� 
    Node* getReK(int k)
	{
		if(plist==NULL || k==0)
		{
			return NULL;
		}
		Node *phead=plist;
		Node *pbehind=NULL;
	
		for(int i=0;i<k-1;i++)
		{
			if(phead->next)
			{
				phead=phead->next;
			}
			else
			{
				return NULL;
			}
		}
	
		while(phead->next)
		{
			phead=phead->next;
			pbehind=pbehind->next; 
		}
		return pbehind;
		} 
} 
#endif	

};

int main()
{
	Linked link;
	//srand(time(0));
	/*
	for(int i=0;i<10;i++)
	{
	//	link.Insert_head(rand()%100);
		link.Insert_tail(rand()%100);
	}
	*/
	
	for(int i=0;i<10;i++)
	{
		//link.Insert_head(i);
		link.Insert_tail(i);
	} 
	cout<<"������ӡ"<<endl; 
	link.Show();
	

	link.Reverse();
	cout<<"����"<<endl;
	 
	link.Show();
	
	cout<<"������λ�ò���30"<<endl; 
	link.Insert_pos(3,400);
	link.Show();
	
	cout<<"ɾ��9��Ԫ��"<<endl; 
	link.Delete(9);
	link.Show();
	
	cout<<"��������Ƿ��л� "<<endl;
	link.create_3LoopLink();
	cout<<link.isLoop()<<endl;
	
	cout<<"���ĳ���"<<endl;
	cout<<link.GetLoopLen()<<endl; 
	link.Show(); 
	
	cout<<"�����ӡ����"<<endl;
	link.rePrintLink(link.GetPList()); 
	cout<<endl;	
	
	Linked link2;
	cout<<"һ���ڵ�ɻ�"<<endl; 
	link2.Insert_head(1);
	cout<<link2.isLoop()<<endl;
	
	link.Destroy();
	for(int i=0;i<10;i++)
	{
		//link.Insert_head(i);
		link.Insert_tail(i);
	} 
	cout<<"������ӡ"<<endl; 
	link.Show();
	
	
	cout<<"������k���ڵ�"<<endl;
	for(int k=1;k<=link.Length();k++)
	{
		cout<<"i="<<k<<" "<<link.getReK(k)->data<<endl;	
	} 
     cout<<endl;
	
	return 0;
}
