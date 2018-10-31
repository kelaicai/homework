#include<iostream>
#include<vector>
using namespace std;
int lower_bound(int arr[],int size,int key)
{
	int first=0,middle;
	int half,len;
	len=size;
	while(len>0)
	{
		half=len>>1;
		middle=first+halt;
		if(arr[middle]<key)
		{
			first=middle+1;
			len=len-half-1;
		}else len=half;
	}
	return first;
} 

void fun(vector<int> vec,vector<int> que,vector<int>& res)
{
	//vec是每堆苹果的个数
	//que是问的苹果que[i]所在的堆
	int vsize=vec.size();
	int qsize=que.size();
	int sum=0;
	vector<int>  temp;
	
	//求出累计到堆i的苹果总数 
	for(int i=0;i<vsize;i++)
	{
		sum+=vec[i];
		temp.push_back(sum);
	} 
	int tsize=temp.size();

	int i=0;
	int pos=0;
    for(int i=0;i<qsize;i++)
	{
		int left=0;
		int right=tsize-1;
		int mid=left+(right-left+1)/2;
              //需要用pos记录第一个大于等于key的元素位置

    while(left < right)
    {
        mid= (left+right)/2;
        if(temp[mid] <que[i] ){      //若中位数的值小于key的值，我们要在右边子序列中查找，这时候pos可能是右边子序列的第一个
            left = mid + 1;
            pos = left;
        }
        else{
            right = mid;           //若中位数的值大于等于key，我们要在左边子序列查找，但有可能middle处就是最终位置，所以我们不移动last,
            pos = right;              //而是让first不断逼近last。
        }
    }
	 res.push_back(pos+1);
	 pos=0;
	}

	 	
}

int main()
{
	int n,m;
	vector<int>  vec,que,res;
	int c;
	cout<<"输入n个堆"<<endl; 
	cin>>n;   //n个苹果堆
	for(int i=0;i<n;i++)
	{
		cin>>c;
		vec.push_back(c);	
	} 
	cout<<"输入访问次序"<<endl;
	cin>>m; 
	for(int i=0;i<m;++i)
	{
		cin>>c;
		que.push_back(c);
	} 
	
	fun(vec,que,res);
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]<<endl; 
	}
} 
