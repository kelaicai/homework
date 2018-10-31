#include<iostream>
using namespace std;

const int STACK_SIZE=10;

class SqStack
{
public:
	void init();
	void release();
	
	//���캯�����������������ֱ��������һ�������������
	//���캯������������û�з���ֵ
	//���캯���ǲ��ܴ��в����ģ���˹��캯��ֻ��һ��
	//���캯���ǲ��ܴ��в����ģ����캯���ǿ������ص�
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

//��ʼ��˳��ջ 
void SqStack::init()
{
	mtop=-1;
	mpstack=new int[STACK_SIZE];
}

//�ͷ���Դ�Ĵ��� 
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
































