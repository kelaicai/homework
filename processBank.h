#define MAX 10

int re_n; //��Դ�� 
int pro_m;  //���̸���
typedef struct request{
	char name[10];
	int num[MAX]; 
}request;
request rqe; //������Դ������
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
 
int avaible[MAX];  //ĳһʱ�̵Ŀ�����Դ��� 
int avaibletmp[MAX];

int work[MAX];  //work���� 
int worktmp[MAX];
int safe[MAX];  //��ȫ���� 
int input(); //���� 
void fun();
int check(); //��ȫ���㷨 
void show() ; //��ʾ���� 
void tryalloc(int );
booL bank();
void recive(int ); 
void recovery();
