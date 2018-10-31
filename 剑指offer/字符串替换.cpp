#include<iostream>
#include<list>
#include<ctime> 
#include<stack>
#include<stdlib.h>
#include<queue>
using namespace std;
using std::exception;

//两个栈实现一个队列 
struct ListNode
{
	int m_nkey;
	ListNode* m_pnext;
};


template<typename T>
class CQueue
{
	public:
	CQueue(void);
	~CQueue(void);
	void appendTail(const T & node);
	T DeleteHead();
	private:
		stack<T> stack1;
		stack<T> stack2;
};

template<typename T>
void CQueue<T>::appendTail(const T& element)
{
	stack1.push(element);
}
//倒序打印链表 

template<typename T>
T CQueue<T>::DeleteHead()
{
	if(stack2.size()<=0)
	{
		while(stack1.size()>0)
		{
			T& data=stack1.top();
			stack1.pop();
			stack2.push(data);
			}	
	}
	if(stack2.size()==0)
	{
	//	throw new exception("queue is empty!");	
	}
	T head=stack2.top();
	stack2.pop();
	return head;
} 

//两个队列实现一个栈
template<typename T>
class Queue_2_Stack
{
	private:
		queue<T> queue1;
		queue<T> queue2;
	public:	
	typedef T value_tyep;
	void my_push(const T &element);
	T my_pop();
}; 

template<typename T>
void Queue_2_Stack<T>::my_push(const T &element)
{
	queue1.push();
}


template<typename T>
T Queue_2_Stack<T>::my_pop()
{
	
}
void  PirntStackReverse(ListNode* phead)
{
	std::stack<ListNode*> nodes;
	ListNode* pNode=phead;
	while(pNode!=NULL)
	{
		nodes.push(pNode);
		pNode=pNode->m_pnext;
	}
	while(!nodes.empty())
	{
		pNode=nodes.top();
		printf("%d\t",pNode->m_nkey);
		nodes.pop(); 
	}
}
/*
void ReplaceBank(char string[],int length)
{
	if(string ==NULL && length<=0)
	{
		return ;	
	} 
	
	int orignal_length=0;
	int numberOfBlank=0;
	int i=0;
	while(string[i]!='\0')
	{
		++orignal_length;
		if(string[i]==' ')
		{
			++numberOfBlank;	
		}	
		++i;
	}
	
	int new_length=orignal_length+numberOfBlank*2;
	if(new_length>length)
	{
		return;
	}
	
	int indexOfOrignal=orignal_length;
	int indexOfNew=new_length;
	
	while(indexOfOrignal>=0 && indexOfNew>indexOfOrignal)
	if(string[indexOfOrignal]==' ')
	{
		string[indexOfNew--]='0';
		string[indexOfNew--]='2';
		string[indexOfNew--]='%';
	}else
	{
		string[indexOfNew--]=string[indexOfOrignal];
	}
	--indexOfOrignal;

}
*/
int main()
{
	/*
	list<int> link;
	srand(NULL);
	
	for(int i=0;i<10;i++)
	{
		link.push_back(rand()%100);
	}
	
    list<int>::iterator it=link.begin();
    for(;it!=link.end();++it)
    {
    	cout<<*it<<" ";
	}
		cout<<endl;
	link.sort();
	it=link.begin();
	  for(;it!=link.end();++it)
    {
    	cout<<*it<<" ";
	}
	*/
	queue<int> que;
	que.
	
	cout<<endl;
	return 0;
} 
