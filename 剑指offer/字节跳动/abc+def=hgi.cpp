
#include "iostream"
using namespace std;
bool outHand[10] = { false };
int list[10] = { 0 };
int total = 0;
void DFS(int step)
{
	if (step == 10)   //��������1����9����ȫ���ȥ��
	{
		if (list[1] * 100 + list[2] * 10 + list[3]     //��������2�������ʽ
			+ list[4] * 100 + list[5] * 10 + list[6]
			== list[7]*100 + list[8]*10 + list[9])
		{
			total++;
		}
		return;
 
	}
	for (int i = 1;i <= 9;i++)  //����ÿһ�ֿ���
	{
		if (outHand[i] == false)
		{
			list[step] = i;    //����������ŵ�������
			outHand[i] = true;  //���
			DFS(step + 1);  //��ʼ����һ����
			outHand[i] = false;//���ó���
		}
	}
	return;
}
int  main()
{
	DFS(1);
	cout << total / 2;
}
