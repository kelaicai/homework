#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<pair<int, int> > MyList;

MyList cover(const MyList& intervals)
{ 
	int left = intervals[0].first, right = intervals[0].second; 
	MyList result;
	for (int i = 1; i < intervals.size(); ++i)
	{
		if (intervals[i].first > right)
		{ 
			result.push_back(make_pair(left, right));
			left = intervals[i].first;
			right = intervals[i].second; 
		}
		else if (intervals[i].second > right) 
		{
			right = intervals[i].second; 
		}
	} 
	result.push_back(make_pair(left, right));
	return result; 
}

void display(const MyList& intervals)
{
	for (int i = 0; i < intervals.size(); ++i)
	{
		cout << intervals[i].first << "," << intervals[i].second << " ";
	}
    cout << endl;
}


int main()
{ 
	MyList intervals; 
	int start, end; 
	char c;
	while(cin >> start >> c >> end, cin.good())
	{ 
		intervals.push_back(make_pair(start, end)); 
	}
	sort(intervals.begin(), intervals.end()); 

	MyList result = cover(intervals); 
	for(auto i:result)
	{
		cout<<i.first<<i.second<<endl; 
	}
	display(result); 
	return 0; 
}

