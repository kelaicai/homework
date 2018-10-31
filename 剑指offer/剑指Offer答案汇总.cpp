
#include<iostream>
#include<functional>
#include<algorithm>
#include<vector> 
#include<string>
/*
��Ŀ������  ������·��ΪK��·������ 
����һ�Ŷ������ĸ��ڵ��һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����·������Ϊ������
����㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����(ע��: �ڷ���ֵ��list�У����鳤�ȴ�����鿿ǰ)
*/
class Solution {
public:
    
    vector<vector<int>>  Result;
    vector<int> temp;
    void dfs(TreeNode* node,int left)
    {
        temp.push_back(node->val);
        if(left-node->val==0 && 
          !node->left&& !node->right)
        {
           Result.push_back(temp);
        }
        else{
            if(node->left) dfs(node->left,left-node->val);
            if(node->right) dfs(node->right,left-node->val);
        }
        temp.pop_back();
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        
        vector<vector<int>>  path;
        if(root)  dfs(root,expectNumber);
        return Result;
    }
};

/*
��Ŀ����  ��ά�����еĲ��� 
��һ����ά�����У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������
ÿһ�ж����մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ��������
�ж��������Ƿ��и�����
*/
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int R=array.size();
        int C=array[0].size();
          bool found=false;
        for(int i=R-1,j=0;i>=0&& j<C;)
        {
            if(target==array[i][j])
            {
                found=true;
                break;
            }
            if(target<array[i][j])
            {
                i--;
                continue;
            }
            if(target>array[i][j])
            {
                j++;
                continue;
            }
        }
        return found;
    }
};
/*
��������˫������ 
���ӣ�https://www.nowcoder.com/questionTerminal/947f6eb80d944a84850b0538bf0ec3a5
��Դ��ţ����
*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == nullptr) return nullptr;
        TreeNode* pre = nullptr;
         
        convertHelper(pRootOfTree, pre);
         
        TreeNode* res = pRootOfTree;
        while(res ->left)
            res = res ->left;
        return res;
    }
     
    void convertHelper(TreeNode* cur, TreeNode*& pre)
    {
        if(cur == nullptr) return;
         
        convertHelper(cur ->left, pre);
         
        cur ->left = pre;
        if(pre) pre ->right = cur;
        pre = cur;
         
        convertHelper(cur ->right, pre);
         
         
         
    }
};
/*

��Ŀ��

С����ϲ����ѧ,��һ����������ѧ��ҵʱ,Ҫ������9~16�ĺ�,�����Ͼ�д������ȷ����100�����������������ڴ�,�����뾿���ж������������������еĺ�Ϊ100(���ٰ���������)��û���,���͵õ���һ������������Ϊ100������:18,19,20,21,22�����ڰ����⽻����,���ܲ���Ҳ�ܿ���ҳ����к�ΪS��������������? Good Luck! 
�������:
������к�ΪS�������������С������ڰ��մ�С�����˳�����м䰴�տ�ʼ���ִ�С�����˳�� 
���ӣ�https://www.nowcoder.com/questionTerminal/c451a3fd84b64cb19485dad758a55ebe
��Դ��ţ����

//�����˼·��˫ָ������
//���ܺ�С��sum����ָ�����+
//����Сָ��+

*/
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > allRes;
        int phigh = 2,plow = 1;
         
        while(phigh > plow){
            int cur = (phigh + plow) * (phigh - plow + 1) / 2;
            if( cur < sum)
                phigh++;
             
            if( cur == sum){
                vector<int> res;
                for(int i = plow; i<=phigh; i++)
                    res.push_back(i);
                allRes.push_back(res);
                plow++;
            }
             
            if(cur > sum)
                plow++;
        }
         
        return allRes;
    }
};
�Ż�����ѧ֧��
���ӣ�https://www.nowcoder.com/questionTerminal/c451a3fd84b64cb19485dad758a55ebe
��Դ��ţ����

