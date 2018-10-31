#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> vec;

int t;
int n;
int ins;
bool flags[128];


string fun(string str,int left,int right)
{
	char s=str[left];
    for(int i=left,j=right;i<j;i++,j--)
    {
        swap(str[i],str[j]);
    }
 	for(int i=0;i<str.size();i++)
 	{
 		if(str[i]==str[left])
		 {
			str[i]='h'; 	
		 }	
	}
	cout<<str<<endl;
    return str;
}
int main()
{
    while(cin>>t)
    {
        
        int k=0;
        for(int i=0;i<t;i++)
        {
            cin>>n;
           
            for(int j=0;j<n;j++)
            {
                 string temp;
                 cin>>temp;
                 vec.push_back(temp);
                  k++;
            }
            if(vec[k-1].size()!=vec[k-2].size())
            {
                cout<<"Sad"<<endl;
            }
           
            int len=vec[k-2].size();
            int num=0;
             for(int n=0;n<len;n++)
             {
                  if(vec[k-1]==fun(vec[k-2],n,vec[k-2].size()))
                  {
                      flags[ins++]=true;
                      break;
                  }
              }
            }
        
        for(int p=0;p<ins;p++)
        {
            if(flags[p])
            {
                cout<<"Yeah"<<endl;
            }
            else
            {
                cout<<"Sad"<<endl;
            }
        }
            
    }
     
    
}
