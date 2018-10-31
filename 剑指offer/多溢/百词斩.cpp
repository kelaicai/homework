#include<iostream>
#include<string>
#include<algorithm>
#include<functional>
#include<stack>
#include<limits.h>
using namespace std;

int MAX=INT_MAX;
int MIN=INT_MIN;

int input;
int flag=1;

int my_reverse()
{
    int temp=input;
    int kx=0;
    if(input<0)
    {
        temp=-1*input;
    }
    stack<int> st;
    while(temp)
    {
         st.push(temp%10);
         temp/=10;
    }
    while(!st.empty())
    {
        kx=kx*10+st.top();
        st.pop();
        if(kx>MAX)
        {
            return MAX;
        }
    }
    return kx*flag;
}
int main()
{
    int res=0;
     while(cin>>input)
     {
         if(input==0) 
         {
             cout<<input<<endl;
             continue;
         }
         flag=input>0?1:-1;
         res=my_reverse();
         cout<<res<<endl;
          input=0;
         res=0;
     }

}
