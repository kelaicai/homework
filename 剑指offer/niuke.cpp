 #include <iostream>
#include<vector>
using namespace std;
/*
定义变量cave表示兔子第i天所在的洞的编号  则有cave=a[i%n+1]这个表达式
 
*/

int search_cave(int n,int k)
{
	if(k<0 || n<0) return 0;
	return 0;
}
int main() {
    vector<int> vec;
    int n; //表示兔子的洞的个数
	int k;  //小强所检查洞的编号 
	int ret=0;
	 while(1)
	 {
	 		cin>>n>>k;
	 		int tmp=k;
	 		int tmp2=0;
	 		while(tmp--)
	 		{
	 			cin>>tmp2;
	 			vec.push_back(tmp2);
			 }
	 		ret=search_cave(n,k); 
			
			 cout<<n<<k<<endl; 
	 } 
}
