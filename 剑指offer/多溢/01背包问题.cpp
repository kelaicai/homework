#include<iostream>
#include<cstring>
#include<stdio.h> 
#include<stdlib.h>
using namespace std;


/*
一、基本概念

    动态规划过程是：每次决策依赖于当前状态，又随即引起状态的转移。
	一个决策序列就是在变化的状态中产生出来的，所以，这种多阶段最优化决策解决问题的过程就称为动态规划。

二、基本思想与策略

    基本思想与分治法类似，也是将待求解的问题分解为若干个子问题（阶段），按顺序求解子阶段，
	前一子问题的解，为后一子问题的求解提供了有用的信息。在求解任一子问题时，列出各种可能的局部解，
	通过决策保留那些有可能达到最优的局部解，丢弃其他局部解。依次解决各子问题，最后一个子问题就是
	初始问题的解。

    由于动态规划解决的问题多数有重叠子问题这个特点，为减少重复计算，对每一个子问题只解一次，
	将其不同阶段的不同状态保存在一个二维数组中。

    与分治法最大的差别是：适合于用动态规划法求解的问题，经分解后得到的子问题往往不是互相独立的
	（即下一个子阶段的求解是建立在上一个子阶段的解的基础上，进行进一步的求解）。
	
	三、适用的情况

能采用动态规划求解的问题的一般要具有3个性质：

    (1) 最优化原理：如果问题的最优解所包含的子问题的解也是最优的，就称该问题具有最优子结构，即满足最优化原理。

    (2) 无后效性：即某阶段状态一旦确定，就不受这个状态以后决策的影响。也就是说，某状态以后的过程不会影响
	以前的状态，只与当前状态有关。

   （3）有重叠子问题：即子问题之间是不独立的，一个子问题在下一阶段决策中可能被多次使用到。
   （该性质并不是动态规划适用的必要条件，
   但是如果没有这条性质，动态规划算法同其他算法相比就不具备优势）
   四、求解的基本步骤

     动态规划所处理的问题是一个多阶段决策问题，一般由初始状态开始，通过对中间阶段决策的选择，达到结束状态。这些决策形成了一个决策序列，同时确定了完成整个过程的一条活动路线(通常是求最优的活动路线)。如图所示。动态规划的设计都有着一定的模式，一般要经历以下几个步骤。

    初始状态→│决策１│→│决策２│→…→│决策ｎ│→结束状态

                      图1 动态规划决策过程示意图

    (1)划分阶段：按照问题的时间或空间特征，把问题分为若干个阶段。在划分阶段时，注意划分后的阶段一
	定要是有序的或者是可排序的，否则问题就无法求解。

    (2)确定状态和状态变量：将问题发展到各个阶段时所处于的各种客观情况用不同的状态表示出来。当然，
	状态的选择要满足无后效性。

    (3)确定决策并写出状态转移方程：因为决策和状态转移有着天然的联系，状态转移就是根据上一阶段的
	状态和决策来导出本阶段的状态。所以如果确定了决策，状态转移方程也就可写出。但事实上常常是反过来做，
	根据相邻两个阶段的状态之间的关系来确定决策方法和状态转移方程。

    (4)寻找边界条件：给出的状态转移方程是一个递推式，需要一个递推的终止条件或边界条件。

    一般，只要解决问题的阶段、状态和状态转移决策确定了，就可以写出状态转移方程（包括边界条件）。

实际应用中可以按以下几个简化的步骤进行设计：

    （1）分析最优解的性质，并刻画其结构特征。

    （2）递归的定义最优解。

    （3）以自底向上或自顶向下的记忆化方式（备忘录法）计算出最优值

    （4）根据计算最优值时得到的信息，构造问题的最优解
    
    五、算法实现的说明

    动态规划的主要难点在于理论上的设计，也就是上面4个步骤的确定，一旦设计完成，实现部分就会非常简单。

     使用动态规划求解问题，最重要的就是确定动态规划三要素：

    （1）问题的阶段 （2）每个阶段的状态

    （3）从前一个阶段转化到后一个阶段之间的递推关系。

     递推关系必须是从次小的问题开始到较大的问题之间的转化，从这个角度来说，动态规划往往可以用递归
	 程序来实现，不过因为递推可以充分利用前面保存的子问题的解来减少重复计算，所以对于大规模问题来说，
	 有递归不可比拟的优势，这也是动态规划算法的核心之处。

    确定了动态规划的这三要素，整个求解过程就可以用一个最优决策表来描述，最优决策表是一个二维表，
	其中行表示决策的阶段，列表示问题状态，表格需要填写的数据一般对应此问题的在某个阶段某个状态下
	的最优值（如最短路径，最长公共子序列，最大价值等），填表的过程就是根据递推关系，从1行1列开始，
	以行或者列优先的顺序，依次填写表格，最后根据整个表格的数据通过简单的取舍或者运算求得问题的最优解。

          f(n,m)=max{f(n-1,m), f(n-1,m-w[n])+P(n,m)}
*/
int N,C;
int dp[10240][10240];
int value[10240];
int weight[10240];
int findMaxValue()
{
	for(int i=0;i<N;i++)
	{
		dp[0][i]=0;  //第0件物品的时，不管容量有多大，它的价值都为0
		dp[i][0]=0;  //包容量为零，放不了物品，那么它的价值只能为0	
	} 
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=C;j++)  //C代表的是容量 
		{
			//dp[i][j]表示第i件物品容量为j时的最大价值 
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);	
		}	
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<C;j++)
		{
			cout<<"dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return dp[N][C]; 
}
int main()
{
		while(cin>>N>>C)
		{
			
			for(int i=1;i<=N;i++)
			{
				cin>>weight[i]; 
			} 
			for(int i=0;i<N;i++)
			{
				cin>>value[i];
			}
			int res=findMaxValue();
			cout<<res<<endl;
			memset(value,0,sizeof(value));
			memset(weight,0,sizeof(weight));
			N=0;
			C=0;
		}
} 
