#include<iostream>
#include<string.h>
#include<string>
#include<vector>
using namespace std;


#if 0
template<typename T>
bool compare(const T a,const T b)    //函数模板 
{
	cout<<"compare"<<endl;
	return a>b;
}

template<>
bool compare<char*>(  char * const a,char *const b)
{
	return strcmp(a,b)>0;
}
template<typename T,int SIZE>   //SIZE为非类型参数 
void sort(T arr[])
{
	for(int i=0;i<SIZE;i++)
	{
		for(int j=i;j<SIZE-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				T temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp; 
			}
		}
	 } 
}

//实现一个函数模板，在一个数组中，寻找值相等的元素额下标并返回，找不到返回-1

template<typename T>
int findVal(T *arr,int size,const T &val)
{
	for(int i=0;i<size;i++)
	{
		if(arr[i]==val)
		{
			return i;
		 } 
	}
	return -1;	
} 

template<>
int findVal<char *>(char **arr,int size,char *const &dst)
{
	for(int i=0;i<size;i++)
	{
		if(strcmp(arr[i],dst)==0)
		{
			return i;
		}
	}
	return -1;
}


template<>
bool compare<char *>(char *a,char *b)
{
	cout<<"compare char*"<<endl;
	return strcmp(a,b)>0;
} 
int main()
{
	//模板要实例化之后才能使用  -》 
	compare<int>(10,20);  //模板的隐式实例化 
	compare<int>(10,20.0) ;
	compare<char *>("hello","world");
	return 0; 
}


int main()
{
	/*
	string s("hello world");
	cout<<s.empty()<<endl;
	cout<<s.size()<<endl;
	*/
	/*
	int arr[]={56,23,45,78,24,33};
	sort<int,6>(arr);
	for(int i=0;i<6;i++)
	{
		cout<<arr[i]<<endl; 
	}
	*/
	
	char * str[]={"hello","hi","thank you"};
	cout<<findVal<char *>(str,3,"hello")<<endl;
//	cout<<compare<char *>("hello","world")<<endl;
	
}
#endif

template<typename T>
class Node
{
	public:
		//T()  零构造 
		Node(T data=T()):mdata(data),mpnext(NULL)
		{
			
		}
		T mdata;
		Node<T> *mpnext;
};

template<typename T>
class Linked
{
	public:
	Linked();
	~Linked();
	void insertHead(const T &val);
	void insertTail(const T &val);
	void deleteNode(const T &val);
	bool query(const T &val); 
	void show() const; 
	private:
		
	Node<T> *phead; 
	/*
	template<typename T>
	friend class Link;	
	*/
	
	/*
	*  class Node
	{
		public:
		T mdata;
		Node *mpnext;
    };
	*
	*/
};

template<typename T>
Linked<T>::Linked()
{
	phead=new Node<T>();
}

template<typename T>
Linked<T>::~Linked()
{
	if(phead->mpnext==NULL)
	{
		return;
	}
	else
	{
		while(phead->mpnext)
		{
			Node<T> *tmp=phead->mpnext;
			phead->mpnext=phead->mpnext->mpnext;
			delete tmp;
		}
	}
}

template<typename T>
void Linked<T>::insertHead(const T &val)
{
	Node<T>* node=new Node<T>(val);
	if(phead->mpnext==NULL)
	{
		phead->mpnext=node;
	}
	else
	{
	    node->mpnext=phead->mpnext;
		phead->mpnext=node;
	}
}

template<typename T>
void Linked<T>::insertTail(const T &val)
{
	Node<T>* node=new Node<T>(val);
	if(phead->mpnext==NULL)
	{
		phead->mpnext=node;
	}
	else
	{
		Node<T> *p=phead->mpnext;
		while(p->mpnext!=NULL)
		{
			p=p->mpnext;
		}
		p->mpnext=node;
		node->mpnext=NULL;
	}
}

template<typename T>
void Linked<T>::deleteNode(const T &val)
{
	if(phead->mpnext==NULL)
	{
		return;
	}
	else
	{
		Node<T> *pre=phead;
		Node<T> *pcur=phead->mpnext;
		
		while(pcur)
		{
			if(pcur->mdata==val)
			{
				pre->mpnext=pcur->mpnext;
				delete pcur;
				pcur=pre->mpnext;
			}
		    pre=pcur;
		    pcur=pcur->mpnext;
		}
		
	}
}



template<typename T>
void Linked<T>::show() const
{
	if(phead->mpnext==NULL)
	{
		cout<<"空表"<<endl;
		return ;
	}
	Node<T> *p=phead->mpnext;
	while(p)
	{
		cout<<" "<<p->mdata<<endl;	
		p=p->mpnext;
	} 
	
}


//在链表中查找val元素是否存在

template<typename T>
bool Linked<T>::query(const T &val)
{
	if(phead->mpnext==NULL)
	{
		return false;
	}
	Node<T> *p=phead->mpnext;
	while(p)
	{
		if(p->mdata==val)
		{
			return true;
		}
		p=p->mpnext;
	}
	return false;
}

template<>
bool Linked::query<char *>(char* const &p)
{
	if(phead->mpnext!=NULL)
	{
		return;
	} 
	else
	{
		Node<T> *t
		if(strcmp())
	}
		
} 
int main()
{
	Linked<int>  intLink;
	/*
	intLink.insertHead(10);
	intLink.insertHead(9);
	intLink.insertHead(8);
	*/
	
	intLink.insertTail(1);
	intLink.insertTail(2);
	intLink.insertTail(3);
	intLink.show();
	cout<<intLink.query(3)<<endl;
	
}
