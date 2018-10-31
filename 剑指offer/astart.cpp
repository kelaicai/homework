#include<stdio.h>
#include<stdlib.h>

#define  STARTNODE 1
#define ENDNODE 2
#define BARRIER 3

typedef struct AStartNode{
	int s_x;  //坐标
	int s_y;
	int s_g; //起点到此点的距离，
	int s_h;  //启发式函数预测的此店到终点的距离
	int s_style;//节点类型:起点，终点，障碍
	struct AStartNode* s_parent;  //父节点
	int s_is_in_closetable;
	int s_is_in_opentable;
}AStartNode,*pAStarNode;


AStartNode map_maze[10][10];  //节点数组
pAStarNode open_table[100]; //open 表
pAStarNode close_table[100];

int open_node_count;//open表中的节点
int close_node_cout;//close表中的节点

pAStarNode path_stack[100];  //保存路径的栈
int top=-1;//栈顶

//交换两元素
void swap(int idx1,int idx2){
  pAStarNode tmp=open_table[idx1];
  open_table[idx1]=open_table[idx2];
  open_table[idx2]=tmp;
}

//堆调整
void adjust_heap(int nIndex){
	int curr=nIndex;
	int child=curr*2+1;  //得到所有的左孩子(所有左孩子的下标都是curr*2+1,下标从零开始)
    int parrent=(curr-1)/2;  //得到双亲idx

    if(nIndex<0 || nIndex>=open_node_count){
    	return ;
    }
    //往下调整（比较左右孩子和curr parrent）
    while(child<open_node_count){
    	//小根堆是双亲小于孩子的值
    	if(child+1<open_node_count && open_table[child]->s_g+open_table[child]->s_h >open_table[child+1]->s_g+open_table[child+1]->s_h)
    	{
    		++child;//判断左右孩子大小
    	}
    	if(open_table[curr]->s_g+open_table[curr]->s_h<=open_table[child]->s_g+open_table[child]->s_h){
    		break;
    	}else{
    		swap(child,curr);
    		curr=child;
    		child=curr*2+1;
    	}
    }
    if(curr!=nIndex){
      return;
    }
    //向上调整(只需要比较curr child 和parrent)
    while(curr!=0){
    	if(open_table[curr]->s_g+open_table[curr]->s_h>=open_table[parrent]->s_g+open_table[parrent]->s_h)
    	{
    		break;
    	}
    	else{
    		swap(curr,parrent);
    		curr=parrent;
    		parrent=(curr-1)/2;
    	}
    }
}

//判断邻居点是否可以进入Open表
void insert_to_opentable(int x,int y,pAStarNode curr_node,pAStarNode end_node,int w){
	int i;
	if(map_maze[x][y].s_style!=BARRIER){
		if (!map_maze[x][y].s_is_in_closetable)
			if (map_maze[x][y].s_is_in_opentable)
			{
				//需要判断是否有一条更优化的路径
				if(map_maze[x][y].s_g>curr_node->s_g+w) //如果更优化
					{
						map_maze[x][y].s_g=curr_node->s_g+w;
				        map_maze[x][y].s_parent=curr_node;

				        for(i=0;i<open_node_count;i++)
				        {
				        	if(open_table[i]->s_x==map_maze[x][y].s_x && open_table[i]->s_y==map_maze[x][y].s_y){
				        		break;
				        	}
				        }
                       adjust_heap(i);
			        }
			        else{
			        	map_maze[x][y].s_g=curr_node->s_g+w;
			        	map_maze[x][y].s_h=abs(end_node->s_x-x)+abs(end_node->s_y-y);
			        	map_maze[x][y].s_is_in_opentable=1;
			        	open_table[open_node_count++]=&(map_maze[x][y]);
			        }
			}
	}
}
//查找邻居
//对上下左右8个邻居进行查找
void get_neighbors(pAStarNode curr_node,pAStarNode end_node){
	int x=curr_node->s_x;
	int y=curr_node->s_y;

	//下面对于8个邻居进行处理
	if((x+1)>=0 && (x+1)<10 && y>=0 && y<10){
		insert_to_opentable(x+1,y,curr_node,end_node,10);
	}
	if((x-1)>=0 && (x-1)<10 && y>=0 && y<10){
		insert_to_opentable(x,y+1,curr_node,end_node,10);
	}
	if(x>=0 && x<10 && (y+1)>=0 && (y+1)<10)
	{
		insert_to_opentable(x,y+1,curr_node,end_node,10);
	}
	if(x>=0 && x<10 && (y-1)>=0 && (y-1)<10){
		insert_to_opentable(x,y-1,curr_node,end_node,10);
	}

	if((x+1)>=0 && (x+1)<10 && (y+1)>=0 && (y+1)<10){  //右下角
		insert_to_opentable(x+1,y+1,curr_node,end_node,10);
	} 
	if ((x+1)>=0 && (x+1)<10 && (y-1)>=0 && (y-1)<10)  //右上角
	{
		insert_to_opentable(x+1,y-1,curr_node,end_node,10);
	}
	if ((x-1)>=0 && (x-1)<10 && (y-1)>=0 && (y-1)<10)  //左上角
	{
		insert_to_opentable(x-1,y-1,curr_node,end_node,10);
	}
	if ((x-1)>=0 && (x-1)<10 && (y+1)>=0 && (y+1)<10)  //左下角
	{
		insert_to_opentable(x-1,y+1,curr_node,end_node,10);
	}
}

