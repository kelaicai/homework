// 20180518.cpp : �������̨Ӧ�ó������ڵ㡣
//



/*
�����������
C++16�ο�   ����container    �ռ�������allocator    ������iterator   stack  queue

vector����������  =��   ��������(�ײ�������ṹ)
1.Ĭ�Ϲ����vector���ײ�û������ڴ� 0
2.vector���Ԫ�أ������Ժ��ڴ���2����ʽ����


��myallocator�ĺ�������
allocate��deallocate�������죬������д�õ�ngx�ڴ����Ӧ���ڴ����ͻ��յĺ���

*/
#include <iostream>
#include <time.h>
using namespace std;

template<typename T>
class myallocator
{
public:
	// construct����  destroy����
	// allocate�����ڴ�  deallocate�ͷ��ڴ�
	void construct(void *ptr, const T &val)
	{
		new (ptr) T(val);  //��ʾ��ptrָ����ڴ棬����һ��ֵΪval�Ķ���
	}
	void destroy(T *ptr)
	{
		//�Լ���
	}
	//�����ڴ�
	void* allocate(size_t size)
	{
		//malloc
	}
	//�ͷ��ڴ�
	void deallocate(void *ptr)
	{

	}
};

template<typename T, typename Allocator=myallocator<T> >
class Vector
{
public:
	//Ĭ�Ϲ����vector���ײ�û������ڴ�0
	Vector() :mpVec(NULL), mSize(0), mCur(0){}
	//size��ʾ��ʼ���ڴ��С��val��ʾ�ڴ��ʼֵ
	Vector(int size, const T &val = T())
		:mSize(size), mCur(size)
	{
		//mpVec = new T[mSize];
		_allocator.allocate(mSize * sizeof(T));
		for (int i = 0; i < mSize; ++i)
		{
			//mpVec[i] = val;
			_allocator.construct(mpVec + i, val);
		}
	}
	//��������
	Vector(const Vector<T> &src)
		:mSize(src.mSize), mCur(src.mCur)
	{
		mpVec = new T[mSize];
		for (int i = 0; i < mCur; ++i)
		{
			mpVec[i] = src.mpVec[i];
		}
	}
	//operator=
	Vector<T>& operator=(const Vector<T> &src)
	{
		if (this == &src)
			return *this;

		delete[]mpVec;

		mpVec = new T[mSize];
		for (int i = 0; i < mCur; ++i)
		{
			mpVec[i] = src.mpVec[i];
		}

		return *this;
	}
	~Vector()
	{
		delete[]mpVec;
		mpVec = NULL;
	}

	//ĩβ���Ԫ��
	void push_back(const T &val)
	{
		if (full())
			reSize();
		mpVec[mCur++] = val;
	}
	//ĩβɾ��
	void pop_back()
	{
		if (empty())
			return;
		--mCur;
	}

	T front()const{ return mpVec[0]; }
	T back()const{ return mpVec[mCur - 1]; }

	bool full()const{ return mCur == mSize; }
	bool empty()const{ return mCur == 0; }

	T& operator[](int index){ return mpVec[index]; }

	//�ڴ���2����ʽ����
	void reSize()
	{
		if (mSize == 0)
		{
			mpVec = new T[1];
			mSize = 1;
			mCur = 0;
		}
		else
		{
			T *ptmp = new T[mSize * 2];
			for (int i = 0; i < mCur; ++i)
			{
				ptmp[i] = mpVec[i];
			}
			mSize *= 2;
			delete[]mpVec;
			mpVec = ptmp;
		}
	}

	int size()const{ return mCur; }
private:
	T *mpVec;
	int mSize;
	int mCur;
	Allocator _allocator;
};
class A
{
public:
	A(){ cout << "A()" << endl; }
	~A(){ cout << "~A()" << endl; }
};
int main(int argc, char* argv[])
{
	//����1��������һ��û���õĶ��󣬹�������ʱ��ֻ��Ҫ�ڴ�
	//����new���ӵĻ����Ĭ�Ϲ������ɶ�����Ч����
	/*
	��������ʱ��ֻ��Ҫ�ڴ�   ��Ҫ�������     new T[];
	�ڴ濪�ٺͶ�����ֿ�
	malloc => �ڴ濪��
	new�����ַ�ʽ
	int *p = new int; => ��׽bad_alloc�쳣
	int *p = new (nothrow) int;  => ���׳��쳣��new
	const int *p = new const int;   => ���Ͽ�����һ������
	int *p = new (addr) int;   =>  ��λnew   ��addr��ַ�Ϲ���һ�����͵ı���/����
	char buffer[1024];
	A *p = new (buffer) A();
	*/
	Vector<A> vec; 
	A a1, a2, a3;

	vec.push_back(a1);
	vec.push_back(a2);
	vec.push_back(a3);

	//����2:������ɾ������ʱ����û����������������
	/*
	���������    ~A();
	�����ڴ���ͷ�   delete
	*/
	vec.pop_back();
	vec.pop_back();
	vec.pop_back();

	return 0;
}

int main2(int argc, char* argv[])
{
	Vector<int> vec1;
	Vector<int> vec2(vec1);

	srand(time(0));
	for (int i = 0; i < 20; ++i){
		vec1.push_back(rand() % 20);
	}

	int size = vec1.size();
	for (int i = 0; i < size; ++i)
	{
		cout << vec1[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}


