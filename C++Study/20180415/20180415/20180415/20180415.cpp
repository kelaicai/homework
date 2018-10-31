// 20180415.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
using namespace std;

/*
C++05 课堂笔记
类和对象
class和struct用来定义类的不同：在没有指定访问限定符的情况下，
默认的访问限定不一样


对象  =》  实体的类型

          
|(实例化)	  属性/行为

类	《=	    ADT（abstract data type）
属性：成员变量
行为：成员方法/函数

类和类之间基本的关系
1.组合
2.继承

OOP语言的四大特征？ 抽象   封装    继承   多态


一。构造函数和析构函数
1.构造和析构函数的名字必须和类名一样，不能随便起，析构函数名字前面加~
2.构造和析构函数没有返回值
3.析构函数是不能带有参数的，因此析构函数只有一个；构造函数可以任意带
参数，构造函数是可以重载的
4.当类里面没有任何构造析构函数的时候，编译器会给当前的类产生一个
默认的构造函数和析构函数（默认的，就是不带任何参数，而且函数什么也不做，就是个空函数）
5.如果在类里面自定义了任意的构造函数，此时，编译器就不会产生默认的
构造函数了
6.定义默认构造的对象，不要在对象名字后面加一对空的()


重要：
问题一：构造函数是不是给对象开辟内存的？
对象的内存是由系统来开辟的，构造函数只做内存的初始化，构造函数调用完了，我们就说对象产生了
问题二：析构函数是不是给对象释放内存的？
是在对象内存释放之前，把对象占用的自他资源先释放掉

一个类产生的多个对象，每个对象都有自己的一份成员变量，它们共享这个类
的成员方法

带来一个问题？ 共享的方法，是怎么知道它要操作哪个对象呢？？？
结论1：类的成员方法一经编译，形参都会加上一个当前类类型的this指针变量
结论2：对象调用成员方法=》 把对象的地址作为方法的实参进行传递
结论3：在方法里面访问其它成员，都是通过this->来调用的


对象的构造和析构的顺序刚好是相反的


说说对象
1.构造函数调用完了，对象就产生了（是给存放对象的内存进行初始化了）
2.析构函数调用完了，对象就释放了(是释放了对象占用的外部资源)


类 =》实例化  =》 对象  总共做两件事情
1：给对象开辟内存
2：调用合适的构造函数



二。拷贝构造函数
场景：同类型一个已经存在的对象构造新对象的时候，就会调用拷贝构造函数
结论1：当类里面没有提供拷贝构造函数的时候，编译器会产生一个默认的
拷贝构造函数，这个函数默认做内存拷贝

结论2：当对象浅拷贝出错，一定要提供自定义的拷贝构造函数

下节课提问的问题（女生）：
拷贝构造函数的形参，能不能按值传递？不能的话为什么？

三。赋值运算符的重载函数operator=
场景：两个已经存在的对象赋值的时候，会调用到该函数
结论1：当类里面没有提供赋值运算符的重载函数的时候，编译器会产生一个默认的
赋值运算符的重载函数，这个函数默认做内存赋值

下节课提问的问题（男生）：=>剑指offer的第一页
operator=函数先释放内存，再重新开辟内存时出异常，这种情况该怎么防止？



四。类和类的组合关系
组合：一个类定义的对象作为另外一个类的成员变量，这两个类之间的关系
就称为组合关系，一般满足a part of... ...一部分的关系 


五。对象的构造函数初始化列表
如果想在对象成员变量初始化的时候，指定成员变量的初始化方式，
那么应该在构造函数的初始化列表当中指定
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
Date birthday;  // 找不到Date的默认构造函数
};

*/

#if 0
//顺序栈
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

	//入栈操作
	void push(int val);
	//出栈操作
	void pop();
	//获取栈顶元素
	int top();
	//判断栈空
	bool empty(){ return mtop == -1; }
	//判断栈满
	bool full(){ return mtop == msize - 1; }
private:
	int *mpstack;
	int mtop;
	int msize;
};

