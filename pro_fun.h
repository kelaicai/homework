#include<stdio.h>
#include<malloc.h>
#include<string.h>
#ifndef _PRO_FUN_H
#def _PRO_FUN_H
int pro_num=0; //记录进程个数
process *pro;//进程链表头结点 

void init();
void create();
void fcfs();
void show();
void fcfs_sort();
void sjb();
void sjb_sort();
