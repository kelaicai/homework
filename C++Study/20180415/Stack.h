#ifndef STACK_H
#define STACK_H

//˳��ջ
const int STACK_SIZE = 10;
class SqStack
{
public:
	SqStack(int size = 10);
	~SqStack();
	//��ջ����
	void push(int val);
	//��ջ����
	void pop();
	//��ȡջ��Ԫ��
	int top();
	//�ж�ջ��
	bool empty();
	//�ж�ջ��
	bool full();
private:
	int *mpstack;
	int mtop;
	int msize;
};

#endif