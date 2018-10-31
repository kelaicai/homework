#include<iostream>
#include<string.h>
#include<assert.h>
using namespace std;

template<typename T>
class BSBase
{
public:
	virtual void push(const T &vla)  =0;
	virtual void pop() = 0;
	virtual T front() const = 0;
	virtual T back() const = 0;
	virtual void show() const =0;
};


template<typename T>
class Stack :public BSBase<T>
{
public:
	Stack();
	~Stack();

	void push(const T &val);
	void pop();
	T front() const;
	T back() const;
	void show() const ;
	
private:
	class Node
	{
	public:
		Node(T data) :mdata(data), pnext(NULL){ }
	public:
		T mdata;
		Node *pnext;   
	};
	Node *mpbottom;
	Node *mptop;
};

template<typename T>
Stack<T>::Stack() :mpbottom(NULL), mptop(mpbottom)
{
	
}
template<typename T>
Stack<T>::~Stack()
{
	if(mpbottom==NULL || mpbottom->pnext==NULL)
	{
		return;	
	} 
	else
	{
		Node *p=mpbottom;
		while(p)
		{
			mpbottom=p->pnext;
			delete p;
		    p=mpbottom;   //mp指向下一个节点 
		    cout<<"~Stack<T>()"<<endl;
		}
		mptop=NULL;
		mpbottom=NULL; 
	}
}

template<typename T>
void Stack<T>::push(const T &val)
{
	Node* p = new Node(val);
	p->mdata=val;
	p->pnext=NULL;
	if (mpbottom == NULL)
	{
		mpbottom = p;  //头指针 
		mptop = p;
		cout<<"first"<<endl;
	}
	else
	{
		mptop->pnext=p;
		cout<<"he"<<endl;
		mptop=p;
	}
}

template<typename T>
void Stack<T>::pop()
{
	if(mpbottom==NULL)
	{
		return ;     //栈内没有数据 
	}
	if(mpbottom==mptop && mptop!=NULL)  //当前为第一个节点 
	{
		delete mpbottom;
		mpbottom=NULL;
		mptop==NULL;  //
		return ;
	}
	else
	{
		T data=mptop->mdata;
		Node *p=mpbottom;
		while(p->pnext->pnext!=NULL)
		{
			p=p->pnext;
		}
		mptop=p;  //当前p就是栈顶倒数第二个元素 
		mptop->pnext=NULL; //将后面的top元素的next区置为NULL 
		p=p->pnext;  //p指向栈顶元素，即 待删除元素
		delete p;
		p=NULL; 
	}
}

template<typename T>
T Stack<T>::front() const
{
	return (T)0; 
} 

template<typename T>
T Stack<T>::back() const
{
	return (T)0;
}

template<typename T>
void Stack<T>::show() const
{
	if(mpbottom==NULL)
	{
		cout<<"此为空栈"<<endl; 
	} 
	else
	{
		Node *p=mpbottom;
		while(p)
		{
			cout<<"  "<<p-> mdata<<endl;
			p=p->pnext;
		} 
	}	
}
//特例化 
template<>
class Stack<char*>
{
	public:
	Stack();
	~Stack();

	void push(char *const val);
	void pop();
	char* front() const;
    char * back() const;
	void show() const ;
	
private:
	class Node
	{
	public:
		Node(char* const data=NULL):pnext(NULL)
		{
			assert(data!=NULL);	
			strcpy(mdata,data); 
		}
	public:
		char mdata[128];
		Node *pnext;   
	};
	Node *mpbottom;
	Node *mptop;
};

Stack<char *>::Stack():mpbottom(NULL),mptop(NULL)   //头指针 
{
		
} 

Stack<char *>::~Stack()
{
	if(mpbottom==mptop && mptop==NULL)  
	{
		return;
	}
	
	Node *_p=mpbottom;
	while(_p)
	{
		mpbottom=mpbottom->pnext;
		delete _p;
		_p=mpbottom;	
	} 
	mptop=NULL;
	cout<<"析构结束"<<endl; 
}

void Stack<char *>::push(char *const p)
{
	Node *_p=new Node(p);
	_p->pnext=NULL;
	 
	if(mpbottom==NULL)
	{
		mpbottom=_p;
		mptop=_p;
	}
	else
	{
		mptop->pnext=_p;
		mptop=_p;
	}
} 

void Stack<char *>::pop()
{
	if(mpbottom==NULL)
	{
		cout<<"栈空了"<<endl; 
		return; 
	} 
	
	Node *_p=mpbottom;
	while(_p->pnext!=mptop)
	{
		_p=_p->pnext;  
	}
	delete mptop;
	mptop=_p;
	mptop->pnext=NULL;
}

char* Stack<char*>::front() const
{
	return mptop?mptop->mdata:NULL;	
} 

char* Stack<char *>::back()  const
{
	
	return mpbottom?mpbottom->mdata:NULL;
}

void Stack<char *>::show() const
{
	
	if(mpbottom==NULL)
	{
		cout<<"空表"<<endl; 
		return ;
	}
	
	Node *_p=mpbottom;
	while(_p)
	{
		cout<<"  "<<_p->mdata<<endl;
		_p=_p->pnext; 
	} 
}
/////////////////////////////////////////////////////////////////////////////////


