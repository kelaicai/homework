#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

int N;
int arr[10240];
using namespace std;
int main()
{
    vector<int>  vec;
    while(cin>>N)
    {
        for(int i=0;i<N;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+N);
        for(int i=0;i<N;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        N=0;
        memset(arr,0,N);
    }
}
