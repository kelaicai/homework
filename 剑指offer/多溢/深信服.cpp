#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

int N1,N2;

int main()
{
	vector<int> vec;
	deque<int> dq;
	while(cin>>N1)
	{
		int temp;
		for(int i=0;i<N1;i++)
		{
			cin>>temp;
			vec.push_back(temp);
		}
		cin>>N2;
		for(int i=0;i<N2;i++)
		{
			cin>>temp;
			dq.push_back(temp);
		}
		while(!dq.empty()) 
		{
			int t=dq.front();
			dq.pop_front();
			vec.push_back(t);
			sort(vec.begin(),vec.end());
			int mid=vec.size()%2==0?vec.size()/2-1:vec.size()/2;
			cout<<vec[mid]<<endl;
		}
		
	}
}
/*

#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

int N1,N2;
int arr[10240];
int brr[10240];
int main()
{
	vector<int> vec;
	deque<int> dq;
	while(cin>>N1)
	{
		int temp;
		for(int i=0;i<N1;i++)
		{
			cin>>arr[i];
		}
		cin>>N2;
        int i=0;
		for(;i<N2;i++)
		{
			cin>>brr[i];
		}
        for(int j=0;j<N2;j++)
        {
            arr[i+j]=brr[j];
            sort(arr,arr+i+j);
            int mid=(i+j)%2==0?(i+j)/2-1:(i+j)/2;
            cout<<arr[mid]<<endl;
        }
        /*
		for(;!dq.empty();)
		{
			int t=dq.front();
			dq.pop_front();
			vec.push_back(t);
			sort(vec.begin(),vec.end());
			
			cout<<vec[mid]<<endl;
		}
        
		
	}
}
*/

#include <iostream>
using namespace std;
int T; 
int arr[T][2];
int main()
{
   
    cin>>T;
   
    for(int i = 0;i<T;i++)
    {
        cin>>arr[i][0];
        cin>>arr[i][1];
    }
    
    for(int i = 0;i < T;i++)
    {
        int max_value = 0;
        if(arr[i][1] > arr[i][0])
            max_value = arr[i][0] * ( arr[i][1] - arr[i][0]);
        int len = arr[i][1]/3;
        int mlen =len + arr[i][1] %3;
        while(len >=1)
        {
            int value = mlen *len;
            if(value > max_value) max_value = value;
            mlen += 2;
            len --;
        }
        cout<<max_value<<endl;
    }
    
    return 0;
}
