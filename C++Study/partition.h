#ifndef _PARTITION_H
#define _PARTITION_H
#define MaxNum 100

typedef struct Partition //空闲分区
{
	int FreePartition;     //空闲分区大小
	int Freesize;          //剩余空闲内存大小
	int pcname[10];
	int pcnum;
	int state;
	int address;
	int num;
}PT;

typedef struct Process //作业
{
	int name;
	int size;
}PC;
#endif
