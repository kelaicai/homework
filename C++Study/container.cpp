#include<iostream>
#include<vector> //包含C++向量容器的代码
#include<functional>  //包含C++ stl函数对象的代码greater,less,,二元函数对象
#include<algorithm>  //包含C++ 的泛型算法实现  sort find
#include<ctime>
using namespace std;


/*
1，请输出showContainer函数模板，通过迭代器，打印容器里元素的值
*/

template<typename container>
void showContainer(container &con)
{
	container::iterator it = con.begin();

	for (; it != con.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

template<typename container>
void sort_t(container &con)
{
	container::iterator it = con.begin();
	
	for (; it != con.end(); ++it)
	{
		for (container::iterator it_i = con.begin(); it_i != con.end(); ++it_i)
		{
			if (*it_i < *(it_i + 1))
			{
				
			}
		}
	}
}


int main()
{
	vector<int> vec;
	srand(time(0));
	for (int i = 0; i < 20; i++)
	{
		vec.push_back(rand() % 100);
	}
	showContainer(vec);
	sort(vec.begin(), vec.end(),less<int>());
	showContainer(vec);
	sort(vec.begin(), vec.end(), greater<int>());
 
    showContainer(vec);
	vector<int>::iterator it = find(vec.begin(), vec.end(), 50);
	if (*it==50)
	{
		cout << "存在数" << endl;
		vec.erase(it);
	}
	else
	{
		cout << "不存在数" << endl;
	}

	showContainer(vec);
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		if (*it % 2 == 0)
		{
			vector::iterator it_t = it;
			it=vec.erase(it);
			--it_t;
		}
	}
	showContainer(vec);

	for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		if (*it % 2 == 1)
		{
			it=vec.insert(it-1,(*it)-1);
		}
	}
	showContainer(vec);

 /*迭代器失效： 在向容器中insert或者rease删除元素时，会使得被插入位置和删除位置的迭代器失效
 需要更新-->由于Inert和erase返回的是更新后的 迭代器，因此使用原迭代器接收被修改过的迭代器即可
 如下
 
 for(vector<int>::iterator it=vec.begin();it!=begin();++it)
 {
 	if(*it%2==0)
 	{
		it=vec.erase(it);
	 }
 } 
 */
	
/*
vector向量容器

底层数据结构
内存增长方式
增删改查方式

初始内存开辟内存次数太多了 --》默构造容器大小为零，一次为1，二次为2，，，，2^n 
reserve  预留，保留 
resize 


swap  
step1 判断自赋值
step2 判断空间配置器是否一样（内存管理方式），只交换成员变量 
step3  空间配置器不一样，效率非常低，设计对象的构造和析构

empty()  || size()==0


gcc可以编译C++ g++可以c嘛？   有什么不同 
*/ 

	
	vec.reserve(100); //预留100个元素空间 ---->解决vector初始的时候开辟内存效率太低 
	vec.size(); //--》 返回元素的个数   0
	
	vec.resize(100);  //-->添加了100个元素，  
	vec.size();  //-->>100 
	
	vec.swap(vec1); 

	system("pause");
}
