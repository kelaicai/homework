#include<stdio.h>
#include<stdlib.h>
int arr[10]={1,2,3,4,5,6,7};
int front=0;
int rear=0;

int full()
{
	if((rear+1)%rear==front)
	{
		return 	1;
	} 
	return 0;
}

void insert(int val)
{   
	if(full())
	{
		return ;
	}
	arr[rear]=val;
	rear=(rear+1)%10;
}


int empty()
{
	if(rear==front)
	{
		return 1;
	}
	return 0;
}

int get()
{
	if(empty())
	{
		return -1;
	}
	int tmp=arr[front];
	front=(front+1)%10;
	return tmp;
}


void display()
{
	int i=0;
	
	for(i=0;i<10;i++)
	{
		printf("%d  ",arr[i]);
	}	
} 

int main()
{
	insert(11);
	insert(22);
	display();
}
