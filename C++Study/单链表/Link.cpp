
/*
编译平台  dev C++,有啥问题博哥直接提吧 
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
	//Linked构造函数完成对于单链表的初始化 
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
			cout<<"当前为空表,将把该节点作为首节点"<<endl;
			plist=tmp;
			return true;
		}
		
		int len=Length();
		if(pos>len)
		{
			cout<<"给出位置大于链表长度，考虑将其放在尾部"<<endl; 
			Node* ptr=plist;
			while(ptr->next)
			{
				ptr=ptr->next;
			}
			ptr->next=tmp;
			return true;
		}
		//Linked链表中有元素 
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
		{  //ptr->next不为空 下面语句自然不会访问NULL 
			if(ptr->next->data==key)
			{
				return ptr;
			}
			ptr=ptr->next;
		}
		//循环完了还没有，就是key不在链表里 
		return NULL; 
	}
	
	bool Delete(int key)
	{
		if(isEmpty())
		{
			return false;
		}
		
		
		//要删除的元素为第一个元素 
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
		//链表内没有节点 
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
		Node* tmp=plist;  //保存下一个将删除节点的位置
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
		plist=NULL;  //销毁链表之后plist置空，防止野指针 
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
			cout<<"空表"<<endl; 
			return;	
		} 
		//如果有环，置为无环 
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
			cout<<"空表"<<endl; 
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
		     
		     pre->next=cur;  //pre是倒序索引指针 
		     cur=pre;   //更新当前的向后移动的已经倒序的新节点 
		     pre=pNext;  //pre指向下一个要倒序的节点 
		}		 
	}
	
	bool create_3LoopLink()
	{
		if(isEmpty())
		{
			cout<<"空表"<<endl;
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
			step=step->next;	//一个元素是自环 
		} 
		
		ptr->next=step;  //将最后一个元素的Next指向环内元素 
		return true;  
	} 
	
	bool isLoop()
	{
		if(isEmpty())
		{
			cout<<"空表"<<endl;	
			return false;
		} 
		
		//单个元素成环 
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
			cout<<"空表"<<endl;
			return 0;
		}
		
		if(!isLoop())
		{
			return -1;
		}
				
		//单个元素成环 
		if(plist==plist->next)
		{
			return 0;
		}
		int len=1;  //和首元素自环区别 
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
			cout<<"空表"<<endl; 
			return false;
		}
		
		if(!isLoop())
		{
			return false;
		}
		//首元素自环 
		if(plist==plist->next)
		{
			plist->next=NULL;
			return true;
		}
		
		
		//现在开始链表至少两个节点 
		Node* fast=plist->next->next,*low=plist;
		for(;fast!=low;fast=fast->next->next,low=low->next)
		{
			; //找出交点 
		}
		
		low=low->next;//先向下移动一步 
		for(;low->next!=fast;low=low->next)
		{
							
		} 
		low->next=NULL;
	}
	//倒叙打印链表？？
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
		链表求交点
		 
	*/
	
	bool isUnionLink(Linked& link)
	{
		
		//判空 
		if(isEmpty() || link.isEmpty())
		{
			return false;
		}
		
		int len=Length()-link.Length();
		Node* this_ptr=plist;
		Node* other_ptr=link.GetPList();
		if(len=0)    //表长度相等，逐个比较 
		{
			for(;this_ptr;
			this_ptr=this_ptr->next,other_ptr=other_ptr->next)
			{
				if(this_ptr==other_ptr)
				{
					return true;	
				} 
			}	
			//遍历结束还未等，说明无交点 
			return false;
		}
		else if(len>0)  //当前链表比待计较链表长 
		{                  //int index=0;   求交点 
			for(int i=0;i<len;i++)
			{
				this_ptr=this_ptr->next;	
			} 
			//
			for(;other_ptr;   //由于other_ptr的长度小于this_ptr所以以other_ptr的长度为限度 
			this_ptr=this_ptr->next,other_ptr=other_ptr->next)
			{
				if(this_ptr==other_ptr)
				{
					return true;	//return this_ptr 
				} 
			}	
			//遍历结束还未等，说明无交点 
			return false;
		} 
		else             //other_ptr的长度大于this_ptr的长度 ，上面情况反过来 
		{
			for(int i=0;i<len;i++)
			{
				other_ptr=other_ptr->next;	
			} 
			//
			for(;this_ptr;   //由于other_ptr的长度小于this_ptr所以以other_ptr的长度为限度 
			this_ptr=this_ptr->next,other_ptr=other_ptr->next)
			{
				if(this_ptr==other_ptr)
				{
					return true;	//return this_ptr 
				} 
			}	
			//遍历结束还未等，说明无交点 
			return false;           //return NULL 
		} 
	}
	
	//获取倒数第k个节点 
	Node* getReK(int k)
	{
 
		//合法判断 
		if(isEmpty() || k<=0 || Length()-k<0 )  //k必须小于表长 
		{
			return NULL;  
		}

    	if(plist->next==NULL || k-Length()==0)  //第一个节点 
		{
			return plist; 
		}
	
		
		//多余两个节点 
		Node* ptr=plist;
		Node* low=plist;
		int tmp=k;
		/*
		1+k <=> len-k 两者是相对于len/2是对称的 
		*/
		for(; ptr && ptr->next && tmp--;ptr=ptr->next);  //先走K步 
		for(;ptr;ptr=ptr->next,low=low->next); //一块走 
		return low;
		
	} 
		
#if 0		//当然书上比这个简单易看 ,但是书里的程序在此会崩溃，因为我返回之后直接访问了，在此如果
//返回NULL。肯定会崩溃的 
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
	cout<<"正常打印"<<endl; 
	link.Show();
	

	link.Reverse();
	cout<<"逆序"<<endl;
	 
	link.Show();
	
	cout<<"第三个位置插入30"<<endl; 
	link.Insert_pos(3,400);
	link.Show();
	
	cout<<"删除9号元素"<<endl; 
	link.Delete(9);
	link.Show();
	
	cout<<"检测链表是否有环 "<<endl;
	link.create_3LoopLink();
	cout<<link.isLoop()<<endl;
	
	cout<<"环的长度"<<endl;
	cout<<link.GetLoopLen()<<endl; 
	link.Show(); 
	
	cout<<"倒叙打印链表"<<endl;
	link.rePrintLink(link.GetPList()); 
	cout<<endl;	
	
	Linked link2;
	cout<<"一个节点成环"<<endl; 
	link2.Insert_head(1);
	cout<<link2.isLoop()<<endl;
	
	link.Destroy();
	for(int i=0;i<10;i++)
	{
		//link.Insert_head(i);
		link.Insert_tail(i);
	} 
	cout<<"正常打印"<<endl; 
	link.Show();
	
	
	cout<<"倒数第k个节点"<<endl;
	for(int k=1;k<=link.Length();k++)
	{
		cout<<"i="<<k<<" "<<link.getReK(k)->data<<endl;	
	} 
     cout<<endl;
	
	return 0;
}
