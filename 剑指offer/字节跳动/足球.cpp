#include<iostream> 
#include<vector> 
using namespace std;

void bfs(vector<vector<int> >& grid, int i, int j, int& num)
{

 if(i<0||i>grid.size()-1||j<0||j>grid[0].size()-1||grid[i][j]==0)

 return ;

 grid[i][j]=0;

 ++num;

 bfs(grid, i-1,j, num);

 bfs(grid, i+1,j, num);

 bfs(grid, i,j-1, num);

 bfs(grid, i,j+1, num);

 bfs(grid, i-1,j-1, num);

	bfs(grid, i-1,j+1, num);

 bfs(grid, i+1,j-1, num);

 bfs(grid, i+1,j+1, num);

 return ;

}


int main()

{

 int M,N;

 cin>>M;

 cin.get();

 cin>>N;

 vector<vector<int> > grid(M,vector<int>(N,0));

 for(int i=0; i<M; ++i)

 {

 for(int j=0;j<N;++j)

 {

 cin>>grid[i][j];

 cin.get();

 }

 }



 int num=0, maxNum=0;

 for(int i=0; i!=M; ++i)

 {

 for(int j=0;j!=N; ++j)

 if(grid[i][j]==1)

 {

 int tmpMax=0;

 bfs(grid, i, j, tmpMax);

 ++num;

 if(tmpMax>maxNum)

 maxNum=tmpMax;

 }

 }

 cout<<num<<","<<maxNum<<endl;

 return 0;

}

