 #include <iostream>
#include<vector>
using namespace std;
/*
�������cave��ʾ���ӵ�i�����ڵĶ��ı��  ����cave=a[i%n+1]������ʽ
 
*/

int search_cave(int n,int k)
{
	if(k<0 || n<0) return 0;
	return 0;
}
int main() {
    vector<int> vec;
    int n; //��ʾ���ӵĶ��ĸ���
	int k;  //Сǿ����鶴�ı�� 
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
