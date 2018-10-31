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
	//vec��ÿ��ƻ���ĸ���
	//que���ʵ�ƻ��que[i]���ڵĶ�
	int vsize=vec.size();
	int qsize=que.size();
	int sum=0;
	vector<int>  temp;
	
	//����ۼƵ���i��ƻ������ 
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
              //��Ҫ��pos��¼��һ�����ڵ���key��Ԫ��λ��

    while(left < right)
    {
        mid= (left+right)/2;
        if(temp[mid] <que[i] ){      //����λ����ֵС��key��ֵ������Ҫ���ұ��������в��ң���ʱ��pos�������ұ������еĵ�һ��
            left = mid + 1;
            pos = left;
        }
        else{
            right = mid;           //����λ����ֵ���ڵ���key������Ҫ����������в��ң����п���middle����������λ�ã��������ǲ��ƶ�last,
            pos = right;              //������first���ϱƽ�last��
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
	cout<<"����n����"<<endl; 
	cin>>n;   //n��ƻ����
	for(int i=0;i<n;i++)
	{
		cin>>c;
		vec.push_back(c);	
	} 
	cout<<"������ʴ���"<<endl;
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
