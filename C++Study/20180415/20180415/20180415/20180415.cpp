// 20180415.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <iostream>
using namespace std;

/*
C++05 ���ñʼ�
��Ͷ���
class��struct����������Ĳ�ͬ����û��ָ�������޶���������£�
Ĭ�ϵķ����޶���һ��


����  =��  ʵ�������

          
|(ʵ����)	  ����/��Ϊ

��	��=	    ADT��abstract data type��
���ԣ���Ա����
��Ϊ����Ա����/����

�����֮������Ĺ�ϵ
1.���
2.�̳�

OOP���Ե��Ĵ������� ����   ��װ    �̳�   ��̬


һ�����캯������������
1.������������������ֱ��������һ�������������������������ǰ���~
2.�������������û�з���ֵ
3.���������ǲ��ܴ��в����ģ������������ֻ��һ�������캯�����������
���������캯���ǿ������ص�
4.��������û���κι�������������ʱ�򣬱����������ǰ�������һ��
Ĭ�ϵĹ��캯��������������Ĭ�ϵģ����ǲ����κβ��������Һ���ʲôҲ���������Ǹ��պ�����
5.������������Զ���������Ĺ��캯������ʱ���������Ͳ������Ĭ�ϵ�
���캯����
6.����Ĭ�Ϲ���Ķ��󣬲�Ҫ�ڶ������ֺ����һ�Կյ�()


��Ҫ��
����һ�����캯���ǲ��Ǹ����󿪱��ڴ�ģ�
������ڴ�����ϵͳ�����ٵģ����캯��ֻ���ڴ�ĳ�ʼ�������캯���������ˣ����Ǿ�˵���������
����������������ǲ��Ǹ������ͷ��ڴ�ģ�
���ڶ����ڴ��ͷ�֮ǰ���Ѷ���ռ�õ�������Դ���ͷŵ�

һ��������Ķ������ÿ���������Լ���һ�ݳ�Ա���������ǹ��������
�ĳ�Ա����

����һ�����⣿ ����ķ���������ô֪����Ҫ�����ĸ������أ�����
����1����ĳ�Ա����һ�����룬�βζ������һ����ǰ�����͵�thisָ�����
����2��������ó�Ա����=�� �Ѷ���ĵ�ַ��Ϊ������ʵ�ν��д���
����3���ڷ����������������Ա������ͨ��this->�����õ�


����Ĺ����������˳��պ����෴��


˵˵����
1.���캯���������ˣ�����Ͳ����ˣ��Ǹ���Ŷ�����ڴ���г�ʼ���ˣ�
2.���������������ˣ�������ͷ���(���ͷ��˶���ռ�õ��ⲿ��Դ)


�� =��ʵ����  =�� ����  �ܹ�����������
1�������󿪱��ڴ�
2�����ú��ʵĹ��캯��



�����������캯��
������ͬ����һ���Ѿ����ڵĶ������¶����ʱ�򣬾ͻ���ÿ������캯��
����1����������û���ṩ�������캯����ʱ�򣬱����������һ��Ĭ�ϵ�
�������캯�����������Ĭ�����ڴ濽��

����2��������ǳ��������һ��Ҫ�ṩ�Զ���Ŀ������캯��

�½ڿ����ʵ����⣨Ů������
�������캯�����βΣ��ܲ��ܰ�ֵ���ݣ����ܵĻ�Ϊʲô��

������ֵ����������غ���operator=
�����������Ѿ����ڵĶ���ֵ��ʱ�򣬻���õ��ú���
����1����������û���ṩ��ֵ����������غ�����ʱ�򣬱����������һ��Ĭ�ϵ�
��ֵ����������غ������������Ĭ�����ڴ渳ֵ

�½ڿ����ʵ����⣨��������=>��ָoffer�ĵ�һҳ
operator=�������ͷ��ڴ棬�����¿����ڴ�ʱ���쳣�������������ô��ֹ��



�ġ���������Ϲ�ϵ
��ϣ�һ���ඨ��Ķ�����Ϊ����һ����ĳ�Ա��������������֮��Ĺ�ϵ
�ͳ�Ϊ��Ϲ�ϵ��һ������a part of... ...һ���ֵĹ�ϵ 


�塣����Ĺ��캯����ʼ���б�
������ڶ����Ա������ʼ����ʱ��ָ����Ա�����ĳ�ʼ����ʽ��
��ôӦ���ڹ��캯���ĳ�ʼ���б���ָ��
*/

