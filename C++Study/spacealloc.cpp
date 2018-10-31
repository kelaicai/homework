// 20180518.cpp : 定义控制台应用程序的入口点。
//



/*
运算符的重载
C++16次课   容器container    空间配置器allocator    迭代器iterator   stack  queue

vector容器的特征  =》   向量容器(底层是数组结构)
1.默认构造的vector，底层没分配过内存 0
2.vector添加元素，满了以后，内存以2倍方式增长


把myallocator的函数填完
allocate和deallocate函数改造，调用你写好的ngx内存池相应的内存分配和回收的函数

*/
#include <iostream>
#include <time.h>
using namespace std;

template<typename T>
class myallocator
{
public:
	// construct构造  destroy析构
	// allocate开辟内存  deallocate释放内存
	void construct(void *ptr, const T &val)
	{
		new (ptr) T(val);  //表示在ptr指向的内存，构造一个值为val的对象
	}
	void destroy(T *ptr)
	{
		//自己填
	}
	//开辟内存
	void* allocate(size_t size)
	{
		//malloc
	}
	//释放内存
	void deallocate(void *ptr)
	{

	}
};

template<typename T, typename Allocator=myallocator<T> >
class Vector
{
public:
	//默认构造的vector，底层没分配过内存0
	Vector() :mpVec(NULL), mSize(0), mCur(0){}
	//size表示初始的内存大小，val表示内存初始值
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
	//拷贝构造
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

	//末尾添加元素
	void push_back(const T &val)
	{
		if (full())
			reSize();
		mpVec[mCur++] = val;
	}
	//末尾删除
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

	//内存以2倍方式增长
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
	//问题1：构造了一堆没有用的对象，构造容器时，只需要内存
	//但是new附加的会调用默认构造生成对象（无效对象）
	/*
	生成容器时：只需要内存   不要构造对象     new T[];
	内存开辟和对象构造分开
	malloc => 内存开辟
	new有四种方式
	int *p = new int; => 捕捉bad_alloc异常
	int *p = new (nothrow) int;  => 不抛出异常的new
	const int *p = new const int;   => 堆上开辟了一个常量
	int *p = new (addr) int;   =>  定位new   在addr地址上构造一个类型的变量/对象
	char buffer[1024];
	A *p = new (buffer) A();
	*/
	Vector<A> vec; 
	A a1, a2, a3;

	vec.push_back(a1);
	vec.push_back(a2);
	vec.push_back(a3);

	//问题2:从容器删除对象时，并没有真正的析构对象
	/*
	对象的析构    ~A();
	对象内存的释放   delete
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


