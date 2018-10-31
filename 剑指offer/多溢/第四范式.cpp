#include<iostream>
#include<vector>
#include<string>
using namespace std;
//最长对称子串 
string longest_Palindrome(string s) {
    int size = s.size();
    if (size <= 1) return s;

    vector<vector<int>> dp(size);
    for (int i = 0; i<size; i++) {
	    for (int j = 0; j<size; j++) {

		    if(i==j) dp[i].push_back(1);
		    else dp[i].push_back(0);
	        }
    }
    int start = 0, max = 1;
    for (int j = 0; j < size;j++){
	    for (int i = j - 1; i >= 0; i--) {
		    if (s[i] == s[j]) {
			    if(j-i==1) dp[i][j] = 2;
			    else {
				      if (dp[i + 1][j - 1]>0) {
					    dp[i][j] = dp[i + 1][j - 1] + 2;
				    }
				else dp[i][j] = 0;
			}
		}
		else dp[i][j] = 0;
		if (dp[i][j]>max) {
			max = dp[i][j]; start = i;
		}
	}
    }
    return s.substr(start, max);
}
string str1;
string str2;
int main()
{
    
    
    while(cin>>str1)
    {
        str2 = longest_Palindrome(str1);
        cout<<str2<<endl;
    }
    return 0;
}

/**
字符串的乘积 
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
string xiangcheng(string num1, string num2) {
    
        int left = num1.length();
        int right = num2.length();
        vector<int> num(left+right,0);
        for(int i=0;i<left;i++)
        {
            int n1=num1[left-1-i]-'0';
            int temp=0;
            for(int j=0;j<right;j++)
            {
                int n2=num2[right-1-j]-'0';
                temp=temp+num[i+j]+n1*n2;
                num[i+j]=temp%10;
                temp/=10;
            }
            num[i+right]=temp;
        }
        int i=left+right-1;
        while(i>0&&num[i]==0)i--;
        string result="";
        while(i>=0)
        {
            result+=static_cast<char>('0'+num[i--]);
        }
        return result;
}
string str1;
string str2;
string str3;
int main()
{
    
    while(cin>>str1>>str2)
    {
        str3 = xiangcheng(str1,str2);
        cout<<str3<<endl;
        str1.clear();
        str2.clear();
        str3.clear();
    }
    return 0;
}

