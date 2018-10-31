/*
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int data[20];
int less[4];
const int N=16;
int index;
int leap;

bool isLeap(int num)
{
	if(num==1) return true;
	
	if(num==2 || num==3) return true;
	
	if(num%2==0) return false;
	
	int rang=sqrt(num)+1;
	for(int i=3;i<=rang;i++)
	{
		if(num%i==0) return false;
	}
	return true;
}
int findLessAndCountLeap()
{
	sort(data,data+16);
	
	for(int i=1;i<16;i++)
	{
		int diff=data[i]-data[i-1];
		if(diff!=1)
		{
			less[index++]=data[i-1]+diff;
			
		}
	}
		
}

int main()
{
		
} 
*/

#include <iostream>
#include <algorithm>
using namespace std;
bool sushu(int num)
{
    int i = 2;
    for ( ;i <= sqrt(num); i++)
    {	
	    if (num%i == 0) return false;		
    }
    return true;
}
int main()
{
	int tmp, num = 0;
	const int len = 21;
	int hash[len] = { 0 };
	int mem[10]={0};
	int index=0;
	int idx=0;
	while (cin >> tmp &&idx<)
	{
		hash[tmp]++;
	}
	for (int i = 1; i < len; ++i)
	{
		if (hash[i] == 0)
		{
			cout << i << " ";
			mem[index++]=i;
			
		}
	} 
	for(int i=0;i<index;i++)
	{
		if(sushu(mem[i]))
		{
			num++;
		}
	}
	cout << num << endl;
	return 0;
}


