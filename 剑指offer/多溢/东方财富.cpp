#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

int main()
{
	char str[1024] = {0};
	cin.getline(str,1024);
	stack<char> st;
	int len =strlen(str);
	int index = 0;
	while (index < len)
	{
		if (str[index] == '{' || str[index] == '(' || str[index] == '[')
		{
			st.push(str[index++]);
		}
		else if (str[index] == ' ')
		{
			++index;
		}
		else 
		{
			if ((str[index] == '}' && st.top() == '{') || (str[index] == ']' && st.top() == '[') || (str[index] == ')' && st.top() == '('))
			{
				++index;
				st.pop();
			}
		}
	}
	if (!st.empty())
	{
		cout<<"NO"<<endl;
	}
	else
	{
		cout<<"YES"<<endl;
	}
	return 0;
}


#include<iostream>
using namespace std;
int N,M;

int func(int n, int m)
{	if(n < 1 || m < 1)		
    return -1; 	
    int result=0;
     for(int i=2;i<=N;i++)
     {
         result=(result+M)%i;
     }
 return result+1;
}

int main()
{
    while(cin>>N)
    {
        cin>>M;
        int res=func(N,M);
        cout<<res<<endl;
        N=0;
        M=0;
    }


