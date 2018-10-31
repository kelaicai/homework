#include<iostream> 
#include<thread> 
#include<algorithm>
#include<functional>
#include<vector>
#include<string> 
#include<deque> 
using namespace std;
int i;
int num;
int fun(int arr[],int inc,int len)
{
	if(inc==1)  return 1;
	bool brr[10]={false};
	if(inc==2)  
	{
		
		if(arr[i]*10+arr[i+1]<25)
		{
			num++;	
		}
		else
		{
			fun(arr,inc-1,len);
		}
	}
}

int fun2(int arr[],int len)
{
	for(int i=0;i<len;i++)
	{
		for(int inc=0;inc<len;inc++)
		if(arr[i]*10+arr[i+1]<26)
		{
				
		}
		
	}	
}
int numDecodings(string &s)
 {
        // write your code here
        if(s.length()==0) return 0;
        s.insert(0,"0");//dp从第一位开始算起，在第0位插入一个0，则遇到输入“0”时会判断到“00”而判断为无法解码，返回0.
        vector<int> n;
        n.push_back(1);//作为-1位的填充
        n.push_back(1);//第0位，除输入“0”以外，必有一种解码情况
        for(int i=1;i<s.length();i++)
        {
            if(s[i]=='0' && (s[i-1]=='0' || s[i-1]>='3')) return 0;
            if((s[i-1]=='2'&& s[i]<='6' && s[i]>='1' || s[i-1]=='1' && s[i]!='0') && (i+1==s.length() || s[i+1]!='0'))
            {
                n.push_back(n[i]+n[i-1]);
            }
            else
            {
                n.push_back(n[i]);
            }
        }
        return n.back();
}


string find_min_seq(string& str)
{
	deque<char> de_s;
	deque<char> de_r;
	
	string res;
	for(int i=0;i<str.size();i++)
	{
		de_s.push_back(str[i]);
		de_r.push_front(str[i]);	
	}
	
	for(int i=0;i<str.size();i++)
	{
		if(de_s.front()<de_r.back())
		{
			res+=de_s.front();
		}
		else if()
		res+=de_s.front()<de_r.back()?de_s.front(),de_s.pop_back():de_r.back(),de_r.pop();	
	}	
	return res;
}


int main()
{
	/*
	string str("27");
	cout<<numDecodings(str)<<endl;
	*/
		cout<<find_min_seq("ACDBCB")<<endl;
}
