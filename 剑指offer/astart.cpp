#include<stdio.h>
#include<stdlib.h>

#define  STARTNODE 1
#define ENDNODE 2
#define BARRIER 3

typedef struct AStartNode{
	int s_x;  //����
	int s_y;
	int s_g; //��㵽�˵�ľ��룬
	int s_h;  //����ʽ����Ԥ��Ĵ˵굽�յ�ľ���
	int s_style;//�ڵ�����:��㣬�յ㣬�ϰ�
	struct AStartNode* s_parent;  //���ڵ�
	int s_is_in_closetable;
	int s_is_in_opentable;
}AStartNode,*pAStarNode;


AStartNode map_maze[10][10];  //�ڵ�����
pAStarNode open_table[100]; //open ��
pAStarNode close_table[100];

int open_node_count;//open���еĽڵ�
int close_node_cout;//close���еĽڵ�

pAStarNode path_stack[100];  //����·����ջ
int top=-1;//ջ��

//������Ԫ��
void swap(int idx1,int idx2){
  pAStarNode tmp=open_table[idx1];
  open_table[idx1]=open_table[idx2];
  open_table[idx2]=tmp;
}

//�ѵ���
void adjust_heap(int nIndex){
	int curr=nIndex;
	int child=curr*2+1;  //�õ����е�����(�������ӵ��±궼��curr*2+1,�±���㿪ʼ)
    int parrent=(curr-1)/2;  //�õ�˫��idx

    if(nIndex<0 || nIndex>=open_node_count){
    	return ;
    }
    //���µ������Ƚ����Һ��Ӻ�curr parrent��
    while(child<open_node_count){
    	//С������˫��С�ں��ӵ�ֵ
    	if(child+1<open_node_count && open_table[child]->s_g+open_table[child]->s_h >open_table[child+1]->s_g+open_table[child+1]->s_h)
    	{
    		++child;//�ж����Һ��Ӵ�С
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
    //���ϵ���(ֻ��Ҫ�Ƚ�curr child ��parrent)
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

//�ж��ھӵ��Ƿ���Խ���Open��
void insert_to_opentable(int x,int y,pAStarNode curr_node,pAStarNode end_node,int w){
	int i;
	if(map_maze[x][y].s_style!=BARRIER){
		if (!map_maze[x][y].s_is_in_closetable)
			if (map_maze[x][y].s_is_in_opentable)
			{
				//��Ҫ�ж��Ƿ���һ�����Ż���·��
				if(map_maze[x][y].s_g>curr_node->s_g+w) //������Ż�
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
//�����ھ�
//����������8���ھӽ��в���
void get_neighbors(pAStarNode curr_node,pAStarNode end_node){
	int x=curr_node->s_x;
	int y=curr_node->s_y;

	//�������8���ھӽ��д���
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

	if((x+1)>=0 && (x+1)<10 && (y+1)>=0 && (y+1)<10){  //���½�
		insert_to_opentable(x+1,y+1,curr_node,end_node,10);
	} 
	if ((x+1)>=0 && (x+1)<10 && (y-1)>=0 && (y-1)<10)  //���Ͻ�
	{
		insert_to_opentable(x+1,y-1,curr_node,end_node,10);
	}
	if ((x-1)>=0 && (x-1)<10 && (y-1)>=0 && (y-1)<10)  //���Ͻ�
	{
		insert_to_opentable(x-1,y-1,curr_node,end_node,10);
	}
	if ((x-1)>=0 && (x-1)<10 && (y+1)>=0 && (y+1)<10)  //���½�
	{
		insert_to_opentable(x-1,y+1,curr_node,end_node,10);
	}
}

int main(){

	//��ͼ���鶨��
	AStartNode  *start_node;  //��ʼ��
	AStartNode  *end_node;  //������
	AStartNode  *curr_node;  //��ǰ��
	int is_found;  //�Ƿ��ҵ�·��

	int maze[][10] ={			// ����Ϊ�˺ø�ֵ��map_maze
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
		//����׼����
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

	//A* �㷨�õ����·��
		open_table[open_node_count++]=start_node;  //��ʼ�����open

		start_node->s_is_in_opentable=1;
		start_node->s_g=0;
		start_node->s_h=abs(end_node->s_x-start_node->s_x)+abs(end_node->s_y-start_node->s_y);
		start_node->s_parent=NULL;

		if(start_node->s_x==end_node->s_x && end_node->s_y==start_node->s_y){
			printf("���==�յ�\n");
			return 0;
		}
		is_found=0;

		while(1){
			curr_node=open_table[0];  //open��ĵ�һ����һ����fֵ��С�ĵ㣨������õ���
			open_table[0]=open_table[--open_node_count];  //���һ����ŵ���һ���㣬Ȼ����жѵ���
			adjust_heap(0);
			close_table[close_node_cout++]=curr_node; //��ǰ�����close�� 
			curr_node->s_is_in_closetable=1;  //����close������

			if(curr_node->s_x==end_node->s_x && curr_node->s_y==end_node->s_y)  //�յ���close������,����
				{
					is_found=1;
			     break;
				}

				//�Ը����ڵ㴦��
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
				printf("(%d��%d)",path_stack[top]->s_x,path_stack[top]->s_y);
			}
		}
	}else{
		printf("û���ҵ�·��");
	}
	puts(" ");
	return 0;

		

}

