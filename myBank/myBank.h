#include<stdio.h>
typedef enum booL{
	F,
	T
}booL;
typedef struct Process  //�������ص���ؾ��󣬱����Ϣ
{
	int max[MAX][MAX]={0};
    int allocation[MAX][MAX]={0};
    int need[MAX][MAX]={0};
    int work[MAX]={0};
    booL finish[MAX];
};
void input();
void show();
int init();
booL check_safe();
void alloc();