/*                                    队列                                  */
template<typename T>
class Queue : public BSBase<T>
{
public:
	//构造   析构   重写5个抽象方法
	Queue();
	~Queue();
	void push(const T &val);
	void pop();
	T front() const;
	T back() const;
	void show() const ;
private:
	
	class Node
	{
	public:
		Node(T data) :mdata(data), pnext(NULL){ }
	public:
		T mdata;
		Node *pnext;   
	};	
	
	Node *mpfront;
	Node *mprear;
};


template<typename T>
Queue<T>::Queue():mpfront(NULL),mprear(NULL)
{
	
}

template<typename T>
Queue<T>::~Queue()
{
	if(mpfront==NULL)
	{
		return;
	}
	else
	{
		Node *p=mpfront;
		while(p)
		{
			mpfront=p->pnext;  //front向后移动 
			delete p;
			p=mpfront;     //p也向后移动 
		}
		//防止野指针 
		mpfront=NULL;
		mprear=NULL;
	}
}

template<typename T>
void Queue<T>::push(const T &val)  //入队 
{
	Node* p=new Node(val);
	p->pnext=NULL; 
	if(mpfront==NULL && mprear==NULL)
	{
		mpfront=p;  //带头指针 
		mprear=p;
	}
	else
	{
		mprear->pnext=p;
		mprear=p;
	}
}

template<typename T>
void Queue<T>::pop()  //出队 
{
	if(mpfront==mprear && mpfront->pnext==NULL)
	{
		cout<<"现在为空表"<<endl; 
		return;
	}
	else
	{
		T data=mprear->mdata;
		if(mpfront->pnext==NULL)  //只有一个节点 
		{
			 
		}
		Node *p=mpfront;
		while(p->pnext->pnext!=NULL)
		{
			p=p->pnext;	
		}
		
		mprear=p;   //倒数第二个节点作为队尾元素
		mprear->pnext=NULL;  //队尾元素置为NULL 
		p=p->pnext;   //待删除元素
		delete p;
		p=NULL; 
	} 
}

template<typename T>
T Queue<T>::front()  const
{
	return mpfront->mdata;	
} 

template<typename T>
T Queue<T>::back() const
{
	return mprear->mdata;
}

template<typename T>
void Queue<T>::show() const
{
	if(mpfront==NULL)
	{
		cout<<"队列为空"<<endl;
		return ;
	}
	Node *p=mpfront;
	while(p)
	{
		cout<<" "<<p->mdata<<endl;
		p=p->pnext;
	}
}

template<>
class Queue<char *>
{
	public:
	//构造   析构   重写5个抽象方法
	Queue();
	~Queue();
	void push(char*const val);
	void pop();
	char* front() const;
	char* back() const;
	void show() const ;
private:
	
	class Node
	{
	public:
		Node(char* data):pnext(NULL)
		{ 
			strcpy(mdata,data);
		}
	public:
		char mdata[128];
		Node *pnext;   
	};	
	
	Node *mpfront;
	Node *mprear;
};

Queue<char*>::Queue():mpfront(NULL),mprear(NULL)
{
	
}

Queue<char*>::~Queue()
{
	if(mpfront==mprear &&mprear==NULL)
	{
		cout<<"空表"<<endl;	
	}
	Node *_p=mpfront;
	while(_p)
	{
		mpfront=_p->pnext;
		delete _p;
		_p=mpfront;	
	}	
	mprear=NULL;
} 

void Queue<char *>::push(char *const val)
{
	Node *_p=new Node(val);
	if(mpfront==NULL)
	{
		mpfront=_p;
		mprear=_p;
	}
	mprear->pnext=_p;
	mprear=_p;
}

void Queue<char*>::pop()
{
	if(mpfront==mprear && mprear==NULL)
	{
		cout<<"空表"<<endl; 
		return ;	
	} 
	
	Node *_p=mpfront;
	while(_p->pnext!=mprear)
	{
		_p=_p->pnext;
	}
	
	delete mprear;
	
	mprear=_p;
	mprear->pnext=NULL;
} 

char* Queue<char*>::front()  const
{
	return mpfront?mpfront->mdata:NULL;
}

char* Queue<char*>::back()  const
{
	return mprear?mprear->mdata:NULL;	
} 

void Queue<char *>::show() const
{
	if(mpfront==mprear && mpfront==NULL)
	{
		cout<<"空表"<<endl;
		return ;
	}
	Node *_p=mpfront;
	while(_p)
	{
		cout<<"  "<<_p->mdata<<endl;
		_p=_p->pnext;	
    }
}
int main()
{
	/*
	Stack<int>  s;
	s.push(12);
	s.push(13);
	s.push(14);
	s.push(15);
	
	s.show();
	
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.show();
	*/
	
	/*
	Queue<int> q;
	q.push(12);
	q.push(13);
	q.push(15);
	
	q.show();

	q.pop();
	q.pop();
	
	q.show();
    q.pop();
    */
	
	/*
	Stack<char *> chStack;
	chStack.push("abc");
	chStack.push("bcd");
	chStack.push("123");
	cout<<chStack.back()<<endl;
	cout<<chStack.front()<<endl;
    chStack.show();	
    chStack.pop();
    chStack.show(); 
    */
    /*
    Queue<char *> strQue;
    strQue.push("123");
    strQue.push("223");
	strQue.push("323"); 
	
	cout<<strQue.back()<<endl;
	cout<<strQue.front()<<endl;
	strQue.show();
	*/
	
}
