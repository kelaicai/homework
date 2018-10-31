



#include "Link.h"
#include "Queue.h"
#include "Stack.h"

/*
C++作业01： 要求如下：
1，软件运行以后，打印一个menu界面，显示支持的数据结构，如下：
=====================================
1.单链表  2.循环队列  3.顺序栈  4.退出系统
=====================================
请选择：

2.用户选择4，输出byebye，系统退出！，如果选择1，2，3项，进入
子菜单，显示如下：
=======================
当前数据结构为： xxx
1.增加   
2.删除
3.修改
4.查询
5.返回
=======================
请选择：

1.增加:提示用户输入一个或者一组整数，添加到数据结构当中，显示
增加成功或者失败，完成后，继续显示子菜单
2.删除：输入指定的值，在数据结构中全部删除掉，显示结果，完成后，继续显示子菜单
3.修改：提示输入需要修改的数据，再输入修改后的数据，进行全文修改，显示结果，完成后，继续显示子菜单
4.查询：显示数据结构所有的数据
5.返回：返回主菜单

*/

class DTSystem
{
public:
	DTSystem();
	void run();
	void showMainMenu();
	void showChildMenu();
private:
	bool isSysRunning;
	Link mLink;
	SqStack mStack;
	CircleQue mQueue;
};

//放在在类外实现，简单的方法可以直接在类体中实现

int main()
{
	DTSystem system;
	system.run();
	return 0;
}

