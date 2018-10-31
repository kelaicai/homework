
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <climits>
#include <cassert>
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define LL long long
#define lson lo, mi, rt << 1
#define rson mi + 1, hi, rt << 1 | 1

using namespace std;
const int maxn = 100000 + 10;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
const double pi = acos(-1.0);
const double ee = exp(1.0);

int n, q;
int num1[maxn];
int num2[maxn];
int cnt;
int cnt1;

int minPoint[maxn][20];
int maxPoint[maxn][20];

int minPoint2[maxn][20];
int maxPoint2[maxn][20];

void queryInit1()
{
 ////////////////////////////
 for (int i = 1; i <= n; i++)
 {
 minPoint[i][0] = maxPoint[i][0] = num1[i];
 }
 ////////////////////////////
 for (int j = 1; (1 << j) <= n; j++)
 {
 for (int i = 1; i + (1 << j) - 1 <= n; i++)
 {
 int p = (1 << (j - 1));
 minPoint[i][j] = Min(minPoint[i][j - 1], minPoint[i + p][j - 1]);
 maxPoint[i][j] = Max(maxPoint[i][j - 1], maxPoint[i + p][j - 1]);
 }
 }
}
int queryMax(int l, int r)
{

 int k = log2((double)(r - l + 1));
 return Max(maxPoint[l][k], maxPoint[r - (1 << k) + 1][k]);
}

int queryMin(int l, int r)
{

 int k = log2((double)(r - l + 1));
 return Min(minPoint2[l][k], minPoint2[r - (1 << k) + 1][k]);
}

void queryInit2()
{
 ////////////////////////////
 for (int i = 1; i <= n; i++)
 {
 minPoint2[i][0] = maxPoint2[i][0] = num2[i];
 }
 ////////////////////////////
 for (int j = 1; (1 << j) <= n; j++)
 {
 for (int i = 1; i + (1 << j) - 1 <= n; i++)
 {
 int p = (1 << (j - 1));
 minPoint2[i][j] = Min(minPoint2[i][j - 1], minPoint2[i + p][j - 1]);
 maxPoint2[i][j] = Max(maxPoint2[i][j - 1], maxPoint2[i + p][j - 1]);

 }
 }
}

int main()
{
 while (~scanf("%d", &n) && n)
 {
 cnt = 0;
 cnt1 = 0;

 for (int i = 1; i <= n; i++)
 {
 scanf("%d", &num1[i]);

 }
 queryInit1();
 for (int i = 1; i <= n; i++) {
 scanf("%d", &num2[i]);
 }
 queryInit2();

 /*
??? ? ? for (int i = 1; i <= n; i++) {
??? ? ? ? ? for (int j = 1; j <= i; j++) {
??? ? ? ? ? ? ? int x = queryMax(j, i);
??? ? ? ? ? ? ? int y = queryMin(j, i);
?
??? ? ? ? ? ? ? if (x < y) {
??? ? ? ? ? ? ? ? ? //printf("%d %d -- %d %d\n", j, i, x, y);
??? ? ? ? ? ? ? ? ? cnt1 ++;
??? ? ? ? ? ? ? }
??? ? ? ? ? }
??? ? ? }*/
 for (int i = 1; i <= n; i++) {
 int l = 1, r = n - i + 1;
 int mid;
 while (l<=r) {
 mid = l + (r - l) / 2;

 int x = queryMax(i, i+mid-1);
 int y = queryMin(i, i+mid-1);
 //printf("%d&&&%d***%d***%d\n", i, i+mid-1,x, y);

 if (x < y) {
 l = mid+1;
 } else {
		 r = mid-1;
				 }

	 }
 //printf("%d %d -- %d %d\n", i, mid, l, r);
 cnt += l-1;
	 }

 //cout << cnt1 << endl;
	printf("%d\n", cnt);

 }
 return 0;
}


