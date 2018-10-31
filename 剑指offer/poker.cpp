

#include <iostream>

#include <cstdio>

#include <cstring>

#include <vector>

#include <algorithm>

#define INF 0x3f3f3f3f

using namespace std;



int n;

int x[105],y[105];

int max_score;



int main(){

/**/ /**/ while(scanf("%d",&n)!=EOF){

/**/ /**/ /**/ /**/ int x_sum = 0;

/**/ /**/ /**/ /**/ for(int i=0;i<n;i++){

/**/ /**/ /**/ /**/ /**/ /**/ scanf("%d%d",x+i,y+i);

/**/ /**/ /**/ /**/ /**/ /**/ x_sum += x[i];

/**/ /**/ /**/ /**/ }

/**/ /**/ /**/ /**/ vector<vector<int作者：lstallone
链接：https://www.nowcoder.com/discuss/93253?type=0&order=0&pos=14&page=1
来源：牛客网

#include <iostream>

?#include <vector>

?#include <utility>

?#include <algorithm>

?using namespace std;

?

?bool cmp(pair<int, int>& p1, pair<int, int>& p2)

?{

?return (p1.second<p2.second )||(p1.second==p2.second && p1.first>p2.first);

?}

?

?int main()

?{

?int N, M;

?cin>>N>>M;

?vector<pair<int, int> > time(N);

?for(int i=0; i<N; ++i)

?{

?int s, t; cin>>s>>t;

?if(s>=t)t+=M;

?time[i] = make_pair(s,t);

?}

?sort(time.begin(), time.end(), cmp);

?int finalRes=0;

?for(int j=0; j<N;++j) //j代表从第j个开始看

?{

?int res =0;

?int cur0 = time[j].first;

?int cur =cur0;

?for(int i=0; i<N; ++i)

?{

?

?if(i+j<N&& time[i].first >= cur)

?{

?cur = time[i].second;

?if(cur<cur0+M)

?++res;

?else break;

?}

?if(i+j>=N && time[i].first+M >= cur)

?{

?cur = time[i].second+M;

?if(cur<cur0+M)

?++res;

?else break;

?}

?}

?if(res>finalRes)

?finalRes = res;

?}

?cout<<finalRes<<endl;

?return 0;

?}>> dp(x_sum+1,vector<int>(x_sum+1,INF));

/**/ /**/ /**/ /**/ dp[0][0] = 0;

/**/ /**/ /**/ /**/ for(int i=0;i<n;i++){/**/ //考虑每个物品

/**/ /**/ /**/ /**/ /**/ /**/ for(int j=x_sum;j>=0;j--){

/**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ for(int k=x_sum;k>=0;k--){

/**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ int t=-1;

/**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ if(j-x[i]>=0 && dp[j-x[i]][k]!=INF)

/**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ t = max(t,dp[j-x[i]][k]);

/**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ if(k-x[i]>=0 && dp[j][k-x[i]]!=INF)

/**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ t = max(t,dp[j][k-x[i]]);

/**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ if(t!=-1)

/**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ t += y[i];

/**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ if(t!=-1){

/**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ if(dp[j][k] == INF)

/**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ dp[j][k] = t;

/**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ else

/**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ dp[j][k] = max(dp[j][k],t);

/**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ }

///**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ dp[j][k] = max(max(dp[j-x[i]][k],dp[j][k-x[i]])+y[i],dp[j][k]);

/**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ }

/**/ /**/ /**/ /**/ /**/ /**/ }

/**/ /**/ /**/ /**/ }

/**/ /**/ /**/ /**/ for(int i=0;i<=x_sum;i++)

/**/ /**/ /**/ /**/ /**/ /**/ if(dp[i][i]!=INF)

/**/ /**/ /**/ /**/ /**/ /**/ /**/ /**/ max_score = max(max_score,dp[i][i]);

/**/ /**/ /**/ /**/ printf("%d\n",max_score);

/**/ /**/ }

/**/ /**/ return 0;

}