int main(){

	//地图数组定义
	AStartNode  *start_node;  //起始点
	AStartNode  *end_node;  //结束点
	AStartNode  *curr_node;  //当前点
	int is_found;  //是否找到路劲

	int maze[][10] ={			// 仅仅为了好赋值给map_maze
						{ 1,0,0,3,0,3,0,0,0,0 },
						{ 0,0,3,0,0,3,0,3,0,3 },
						{ 3,0,0,0,0,3,3,3,0,3 },
						{ 3,0,3,0,0,0,0,0,0,3 },
						{ 3,0,0,0,0,3,0,0,0,3 },
						{ 3,0,0,3,0,0,0,3,0,3 },
						{ 3,0,0,0,0,3,3,0,0,0 },
						{ 0,0,2,0,0,0,0,0,0,0 },
						{ 3,3,3,0,0,3,0,3,0,3 },
						{ 3,0,0,0,0,3,3,3,0,3 },
					};

		int i,j,x;
		//下面准备点
		for(i=0;i<10;i++){
			for(j=0;j<10;j++){
				map_maze[i][j].s_g=0;
				map_maze[i][j].s_h=0;
				map_maze[i][j].s_is_in_opentable=0;
				map_maze[i][j].s_is_in_closetable=0;
				map_maze[i][j].s_style=map_maze[i][j].s_style;
				map_maze[i][j].s_x=i;
				map_maze[i][j].s_y=j;
				map_maze[i][j].s_parent=NULL;
				if(map_maze[i][j].s_style==STARTNODE){
					start_node=&(map_maze[i][j]);
				}
				else if(map_maze[i][j].s_style==ENDNODE)
				{
					end_node=&(map_maze[i][j]);
				}
				printf("%d\n",map_maze[i][j] );
			}
			printf("\n");
		}

	//A* 算法得到最短路径
		open_table[open_node_count++]=start_node;  //起始点加入open

		start_node->s_is_in_opentable=1;
		start_node->s_g=0;
		start_node->s_h=abs(end_node->s_x-start_node->s_x)+abs(end_node->s_y-start_node->s_y);
		start_node->s_parent=NULL;

		if(start_node->s_x==end_node->s_x && end_node->s_y==start_node->s_y){
			printf("起点==终点\n");
			return 0;
		}
		is_found=0;

		while(1){
			curr_node=open_table[0];  //open表的第一个点一定是f值最小的点（堆排序得到）
			open_table[0]=open_table[--open_node_count];  //最后一个点放到第一个点，然后进行堆调整
			adjust_heap(0);
			close_table[close_node_cout++]=curr_node; //当前点加入close表 
			curr_node->s_is_in_closetable=1;  //已在close表里面

			if(curr_node->s_x==end_node->s_x && curr_node->s_y==end_node->s_y)  //终点在close表里面,结束
				{
					is_found=1;
			     break;
				}

				//对附近节点处理
		get_neighbors(curr_node,end_node);

		if(open_node_count==0){
			is_found=0;
			break;
		}
	}
	if(is_found){
		curr_node=end_node;
		while(curr_node){
			path_stack[++top]=curr_node;
			curr_node=curr_node->s_parent;
		}
		while(top>=0){
			if(top>0){
				printf("(%d,%d)--->", path_stack[top]->s_x,path_stack[top]->s_y);
			}else{
				printf("(%d，%d)",path_stack[top]->s_x,path_stack[top]->s_y);
			}
		}
	}else{
		printf("没有找到路径");
	}
	puts(" ");
	return 0;

		

}

