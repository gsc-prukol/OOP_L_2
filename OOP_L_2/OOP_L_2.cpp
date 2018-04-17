// OOP_L_2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include "Sourse.cpp"

using namespace std;
/*
������ 7
������� ����� �� ��������� �����. ���� "������� �����" -- �������,
�������, ���� ���������� � �����. ��������������� ����� "�������� �����"
����������� � ������������ ��������� priority queue. ���������� �������:
- ���������� ������� �����;
- ��������� ������ �������� � ����� ( ������������� �� ���� ������
��������);
- ��������� ��������, �� �������� ����� ( �� ����).
������������ ������� ��������: ���� ���������� �� ���� ����� ��
�������; ���� ������������� �� ���� �� ������� ������� ��� ����� ��������.
*/

int main()
{
	PartyQueue * a;
	Date * b;
	a = new PartyQueue[30];
	b = new Date[30];
	for (int i = 0; i < 30; i++)
	{
		a[i] = PartyQueue(string("Windows"), string("+1 202 - 456 - 1111"), Date( i+1, i/ 5 + 6 , 2000+i));
		b[i] = Date(i + 1, i / 5 + 6, 2000 + i);
	}
	QueueHousing c(a, b, 30);
	cout << c.longQueue() << endl;
//	c.push(c.top());
	while (c.longQueue())
	{
		cout << c.top() << ";;;";
		cout << c.longQueue() << endl;
		c.pop();
	}
	system("pause");

    return 0;
}
