#include<iostream>
#include<vector>
using namespace std;

int record[1024];
int n,m;
struct diff{
	int redix;
	int redix_num;
	int dec_num; 
};
struct diff* convert(vector<string> vec)
{
	if(vec.size()==0) return NULL;
	int len=vec.size();
	diff *con_arr=new diff[len];
	for(int i=0;i<len;i++)
	{
		int num=0;
		int j=0;
		for(;j<vec[i].size() && vec[i][j]!='#';j++)
		{
			if(vec[i][j]!='#')
			{
				num=num*10+vec[i][j]-'0';
			}
	
		}
		con_arr[i].redix=num;
		j=j+1;
		//计算数值 
		num=0;
		for(;j<vec[i].size();j++)
		{
			num=num*10+vec[i][j]-'0'; 
		}
		con_arr[i].redix_num=num;
		
		int k=con_arr[i].redix;
		int con_num=con_arr[i].redix_num;
		num=0;
		int low=0;
		while(con_num)
		{
			low=con_num%k;  //获取个位 
			num=low*k;    // 
			k=k*k;
			con_num/=K;
		}
		con_arr[i].dec_num=num; 
	}
	return con_arr;
}
string findDiff(vector<string> vec)
{
	struct diff * con=convert(vec);
	
	string res;
	for(int i=0;i<vec.size();i++)
	{
		record[con[i].dec_num]++;
	}
	for(int i=0;i<vec.size();i++)
	{
		if(record[i]==1)
		{
			res=vec[i];
			break;
		}
	}
	return res;
} 
int main()
{
	string str;
	vector<string> vec;
	while(cin>>str && str!="END")
	{
		vec.push_back(str);
		str.clear();
	}
	string res=findDiff(vec);
	cout<<res<<endl;
	return 0;
	
} 
