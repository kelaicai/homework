#ifndef _PARTITION_H
#define _PARTITION_H
#define MaxNum 100

typedef struct Partition //���з���
{
	int FreePartition;     //���з�����С
	int Freesize;          //ʣ������ڴ��С
	int pcname[10];
	int pcnum;
	int state;
	int address;
	int num;
}PT;

typedef struct Process //��ҵ
{
	int name;
	int size;
}PC;
#endif