/*
class Date
{
public:
Date(int y, int m , int d)
{
_y = y;
_m = m;
_d = d;
}
private:
int _y;
int _m;
int _d;
};

class Student
{
public:
Student(char *n, int a, char s,
int y, int m, int d)
:age(a), sex(s) ,birthday(y,m,d)
{
strcpy(name, n);
}
private:
char name[20];
int age;
char sex;
Date birthday;  // �Ҳ���Date��Ĭ�Ϲ��캯��
};

*/

#if 0
//˳��ջ
const int STACK_SIZE = 10;
class SqStack
{
public:
	SqStack(int size = 10)
	{
		cout << "SqStack(int)" << endl;
		mtop = -1;
		mpstack = new int[size];
		msize = size;
	}

	~SqStack()
	{
		cout << "~SqStack()" << endl;
		delete[]mpstack;
		mpstack = NULL;
	}

	//��ջ����
	void push(int val);
	//��ջ����
	void pop();
	//��ȡջ��Ԫ��
	int top();
	//�ж�ջ��
	bool empty(){ return mtop == -1; }
	//�ж�ջ��
	bool full(){ return mtop == msize - 1; }
private:
	int *mpstack;
	int mtop;
	int msize;
};

//��ջ����
void SqStack::push(int val)
{
	if (full())
		return;
	mpstack[++mtop] = val;
}
//��ջ����
void SqStack::pop()
{
	if (empty())
		return;
	--mtop;
}
//��ȡջ��Ԫ��
int SqStack::top()
{
	if (empty())
		throw "stack is empty!";
	return mpstack[mtop];
}
// Test a = 10;   Test a; a = 10;
class Vector
{
public:
	Vector(int size = 20) :mstack(size)
	{
	}
	void push_back(int val)
	{
		mstack.push(val);
	}
	void pop_back()
	{
		mstack.pop();
	}
	int back()
	{
		return mstack.top();
	}
	bool empty()
	{
		return mstack.empty();
	}
	bool full()
	{
		return mstack.full();
	}
private:
	SqStack mstack;  // ��Ա����
	int a;
};

int main()
{

	return 0;
}
#endif

#if 0
//ѭ������
class CircleQue
{
public:
	CircleQue(int size = 10);
	~CircleQue();
	CircleQue(const CircleQue &src);
	void operator=(const CircleQue &src);

	void addQue(int val);
	void delQue();
	int front();
	int rear();

	bool empty();
	bool full();
private:
	int *mpQue;
	int msize;
	int mfront;
	int mrear;
};
#endif



#if 0
//˳������
class Vector
{
public:
	//���캯�� ����ָ����size��̬���ٵײ������ռ䣬���г�ʼ��
	//thisָ��  =��   ������ڴ���ʼ��ַ
	Vector(int size = 10)
	{
		cout << this << endl;
		cout << "Vecctor(int size = 10)" << endl;
		this->mpvec = new int[size];
		this->mcur = 0;
		this->msize = size;
	}
	//�ṩ�Զ���Ŀ������캯��
	Vector(const Vector &src)
	{
		cout << &src << " copy " << this << endl;
		cout << "Vector(const Vector&)" << endl;
		mcur = src.mcur;
		msize = src.msize;
		mpvec = new int[msize];
		for (int i = 0; i < mcur; ++i)
		{
			mpvec[i] = src.mpvec[i];
		}
	}
	//�Զ���ĸ�ֵ����������غ���
	void operator=(const Vector &src)
	{
		cout << &src << " => " << this << endl;
		cout << "void operator=(const Vector&)" << endl;
		//�ж��Ը�ֵ�����
		if (this == &src)
			return;

		//��Ҫ���ͷ�thisָ��ָ�����ԭ��ռ�õ��ⲿ��Դ
		delete[]mpvec;

		//���¿�����Դ����������
		mcur = src.mcur;
		msize = src.msize;
		mpvec = new int[msize];
		for (int i = 0; i < mcur; ++i)
		{
			mpvec[i] = src.mpvec[i];
		}
	}

