#include<iostream>
using namespace std; 
int main()
{
	int n;
	cin >> n;
	int arr[MAXSIZE];
	int brr[MAXSIZE];
	int tmp;
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		arr[i] = tmp;
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		brr[i] = tmp;
	}
	//cout << Result(arr, brr, 0, n-1) << endl;

	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; j++)
		{
			int max = amax(arr, i, j);
			int min = bmin(brr, i, j);
			if (max < min)
			{
				++count;
			}
			else
			{
				break;
			}
		}
	}
	cout << count << endl;
	return 0;
}


