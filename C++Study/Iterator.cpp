#include <iostream>
#include <time.h>
#include<stdlib.h>
#include<vector>
using namespace std;
#include<string>
template<typename T>
class myallocator
{
public:
	// construct����  destroy����
	// allocate�����ڴ�  deallocate�ͷ��ڴ�
	void construct(void *ptr, const T &val)
	{
		new (ptr)T(val);  //��ʾ��ptrָ����ڴ棬����һ��ֵΪval�Ķ���
	}
	void destroy(T *ptr)
	{
		//�Լ���
		ptr->~T();
	}
	//�����ڴ�
	T* allocate(size_t size)
	{
		//malloc
		return (T*)malloc(size);
	}
	//�ͷ��ڴ�
	void deallocate(void *ptr)
	{
		free(ptr);
	}
};

template<typename T, typename Allocator = myallocator<T> >
class Vector
{
public:
	//Ĭ�Ϲ����vector���ײ�û������ڴ�0
	Vector() :mpVec(NULL), mSize(0), mCur(0){}
	//size��ʾ��ʼ���ڴ��С��val��ʾ�ڴ��ʼֵ
	Vector(int size, const T &val = T())
		:mSize(size), mCur(size)
	{
		mpVec = _allocator.allocate(mSize * sizeof(T));
		for (int i = 0; i < mSize; ++i)
		{
			_allocator.construct(mpVec + i, val);
		}
	}
	//��������
	Vector(const Vector<T> &src)
		:mSize(src.mSize), mCur(src.mCur)
	{
		mpVec = _allocator.allocate(sizeof(T)*mSize);
		for (int i = 0; i < mCur; ++i)
		{
			_allocator.construct(mpVec + i, src.mpVec[i]);
		}
	}
	//operator=
	Vector<T>& operator=(const Vector<T> &src)
	{
		if (this == &src)
			return *this;

		for (int i = 0; i < mCur; ++i)
		{
			_allocator.destroy(mpVec + i);
		}
		_allocator.deallocate(mpVec);

		mpVec = _allocator.allocate(sizeof(T)*mSize);
		for (int i = 0; i < mCur; ++i)
		{
			_allocator.construct(mpVec + i, src.mpVec[i]);
		}

		return *this;
	}
	~Vector()
	{
		for (int i = 0; i < mCur; ++i)
		{
			_allocator.destroy(mpVec + i);
		}
		_allocator.deallocate(mpVec);
		mpVec = NULL;
	}

	//ĩβ���Ԫ��    push_front   pop_front  O(n)
	void push_back(const T &val)
	{
		if (full())
			reSize();
		_allocator.construct(mpVec + mCur, val);
		mCur++;
	}
	//ĩβɾ��
	void pop_back()
	{
		if (empty())
			return;
		--mCur;
		_allocator.destroy(mpVec + mCur); //��ɾ���Ķ���һ��Ҫ����
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
			mpVec = _allocator.allocate(sizeof(T));
			mSize = 1;
			mCur = 0;
		}
		else
		{
			T *ptmp = _allocator.allocate(mSize * 2 * sizeof(T));
			for (int i = 0; i < mCur; ++i)
			{
				_allocator.construct(ptmp + i, mpVec[i]);
			}
			mSize *= 2;
			for (int i = 0; i < mCur; ++i)
			{
				_allocator.destroy(mpVec + i);
			}
			_allocator.deallocate(mpVec);
			mpVec = ptmp;
		}
	}

	int size()const{ return mCur; }


	void insert()
	{

	}
	/*
	1.��Ҫ���������涨��Ƕ������  iterator
	2.�������ṩbegin����     iterator begin();  ��������0��λԪ�صĵ��������ػ�ȥ
	3.�������ṩend����       iterator end();    ������ĩβԪ�غ��λ�õĵ��������ػ�ȥ
	4.���������ṩoperator!=
	5.���������ṩoperator++()
	6.���������ṩoperator*()
	*/
	class Iterator
	{
	private:
		int index;
		T *ptr;
	public:
		Iterator(T* _ptr = NULL) :ptr(_ptr)
		{

		}


		bool operator!=(const Iterator &val)
		{
			return ptr != val.ptr;
		}

		void operator++()
		{
			++ptr;
		}

		T& operator*() //����������Ϊ���޸�
		{
			return *ptr;
		}

		

		
	};

	//���嵱ǰ�����ĵ���������  �����ã�����������������(���������ײ�����ݽṹ)
	Iterator begin()
	{
		return Iterator(mpVec);
	}

	Iterator end()
	{
		return Iterator(mpVec + mCur);
	}
private:
	T *mpVec;
	int mSize;
	int mCur;
	Allocator _allocator;
};

template<typename Container>
void ShowContainer(Container &con)
{
	Container::Iterator it = con.begin();
	for (; it != con.end();++it)
	{
		cout << *it << endl;
	}
}

template<typename Iterator>
void mySort(Iterator first,Iterator last)
{
	for (Iterator it_i(first); it_i!= last;++it_i)
	{
		for (Iterator it_j; it_j != last - 1 - it_i)
		{
			if ()
		}
	}
}


int main(int argc, char* argv[])
{
	Vector<int> vec1;

	srand(time(0));
	for (int i = 0; i < 20; ++i){
		vec1.push_back(rand() % 100);
	}

	int size = vec1.size();
	for (int i = 0; i < size; ++i)
	{
		cout << vec1[i] << " ";   // vector �������� operator[]    [i] O(1)
	}
	cout << endl;


	ShowContainer(vec1);
	/*
	��Ҫһ��ͨ�õķ�ʽ���������κε�����   operator[]��������
	ͨ�ã� ��ôͨ�ã���ʹ�÷�ʽͨ���أ�����������������һ���������أ�
	����operator[]
	����
	��ά����
	��ϣ��
	�����

	��������������һһ��Ӧ�ģ�����������ϣ��ѵ���������࣬��Ƴ��������͵�Ƕ������
	*/
	/*
	1.��Ҫ���������涨��Ƕ������  iterator
	2.�������ṩbegin����     iterator begin();  ��������0��λԪ�صĵ��������ػ�ȥ
	3.�������ṩend����       iterator end();    ������ĩβԪ�غ��λ�õĵ��������ػ�ȥ
	4.���������ṩoperator!=
	5.���������ṩoperator++()
	6.���������ṩoperator*()
	*/
	/*
	Vector<int>::Iterator it = vec1.begin();
	for (; it != vec1.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

*/

	system("pause");
	return 0;
}

