#ifndef QUEUE_H
#define QUEUE_H

//—≠ª∑∂”¡–
class CircleQue
{
public:
	CircleQue(int size = 10);
	~CircleQue();
	CircleQue(const CircleQue &src);
	void operator=(const CircleQue &src);

	void addQue(int val);
	void delQue();
	int front();
	int rear();

	bool empty();
	bool full();
private:
	int *mpQue;
	int msize;
	int mfront;
	int mrear;
};


#endif