//入栈操作
void SqStack::push(int val)
{
	if (full())
		return;
	mpstack[++mtop] = val;
}
//出栈操作
void SqStack::pop()
{
	if (empty())
		return;
	--mtop;
}
//获取栈顶元素
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
	SqStack mstack;  // 成员对象
	int a;
};

int main()
{

	return 0;
}
#endif

#if 0
//循环队列
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
//顺序容器
class Vector
{
public:
	//构造函数 根据指定的size动态开辟底层的数组空间，进行初始化
	//this指针  =》   对象的内存起始地址
	Vector(int size = 10)
	{
		cout << this << endl;
		cout << "Vecctor(int size = 10)" << endl;
		this->mpvec = new int[size];
		this->mcur = 0;
		this->msize = size;
	}
	//提供自定义的拷贝构造函数
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
	//自定义的赋值运算符的重载函数
	void operator=(const Vector &src)
	{
		cout << &src << " => " << this << endl;
		cout << "void operator=(const Vector&)" << endl;
		//判断自赋值的情况
		if (this == &src)
			return;

		//需要先释放this指针指向对象原来占用的外部资源
		delete[]mpvec;

		//重新开辟资源，拷贝数据
		mcur = src.mcur;
		msize = src.msize;
		mpvec = new int[msize];
		for (int i = 0; i < mcur; ++i)
		{
			mpvec[i] = src.mpvec[i];
		}
	}

	//析构函数了
	~Vector()
	{
		cout << this << endl;
		cout << "~Vector()" << endl;
		delete[]this->mpvec;
		this->mpvec = NULL;
	}
	//后置添加元素
	void push_back(int val)
	{
		if (full())
			this->resize();
		this->mpvec[this->mcur++] = val;
	}
	//后置删除元素
	void pop_back()
	{
		if (empty())
			return;
		mcur--;
	}
	//返回后置元素
	int back(){ return mpvec[mcur - 1]; }
	//判空
	bool empty(){ return mcur == 0; }
	//判满
	bool full(){ return mcur == msize; }
	//打印vector容器的方法
	void show()
	{
		for (int i = 0; i < this->mcur; ++i)
		{
			cout << this->mpvec[i] << " ";
		}
		cout << endl;
	}
private:
	//扩展空间用的，一次性扩找到原来的2倍
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
	//表示存储数据的数组
	int *mpvec;
	//表示当前元素的序号
	int mcur;
	//表示当前数组的大小
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

	//    Vector(Vector*)  =>   拷贝构造函数
	Vector vec3 = vec1;  // => Vector vec3 = vec1;

	//对于对象的各种运算都转成了左边的对象，调用相应的运算符的重载方法，把右边剩下的东西，当做实参传递进来
	//vec3.operator=(vec1);
	//void operator=(const Vector &vec)
	vec3 = vec3;
	

	return 0;
}



//顺序栈
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
	
	//入栈操作
	void push(int val);
	//出栈操作
	void pop();
	//获取栈顶元素
	int top();
	//判断栈空
	bool empty(){ return mtop == -1; }
	//判断栈满
	bool full(){ return mtop == msize - 1; }
private:
	int *mpstack;
	int mtop;
	int msize;
};

//入栈操作
void SqStack::push(int val)
{
	if (full())
		return;
	mpstack[++mtop] = val;
}
//出栈操作
void SqStack::pop()
{
	if (empty())
		return;
	--mtop;
}
//获取栈顶元素
int SqStack::top()
{
	if (empty())
		throw "stack is empty!";
	return mpstack[mtop];
}
int main()
{
	/*
	定义对象需要两步
	1：给对象分配内存
	2：给对象调用构造函数
	*/
	SqStack stack1;
	SqStack stack2(20);

	//“.push”的左边必须有类/结构/联合
	//SqStack stack3();
	//stack3.push(10);
	

	return 0;
	/*
	栈上的对象，在return除，自动调用对象的析构函数
	*/
}
#endif

