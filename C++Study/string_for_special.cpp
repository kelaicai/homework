#include<iostream>
#include<string.h> 
#include<string>
#include<stack>
using namespace std;
 
template<typename T = int>
class Link
{
public:
   	Link();
	~Link();
	void insertHead(const T &val);
	void insertTail(const T &val);
	void deleteNode(const T &val);
	void show()const;
	bool query(const T &val)const;
	
	typename Link::Node* getNodeAddr(const T &val); 
	//在链表中查找val元素是否存在

    /*
	//要用特例化，首先得定义模板
	template<typename E>
	bool query(const E &val)
	{
		cout << "template query" << endl;
		Node *pcur = mphead->mpnext;
		while (pcur != NULL)
		{
			if (pcur->mdata == val)
				return true;
			pcur = pcur->mpnext;
		}
		return false;
	}

   */
	//针对char*类型的模板实例化

	
private:
	class Node
	{
	public:
		// T():零初始化/零构造
		Node(T data = T())
			:mdata(data), mpnext(NULL){}
		T mdata;
		Node *mpnext;
	};

	Node *mphead;
};

template<typename R,typename A1,typename A2>
class Link<R(*)(A1,A2)>  //函数指针类型 
{
	public :
		Link()
		{
			cout<<" Link<R(*)(A1,A2)>"<<endl;
		}
}


//函数的专门针对于函数类型的部分特例化

template<typename T>
class Test
{
	public:
	Test()
	{
		cout<<" "<<endl;	
	}	
} 

//函数的专门针对于函数类型的部分特例化
template<typename R,typename A1,typename A2>
class Test<R (A1,A2)>
{
	
}

template<typename T>
template<typename T>
Link<T>::Link()
{
	mphead = new Node();
}

template<typename T>
Link<T>::~Link()
{
	Node *pcur = mphead;
	while (pcur != NULL)
	{
		mphead = mphead->mpnext;
		delete pcur;
		pcur = mphead;
	}
}

template<typename T>
void Link<T>::insertHead(const T &val)
{
	Node *pnode = new Node(val);  // bad_alloc
	pnode->mpnext = mphead->mpnext;
	mphead->mpnext = pnode;
}

template<typename T>
void Link<T>::insertTail(const T &val)
{
	Node *plast = mphead;
	while (plast->mpnext != NULL)
	{
		plast = plast->mpnext;
	}
	plast->mpnext = new Node(val);
}

template<typename T>
void Link<T>::deleteNode(const T &val)
{
	Node *ppre = mphead;
	Node *pcur = mphead->mpnext;
	while (pcur != NULL)
	{
		if (pcur->mdata == val)
		{
			ppre->mpnext = pcur->mpnext;
			delete pcur;
			pcur = ppre->mpnext;
		}
		else
		{
			ppre = pcur;
			pcur = pcur->mpnext;
		}
	}
}

template<typename T>
void Link<T>::show()const
{
	Node *pcur = mphead->mpnext;
	while (pcur != NULL)
	{
		cout << pcur->mdata << " ";
		pcur = pcur->mpnext;
	}
	cout << endl;
}

template<typename T>
bool Link<T>::query(const T &val)const
{
	cout << "non-template query" << endl;
	Node *pcur = mphead->mpnext;
	while (pcur != NULL)
	{
		if (pcur->mdata == val)
			return true;
		pcur = pcur->mpnext;
	}
	return false;
}

template<typename T>
typename Link<T>::Node* Link<T>::getNodeAddr(const T &val) 
{
	if(mphead==NULL)
	{
		return NULL;
	}
	
	Node*p =mphead->mpnext;
	while(p)
	{
		if(val.mdata==p->mpnext->mdata)
		{
			return p->mpnext;	
		}	
		p=p->mpnext;
	} 
	return NULL;
}

template<>
class Link<char*>
{
public:
	//Link  ~Link  insertHead  insertTail  deleteNode  query  show
	Link();
	~Link();
	void insertHead(char * const &val);
	void insertTail(char* const &val);
	void deleteNode(char *const &val);
	bool query(char *val) const;
	void show() const;
	
	//这些方法在类体内声明，在类外部定义
private:
	class Node{
		public:
		// T():零初始化/零构造
		Node(char* data=NULL ):mpnext(NULL)
		{
			if(data!=NULL)
			{
				strcpy(mdata,data);
			}
		}
		char mdata[128];
		Node *mpnext;
	};
	Node *mphead;
};

Link<char *>::Link()
{
	mphead=new Node;
	mphead->mpnext=NULL;
}

void Link<char *>::insertHead(char *const &val)
{
	cout<<"speacial "<<endl;
	Node *p=new Node(val);
	p->mpnext=mphead->mpnext;
	mphead->mpnext=p;
}

void Link<char *>::insertTail(char *const &val)
{
	Node *p=new Node(val);
	if(mphead->mpnext==NULL)
	{
		mphead->mpnext=p;
	}
	else
	{
		Node *ptr=mphead->mpnext;
		while(ptr->mpnext!=NULL)
		{
			ptr=ptr->mpnext;
		}
		ptr->mpnext=p;
	}
}

void Link<char *>::deleteNode(char *const &val)
{
	if(mphead->mpnext==NULL)
	{
		return;
	}
	
	Node *pre=mphead->mpnext;
	Node *cur=mphead;
	while(pre!=NULL)
	{
		if((strcmp(pre->mdata,val))==0)
		{
			cur->mpnext=pre->mpnext;
			delete pre;
			pre=cur->mpnext;
		}
		pre=pre->mpnext;
		cur=cur->mpnext;
	}
} 


bool Link<char *>::query(char * val) const
{
	if(mphead->mpnext==NULL)
	{
		cout<<"当前为空表"<<endl; 
		return false;
	}
	
	Node *p=mphead->mpnext;
	while(p)
	{
		if((strcmp(p->mdata,val))==0)
		{
			return true;
		}
		p=p->mpnext;
	 } 
	 return false;
} 

void Link<char *>::show() const
{
	if(mphead->mpnext==NULL)
	{
		cout<<"此为空表"<<endl; 
		return ;
	}
	
	Node *_p=mphead->mpnext;
	while(_p)
	{
		cout<<_p->mdata<<"   ";
		_p=_p->mpnext;
	}
}


Link<char *>::~Link()
{
	if(mphead->mpnext==NULL)
	{
		delete mphead;
	}
	
	Node *p=mphead;
	while(p)
	{
		mphead=mphead->mpnext;
		delete p;
		p=mphead;
	}
}
/*

//compare：称作函数模板，模板代码只检查模板语法，不编译代码
template<typename T>
bool compare(T a, T b)
{
	cout << "compare(T, T)" << endl;
	return a > b;
}

//针对char*类型，提供了模板的特例化/特化/专用化版本
template<>
bool compare<char*>(char*  a, char *b)
{
	cout << "compare<char*>(char*, char*)" << endl;
	return strcmp(a, b) > 0;
}
*/
int main()
{
	/*
	char *p1 = "aaa";
	char *p2 = "bbb";
//	compare<char*>(p1, p2);
*/
    Link<char*> strLink;
    char * buff[]={"hello","i","am"};
	strLink.insertHead("hi");
	strLink.insertHead("am");
	strLink.insertHead(buff[2]);
	
	strLink.show();
	
	cout<<strLink.query("am")<<endl;
}
