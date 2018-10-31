#ifndef LINK_H
#define LINK_H

struct Node
{
	int value;
	Node *pnext;
};

//ʵ�ִ���ͷ���ĵ�����
class Link
{
public:
	//����ͷ���
	Link();
	//�ͷ�����
	~Link();
	//ͷ�巨
	void insertHead(int val);
	//β�巨
	void insertTail(int val);
	//ɾ��Ԫ��
	void deleteNode(int val);
	//��ӡ�����
	void show();
	//�ж������Ƿ�Ϊ�� 
	bool empty();

private:
	Node *phead;
};


#endif
