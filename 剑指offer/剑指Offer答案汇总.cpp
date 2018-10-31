
#include<iostream>
#include<functional>
#include<algorithm>
#include<vector> 
#include<string>
/*
题目描述：  二叉树路径为K的路径集合 
输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的
根结点开始往下一直到叶结点所经过的结点形成一条路径。(注意: 在返回值的list中，数组长度大的数组靠前)
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
题目描述  二维数组中的查找 
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，
判断数组中是否含有该整数
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
二叉树和双向链表 
链接：https://www.nowcoder.com/questionTerminal/947f6eb80d944a84850b0538bf0ec3a5
来源：牛客网
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

题目：

小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck! 
输出描述:
输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序 
链接：https://www.nowcoder.com/questionTerminal/c451a3fd84b64cb19485dad758a55ebe
来源：牛客网

//左神的思路，双指针问题
//当总和小于sum，大指针继续+
//否则小指针+

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
优化：数学支持
链接：https://www.nowcoder.com/questionTerminal/c451a3fd84b64cb19485dad758a55ebe
来源：牛客网

1）由于我们要找的是和为S的连续正数序列，因此这个序列是个公差为1的等差数列，而这个序列的中间值代表了平均值的大小。假设序列长度为n，
那么这个序列的中间值可以通过（S / n）得到，知道序列的中间值和长度，也就不难求出这段序列了。
2）满足条件的n分两种情况：
n为奇数时，序列中间的数正好是序列的平均值，所以条件为：(n & 1) == 1 && sum % n == 0；
n为偶数时，序列中间两个数的平均值是序列的平均值，而这个平均值的小数部分为0.5，所以条件为：
(sum % n) * 2 == n.
3）由题可知n >= 2，那么n的最大值是多少呢？我们完全可以将n从2到S全部遍历一次，但是大部分遍历是不必要的。
为了让n尽可能大，我们让序列从1开始，
根据等差数列的求和公式：S = (1 + n) * n / 2，得到.

最后举一个例子，假设输入sum = 100，我们只需遍历n = 13~2的情况（按题意应从大到小遍历），n = 8时，
得到序列[9, 10, 11, 12, 13, 14, 15, 16]；n  = 5时，得到序列[18, 19, 20, 21, 22]。 
链接：https://www.nowcoder.com/questionTerminal/c451a3fd84b64cb19485dad758a55ebe
来源：牛客网

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
之字形打印二叉树 
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
题目描述
请实现两个函数，分别用来序列化和反序列化二叉树
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
