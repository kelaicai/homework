#define MAX 10

int re_n; //资源数 
int pro_m;  //进程个数
typedef struct request{
	char name[10];
	int num[MAX]; 
}request;
request rqe; //请求资源的命令
typedef enum booL{
	F,
	T
}booL;
typedef struct process{
	char nam[MAX];
	int max[MAX];
	int  alloction[MAX];
	int need[MAX];
	booL finish; 
	booL recived;
}process;

process p[MAX];
process protmp[MAX];
 
int avaible[MAX];  //某一时刻的可用资源情况 
int avaibletmp[MAX];

int work[MAX];  //work向量 
int worktmp[MAX];
int safe[MAX];  //安全序列 
int input(); //输入 
void fun();
int check(); //安全性算法 
void show() ; //显示函数 
void tryalloc(int );
booL bank();
void recive(int ); 
void recovery();
