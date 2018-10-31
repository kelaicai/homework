#include<iostream>
#include<string.h>
#include<stdlib.h>
#include "partiton.h"
using namespace std;

int m;
int n;
PT pt[MaxNum];

PC pc[MaxNum];
int load(int sign)   //��������
{
	int i;
	cout << "��������з�������: " << endl;
	cin >> m;
	cout << "��������з����׵�ַ��" << endl;
	cin >> pt[0].address;
	cout << "������������з�����С(KB): " << endl;

	for (i = 0; i<m; i++)
	{
		cin >> pt[i].FreePartition;
		pt[i].Freesize = pt[i].FreePartition;
		pt[i].pcnum = 0;
		pt[i].state = 0;
		pt[i].num = i;
	}

	if (sign == 3)
	{
		for (int x = 0; x<m - 1; x++)
		{
			for (int y = x + 1; y<m; y++)
			{
				if (pt[x].address > pt[y].address)
				{
					PT tmp;
					tmp = pt[x];
					pt[x] = pt[y];
					pt[y] = tmp;
				}
			}
		}
	}
	if (sign == 4)
	{
		for (int x = 0; x<m - 1; x++)
		{
			for (int y = x + 1; y<m; y++)
			{
				if (pt[x].address < pt[y].address)
				{
					PT tmp;
					tmp = pt[x];
					pt[x] = pt[y];
					pt[y] = tmp;
				}
			}
		}
	}
	cout << "��������ҵ����:" << endl;
	cin >> n;
	cout << "������������ҵ����: " << endl;
	for (i = 0; i<n; i++)
	{
		cin >> pc[i].name;
	}
	cout << "������������ҵ��С(KB)" << endl;
	for (i = 0; i<n; i++)
	{
		cin >> pc[i].size;
	}
	cout << "��ҵ��Ϣ���£�" << endl;
	cout << "name   size" << endl;
	for (i = 0; i<n; i++)
	{
		cout << pc[i].name << "        ";
		cout << pc[i].size << endl;
	}

	return 0;
}

int First() //�״���Ӧ�㷨
{
	int i;
	int j;
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<m; j++)
		{
			//�ҵ���һ�����ʵĿ��з���
			if (pc[i].size <= pt[j].Freesize)
			{
				pt[j].Freesize -= pc[i].size;
				pt[j].pcname[pt[j].pcnum] = pc[i].name;
				pt[j].pcnum++;
				pt[j].state = 1;
				break;
			}
		}
		if (j >= m)
		{
			cout << pc[i].name << pc[i].size << "   �޿ɷŷ���" << endl;
		}
	}
	return 0;
}

int CycleFirst()   //ѭ���״���Ӧ�㷨
{
	int i;
	int j;
	int sign = 0;
	for (i = 0; i<n; i++)
	{
		for (j = sign; j<m; j++)
		{
			//�ҵ���һ�����ʵĿ��з���
			if (pc[i].size <= pt[j].Freesize)
			{
				pt[j].Freesize -= pc[i].size;
				pt[j].pcname[pt[j].pcnum] = pc[i].name;
				pt[j].pcnum++;
				pt[j].state = 1;
				sign = j + 1;
				break;
			}
		}
		if (j >= m)
		{
			int k = 0;
			for (; k<sign; k++)
			{
				if (pc[i].size <= pt[k].Freesize)
				{
					pt[k].Freesize -= pc[i].size;
					pt[k].pcname[pt[k].pcnum] = pc[i].name;
					pt[k].pcnum++;
					pt[k].state = 1;
					sign = k + 1;
					break;
				}
			}
			if (k >= sign)
			{
				cout << pc[i].name << "    " << pc[i].size << "   �޿ɷŷ���" << endl;
			}

		}


	}
	return 0;
}

int Best()    //�����Ӧ�㷨
{
	int i;
	int j;

	for (i = 0; i<n; i++)
	{

		for (j = 0; j<m; j++)
		{
			//�ҵ���һ�����ʵĿ��з���
			if (pc[i].size <= pt[j].Freesize)
			{
				pt[j].Freesize -= pc[i].size;
				pt[j].pcname[pt[j].pcnum] = pc[i].name;
				pt[j].pcnum++;
				pt[j].state = 1;
				break;
			}
		}
		if (j >= m)
		{
			cout << pc[i].name << pc[i].size << "   �޿ɷŷ���" << endl;
		}
	}
	return 0;
}


int Worst()   //���Ӧ�㷨
{
	int i;
	int j;

	for (i = 0; i<n; i++)
	{
		int sign = 0;
		int tmp = 0;
		int x = -1;
		for (j = 0; j<m; j++)
		{
			//�ҵ���һ�����ʵĿ��з���
			if (pc[i].size <= pt[j].Freesize)
			{
				if (sign == 0)
				{
					sign = 1;
					tmp = pt[j].Freesize;
					x = j;
				}
				else if (tmp<pt[j].Freesize)
				{
					tmp = pt[j].Freesize;
					x = j;
				}
			}
		}
		if (x == -1)
		{
			cout << pc[i].name << pc[i].size << "   �޿ɷŷ���" << endl;
		}
		else
		{
			pt[x].Freesize -= pc[i].size;
			pt[x].pcname[pt[x].pcnum] = pc[i].name;
			pt[x].pcnum++;
			pt[x].state = 1;
		}
	}
	return 0;
}
void show()     //������
{
	int i;
	for (i = 0; i<m; i++)
	{
		if (pt[i].state == 1)
		{
			int j = 0;
			cout << "�����ţ�" << pt[i].num << " " << "�������ҵ���:";
			for (; j<pt[i].pcnum; j++)
			{
				cout << pt[i].pcname[j] << " ";
			}
			cout << endl;
		}
	}
}
int main()
{
	//load(0);
	//First();
	//show();

	//load(0);
	//CycleFirst();
	//show();

	load(3);
	Best();
	show();
	//load(4);
	//Worst();
	//show();
}

