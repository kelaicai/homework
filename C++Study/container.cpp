#include<iostream>
#include<vector> //����C++���������Ĵ���
#include<functional>  //����C++ stl��������Ĵ���greater,less,,��Ԫ��������
#include<algorithm>  //����C++ �ķ����㷨ʵ��  sort find
#include<ctime>
using namespace std;


/*
1�������showContainer����ģ�壬ͨ������������ӡ������Ԫ�ص�ֵ
*/

template<typename container>
void showContainer(container &con)
{
	container::iterator it = con.begin();

	for (; it != con.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

template<typename container>
void sort_t(container &con)
{
	container::iterator it = con.begin();
	
	for (; it != con.end(); ++it)
	{
		for (container::iterator it_i = con.begin(); it_i != con.end(); ++it_i)
		{
			if (*it_i < *(it_i + 1))
			{
				
			}
		}
	}
}


int main()
{
	vector<int> vec;
	srand(time(0));
	for (int i = 0; i < 20; i++)
	{
		vec.push_back(rand() % 100);
	}
	showContainer(vec);
	sort(vec.begin(), vec.end(),less<int>());
	showContainer(vec);
	sort(vec.begin(), vec.end(), greater<int>());
 
    showContainer(vec);
	vector<int>::iterator it = find(vec.begin(), vec.end(), 50);
	if (*it==50)
	{
		cout << "������" << endl;
		vec.erase(it);
	}
	else
	{
		cout << "��������" << endl;
	}

	showContainer(vec);
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		if (*it % 2 == 0)
		{
			vector::iterator it_t = it;
			it=vec.erase(it);
			--it_t;
		}
	}
	showContainer(vec);

	for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		if (*it % 2 == 1)
		{
			it=vec.insert(it-1,(*it)-1);
		}
	}
	showContainer(vec);

 /*������ʧЧ�� ����������insert����reaseɾ��Ԫ��ʱ����ʹ�ñ�����λ�ú�ɾ��λ�õĵ�����ʧЧ
 ��Ҫ����-->����Inert��erase���ص��Ǹ��º�� �����������ʹ��ԭ���������ձ��޸Ĺ��ĵ���������
 ����
 
 for(vector<int>::iterator it=vec.begin();it!=begin();++it)
 {
 	if(*it%2==0)
 	{
		it=vec.erase(it);
	 }
 } 
 */
	
/*
vector��������

�ײ����ݽṹ
�ڴ�������ʽ
��ɾ�Ĳ鷽ʽ

��ʼ�ڴ濪���ڴ����̫���� --��Ĭ����������СΪ�㣬һ��Ϊ1������Ϊ2��������2^n 
reserve  Ԥ�������� 
resize 


swap  
step1 �ж��Ը�ֵ
step2 �жϿռ��������Ƿ�һ�����ڴ����ʽ����ֻ������Ա���� 
step3  �ռ���������һ����Ч�ʷǳ��ͣ���ƶ���Ĺ��������

empty()  || size()==0


gcc���Ա���C++ g++����c�   ��ʲô��ͬ 
*/ 

	
	vec.reserve(100); //Ԥ��100��Ԫ�ؿռ� ---->���vector��ʼ��ʱ�򿪱��ڴ�Ч��̫�� 
	vec.size(); //--�� ����Ԫ�صĸ���   0
	
	vec.resize(100);  //-->�����100��Ԫ�أ�  
	vec.size();  //-->>100 
	
	vec.swap(vec1); 

	system("pause");
}
