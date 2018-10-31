#include<iostream>
#include<stdio.h>
using namespace std;
#define M 1005
#define N 1005
int Map[M][N];
struct node{
    int x;
    int y;
};
node no[M*N];
int dir[8][2]={-1,-1,-1,0,-1,1,0,1,0,-1,1,-1,1,0,1,1};

int  bfs(int x,int y){
    int l = 0;
    int r = 1;
    int sum = 0;
    node root;
    root.x= x;
    root.y =y;
    no[l] = root;
    while(l<r){
         node temp = no[l];
         Map[temp.x][temp.y] = 0;
         for(int x1=0;x1<8;x1++){
             node t;
             t.x = temp.x + dir[x1][0];
             t.y = temp.y + dir[x1][1];
             if(t.x <0 || t.x >=m || t.y <0 || t.y >=n || Map[t.x][t.y]==0)
                 continue;
             sum++;
             Map[t.x][t.y] = 0;
             no[r] = t;
             r++;
         }
        l++;
    }
}
int main(){
    char t;
    scanf("%d%c%d",&m,&t,&n);
    int u ;
    for(int x=0;x<m;x++){
        for(int y=0;y<n;y++){
            if(y!=n-1)
                scanf("%d%c",&Map[x][y],&t);
             else
                 scanf("%d",&Map[x][y]);
        }
    }
    int sum = 0;
    int Max = 0;
    for(int x=0;x<m;x++){
        for(int y=0;y<n;y++){
            if(Map[x][y]){
                int u = bfs(x,y);
                Max = max(Max,u);
                sum++;
            }
        }
    }

    cout<<sum<<","<<Max<<endl;
}