	//����������
	~Vector()
	{
		cout << this << endl;
		cout << "~Vector()" << endl;
		delete[]this->mpvec;
		this->mpvec = NULL;
	}
	//�������Ԫ��
	void push_back(int val)
	{
		if (full())
			this->resize();
		this->mpvec[this->mcur++] = val;
	}
	//����ɾ��Ԫ��
	void pop_back()
	{
		if (empty())
			return;
		mcur--;
	}
	//���غ���Ԫ��
	int back(){ return mpvec[mcur - 1]; }
	//�п�
	bool empty(){ return mcur == 0; }
	//����
	bool full(){ return mcur == msize; }
	//��ӡvector�����ķ���
	void show()
	{
		for (int i = 0; i < this->mcur; ++i)
		{
			cout << this->mpvec[i] << " ";
		}
		cout << endl;
	}
private:
	//��չ�ռ��õģ�һ�������ҵ�ԭ����2��
	void resize()
	{
		int *ptemp = new int[msize * 2];
		for (int i = 0; i < msize; ++i)
		{
			ptemp[i] = mpvec[i];
		}

		msize *= 2;
		delete[]mpvec;
		mpvec = ptemp;
	}
	//��ʾ�洢���ݵ�����
	int *mpvec;
	//��ʾ��ǰԪ�ص����
	int mcur;
	//��ʾ��ǰ����Ĵ�С
	int msize;
};
int main()
{
	//    Vector(int)
	Vector vec1(10);
	Vector vec2(20);
	
	// Vector::push_back(&vec1, 10)
	vec1.push_back(10);
	// Vector::push_back(&vec1, 11)
	vec1.push_back(11);

	// Vector::push_back(&vec2, 12)
	vec2.push_back(12);
	// Vector::push_back(&vec2, 13)
	vec2.push_back(13);

	vec1.show();
	vec2.show();

	//    Vector(Vector*)  =>   �������캯��
	Vector vec3 = vec1;  // => Vector vec3 = vec1;

	//���ڶ���ĸ������㶼ת������ߵĶ��󣬵�����Ӧ������������ط��������ұ�ʣ�µĶ���������ʵ�δ��ݽ���
	//vec3.operator=(vec1);
	//void operator=(const Vector &vec)
	vec3 = vec3;
	

	return 0;
}



//˳��ջ
const int STACK_SIZE = 10;
class SqStack
{
public:
	/*SqStack()
	{
		cout << "SqStack()" << endl;
		mtop = -1;
		mpstack = new int[STACK_SIZE];
		msize = STACK_SIZE;
	}*/

	SqStack(int size)
	{
		cout << "SqStack(int)" << endl;
		mtop = -1;
		mpstack = new int[size];
		msize = size;
	}

	~SqStack()
	{
		cout << "~SqStack()" << endl;
		delete[]mpstack;
	}
	
	//��ջ����
	void push(int val);
	//��ջ����
	void pop();
	//��ȡջ��Ԫ��
	int top();
	//�ж�ջ��
	bool empty(){ return mtop == -1; }
	//�ж�ջ��
	bool full(){ return mtop == msize - 1; }
private:
	int *mpstack;
	int mtop;
	int msize;
};

//��ջ����
void SqStack::push(int val)
{
	if (full())
		return;
	mpstack[++mtop] = val;
}
//��ջ����
void SqStack::pop()
{
	if (empty())
		return;
	--mtop;
}
//��ȡջ��Ԫ��
int SqStack::top()
{
	if (empty())
		throw "stack is empty!";
	return mpstack[mtop];
}
int main()
{
	/*
	���������Ҫ����
	1������������ڴ�
	2����������ù��캯��
	*/
	SqStack stack1;
	SqStack stack2(20);

	//��.push������߱�������/�ṹ/����
	//SqStack stack3();
	//stack3.push(10);
	

	return 0;
	/*
	ջ�ϵĶ�����return�����Զ����ö������������
	*/
}
#endif