1����������Ҫ�ҵ��Ǻ�ΪS�������������У������������Ǹ�����Ϊ1�ĵȲ����У���������е��м�ֵ������ƽ��ֵ�Ĵ�С���������г���Ϊn��
��ô������е��м�ֵ����ͨ����S / n���õ���֪�����е��м�ֵ�ͳ��ȣ�Ҳ�Ͳ��������������ˡ�
2������������n�����������
nΪ����ʱ�������м�������������е�ƽ��ֵ����������Ϊ��(n & 1) == 1 && sum % n == 0��
nΪż��ʱ�������м���������ƽ��ֵ�����е�ƽ��ֵ�������ƽ��ֵ��С������Ϊ0.5����������Ϊ��
(sum % n) * 2 == n.
3�������֪n >= 2����ôn�����ֵ�Ƕ����أ�������ȫ���Խ�n��2��Sȫ������һ�Σ����Ǵ󲿷ֱ����ǲ���Ҫ�ġ�
Ϊ����n�����ܴ����������д�1��ʼ��
���ݵȲ����е���͹�ʽ��S = (1 + n) * n / 2���õ�.

����һ�����ӣ���������sum = 100������ֻ�����n = 13~2�������������Ӧ�Ӵ�С��������n = 8ʱ��
�õ�����[9, 10, 11, 12, 13, 14, 15, 16]��n  = 5ʱ���õ�����[18, 19, 20, 21, 22]�� 
���ӣ�https://www.nowcoder.com/questionTerminal/c451a3fd84b64cb19485dad758a55ebe
��Դ��ţ����

import java.util.ArrayList;
public class Solution {
    public ArrayList<ArrayList<Integer> > FindContinuousSequence(int sum) {
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        for (int n = (int) Math.sqrt(2 * sum); n >= 2; n--) {
            if ((n & 1) == 1 && sum % n == 0 || (sum % n) * 2 == n) {
                ArrayList<Integer> list = new ArrayList<>();
                for (int j = 0, k = (sum / n) - (n - 1) / 2; j < n; j++, k++) {
                    list.add(k);
                }
                ans.add(list);
            }
        }
        return ans;
    }
}


/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/

/*
֮���δ�ӡ������ 
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>>  res;
        if(pRoot==nullptr)
            return res;
        queue<TreeNode*>  dq;
        dq.push(pRoot);
        int i=1;
        bool  even=false;
        while(!dq.empty())
        {
            int size=dq.size();
            vector<int>  vec;
    
            for(int i=0;i!=size;i++)
            {
                TreeNode* temp=dq.front();
                dq.pop();
                vec.push_back(temp->val);
               if(temp->left) dq.push(temp->left);
                if(temp->right) dq.push(temp->right);
            }
   
            
            if(even)  reverse(vec.begin(),vec.end());
            res.push_back(vec);
            even=!even;
            
        }
         return  res;
    }
    
};


/*
��Ŀ����
��ʵ�������������ֱ��������л��ͷ����л�������
*/

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    char* Serialize(TreeNode *root) {    
        if(root==NULL)  return NULL;
        
        string str;
        Serialize(root,str);
        int size=str.length();
        char *res=new char[size+1]();
        int i=0;
        for(;i<size;i++)
        {
            res[i]=str[i];
        }
        res[i]='\0';
        return res;
    }
    
    void Serialize(TreeNode* root,string& str)
    {
        if(root==NULL) 
        {
            str+='#';
            return ;
        }
        string r=to_string(root->val);
        str+=r;
        str+=',';
        Serialize(root->left,str);
        Serialize(root->right,str);
    }
    
    
    
    
    
    
    
    
    
    TreeNode* Deserialize(char *str) {
        if(str==NULL)
            return NULL;
        TreeNode* res=Deserialize(&str);
        return  res;
    }
    
    TreeNode* Deserialize(char **str)
    {
        if(**str=='#')
        {
            ++(*str);
            return NULL;
        }
        
        int num=0;
        while(**str!='\0' && **str!=',')
        {
            num=num*10+(**str-'0');
           ++(*str);
        }
        TreeNode* p=new TreeNode(num);
       if(**str=='\0')
       {
           return p;
       }
        else{
             ++(*str);
        }
        
        p->left=Deserialize(str);
        p->right=Deserialize(str);
        return p;
    }
};
int  main()
{
	to_string();
 } 
