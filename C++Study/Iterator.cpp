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
	// construct构造  destroy析构
	// allocate开辟内存  deallocate释放内存
	void construct(void *ptr, const T &val)
	{
		new (ptr)T(val);  //表示在ptr指向的内存，构造一个值为val的对象
	}
	void destroy(T *ptr)
	{
		//自己填
		ptr->~T();
	}
	//开辟内存
	T* allocate(size_t size)
	{
		//malloc
		return (T*)malloc(size);
	}
	//释放内存
	void deallocate(void *ptr)
	{
		free(ptr);
	}
};

template<typename T, typename Allocator = myallocator<T> >
class Vector
{
public:
	//默认构造的vector，底层没分配过内存0
	Vector() :mpVec(NULL), mSize(0), mCur(0){}
	//size表示初始的内存大小，val表示内存初始值
	Vector(int size, const T &val = T())
		:mSize(size), mCur(size)
	{
		mpVec = _allocator.allocate(mSize * sizeof(T));
		for (int i = 0; i < mSize; ++i)
		{
			_allocator.construct(mpVec + i, val);
		}
	}
	//拷贝构造
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

	//末尾添加元素    push_front   pop_front  O(n)
	void push_back(const T &val)
	{
		if (full())
			reSize();
		_allocator.construct(mpVec + mCur, val);
		mCur++;
	}
	//末尾删除
	void pop_back()
	{
		if (empty())
			return;
		--mCur;
		_allocator.destroy(mpVec + mCur); //把删除的对象一定要析构
	}

	T front()const{ return mpVec[0]; }
	T back()const{ return mpVec[mCur - 1]; }

	bool full()const{ return mCur == mSize; }
	bool empty()const{ return mCur == 0; }

	T& operator[](int index){ return mpVec[index]; }

	//内存以2倍方式增长
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
	1.需要在容器里面定义嵌套类性  iterator
	2.给容器提供begin方法     iterator begin();  把容器第0号位元素的迭代器返回回去
	3.给容器提供end方法       iterator end();    把容器末尾元素后继位置的迭代器返回回去
	4.给迭代器提供operator!=
	5.给迭代器提供operator++()
	6.给迭代器提供operator*()
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

		T& operator*() //返回引用是为了修改
		{
			return *ptr;
		}

		

		
	};

	//定义当前容器的迭代器类型  的作用，就是来遍历容器的(遍历容器底层的数据结构)
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
		cout << vec1[i] << " ";   // vector 向量容器 operator[]    [i] O(1)
	}
	cout << endl;


	ShowContainer(vec1);
	/*
	需要一种通用的方式，来遍历任何的容器   operator[]做不到的
	通用： 怎么通用？是使用方式通用呢？还是所有容器共用一个迭代器呢？
	数组operator[]
	链表
	二维数组
	哈希表
	红黑树

	迭代器和容器是一一对应的，所以在设计上，把迭代器这个类，设计成容器类型的嵌套类性
	*/
	/*
	1.需要在容器里面定义嵌套类性  iterator
	2.给容器提供begin方法     iterator begin();  把容器第0号位元素的迭代器返回回去
	3.给容器提供end方法       iterator end();    把容器末尾元素后继位置的迭代器返回回去
	4.给迭代器提供operator!=
	5.给迭代器提供operator++()
	6.给迭代器提供operator*()
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

