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
������������ �������� ��������: ���� ���������� �� ���� ����� ��
�������; ���� ������������� �� ���� �� ������� �������� ��� ����� ��������.
*/

int main()
{
	PartyQueue * a;
	a = new PartyQueue[30];

	for (int i = 0; i < 30; i++)
	{
		a[i] = PartyQueue(string("Li Chhoo An'"), string("+1 202 - 456 - 1111"), Date( i+1, i / 4 +1, 2000+i * 5));
	}
	QueueHousing b(a, 30);
	cout << b.longQueue() << endl;
	system("pause");

    return 0;
}
