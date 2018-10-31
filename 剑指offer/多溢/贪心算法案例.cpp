#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
struct sechule
{
	int start;
	int end;
	bool isAllowed(int time)
	{
		return time > start&&time <= end;
	}
}sechule;
 
int N;
int start[1000];
int finish[1000];
int main()
{
	
	while (cin >>N)
	{
		sechule plan[100];
		
		for (int i = 0; i < N; i++)
		{
			
			cin >>start[i];
			
		}
		for (int i = 0; i < N; i++)
		{
			cin>>finish[i];
		}
		for (int i = 0; i < N; i++)
		{
			sechule tim;
			tim.start = start[i];
			tim.end = finish[i];
			plan[i] = tim;
		}
 
		sort(start, start + N);
		sort(finish, finish + N);
		int min = start[0];
		int max = finish[N - 1];
 
		int maxcount = 0;
		for (int i = min; i <= max; i++)
		{
			int count = 0;
			for (int j = 0; j < N; j++)
			{
				if (plan[j].isAllowed(i))
				{
					count++;
				}
			}
			if (count>maxcount)
			{
				maxcount = count;
			}
		}
		cout << maxcount << endl;
	}
}

 
