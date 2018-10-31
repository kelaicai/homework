#include<iostream>
using namespace std;

const int STACK_SIZE=10;

class SqStack
{
public:
	void init();
	void release();
	
	//构造函数和析构函数的名字必须和类名一样，不能随便起
	//构造函数和析构函数没有返回值
	//构造函数是不能带有参数的，因此构造函数只有一个
	//构造函数是不能带有参数的，构造函数是可以重载的
	SqStack()
	{
		cout<<"SqStack()"<<endl;
		mtop=-1;
		mpstack=new int[STACK_SIZE];
	} 
	
	~SqStack()
	{
	 	cout<<"~SqStack()"<<endl;
	 	delete [] mpstack;
	}
	 
	
    void push(int val);
	void pop();
	int top();
	 
	bool empty()
	{
  	 	return mtop==-1;
	}
	 
	 bool full()
	 {
	 	return mtop==STACK_SIZE-1;
	 }
	 
private:
	int *mpstack;
	int mtop; 
}; 

//初始化顺序栈 
void SqStack::init()
{
	mtop=-1;
	mpstack=new int[STACK_SIZE];
}

//释放资源的代码 
void SqStack::release()
{
	delete [] mpstack;
}

void SqStack::push(int val)
{
	if(full())
	{
		return ;
	}
	mpstack[++mtop]=val;
} 
void SqStack::pop()
{
	if(empty())
	{
		return;
	}
	--mtop;
}

int SqStack::top()
{
	if(empty())
	{
		throw "stack is empty";
	}
	return mpstack[mtop];
}

 
int main()
{
	SqStack stack1;
	
	stack1.init();
	
	stack1.push(10);
	stack1.push(12);
	stack1.push(13);
	stack1.push(14); 
	
	while(!stack1.empty())
	{
		int val=stack1.top();
		cout<<val<<" ";
		stack1.pop();
		
	}
	
	stack1.push(12);
	
	
} 
































