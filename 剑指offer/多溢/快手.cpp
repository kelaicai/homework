#include<iostream>
#include<vector>
#include<string>
using namespace std;

int fun(string str)
{
	int len=str.size();
	int num=0;
	for(int i=0;i<len;i++)	
	{
		num++; //字母本身就是一个 
		int flag=false;
		for(int j=0,k=i;j<k;j++,k--)
		{
			int flag=false;
			if(str[j]!=str[k])
			{
				flag=true;
			}
		}
		if(!flag)
		{
			num++;
		}
	}
	return num;

} 

int main()
{
	
	string input;	
	 while(cin>>input)
	 {
	 	int res=fun(input);
	 	cout<<res<<endl;
	 }
}
/*交上去的答案**/
#include<iostream>
#include<string>
using namespace std;
int countSubstrings(string s) {
	if (s.length() == 0)
		return 0;
	int len_res = 0;

	string new_s = "$#";
	for (int i = 0; i < s.length(); i++)
	{
		new_s += s[i];
		new_s += "#";
	}

	for (int i = 1; i < new_s.length(); i++){
		int p = 1;
		while (new_s[i - p] == new_s[i + p]) {
			p++;
		}
		len_res += (p - 1) / 2;
	}

	return len_res + s.length();

}
int main()
{
	string s;
	cin >> s;
	int a=countSubstrings(s);
	cout << a << endl;
	return 0;
}

