/*
* ��������: �������� �������
*
* ������:
* ���� M �������, ����� �������� ������������ ��������� �� N ������.
*
* ������� ������ �������� � ��������� ����� M �� N ���������.
*
* ��������� �������� ��� �������:
* 1) ���-�� ����� � ���-�� ������ �������� � ���� ���������. (���������� ������������ ������ ��� �������� �� ������, �� �������� ��� �� ������)
* 2) 1+2 � 2+1 - ��� ������ ��������, �.�. � ������ ������ Team1 - 1 �������, Team2 - 2 �������, � �� ������ Team1 - 2 �������, Team2 - 1 ������� (� ������ 72 ��� ����� ���������
*                                                           � �����, ��������� ��������� ������������� �������� � ������� ������ ���������� ������� �����, ��� �������� � ��������).
* 3) ����������� ������� � ������� ���-��� ������� (� ������� 67-68 ��� ����� ���������)
*
* �������� ������� ��� ������ ���������: �� ���������� ���������� �����, ������� ��� ������ � ������ ����������� PLAYERS, ����������� ��������� �������� ������ 3=(1+1+1)=(1+2+0)=(2+1+0)=(3+0+0),
* ����� �� ������� ���-�� ��������� ��������� ������� � ������ ������ (COMANDS), � ������ ����� ����������� ������� �������� � ��������, �������� ��������� ��������� ������� ������ ���� ����� ���-�� ������,
* ���� ������� ���-�� ������� � �������� �� �����������, �� �������� ��������� ��������� ������� ������ ���� ����� ���-�� ������.
*
*/
#include <math.h>
#include <locale.h>
#include <conio.h>
#include <stdio.h>

#define PLAYERS 5 // ���-�� ����� ��� ������������� �� ��������
#define COMANDS 3 // ���-�� ������

int n = PLAYERS;
int countComands = COMANDS;
int x[PLAYERS];

void Partitions(int pos, int max, int number);
void PrintResultWithZero();
void PrintResultWithoutZero();
void LastPrint();
int Min(int a, int b);

int main()
{
	setlocale(LC_ALL, "rus");

	if (countComands <= n)
	{
		for (int i = 0; i < countComands; i++)
			printf("Team%d  ", i + 1);

		Partitions(0, n, n);
	}
	else
		printf("������������ ��������");

	_getch();

	return 0;
}

void Partitions(int pos, int max, int number)
{
	int i;

	if (number == 0)
	{
		for (i = pos; i < n; i++)
			x[i] = 0;

		PrintResultWithZero(); // ����� ���������, ��� 0 ������� � ������� �����������
//		PrintResultWithoutZero(); // ����� ���������, ��� 0 ������� � ������� �� �����������
	}
	else
	{
		for (i = 1; i <= number; i++) // ���� ������� �� (i = 1; i <= Min(max, number); i++) �� ���������� ������������� �������� 
									  // (��������, ��� ��������� �������� �������), �������� ��� ���������� 3 ����� 3=(1+1+1)=(1+2)=(3) ������ 3=(1+1+1)=(1+2)=(2+1)=(3)
		{
			x[pos] = i;
			Partitions(pos + 1, i, number - i);
		}
	}
}

// ����� ���������, ��� 0 ������� � ������� �� �����������
void PrintResultWithoutZero()
{
	//	for (int i = 0; i < n; i++)
	//			printf(" %d", x[i]);
	//		printf("\n");
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (x[i] != 0)
		{
			count++;
		}
		else
			break;
	}

	if (count == countComands)
	{
		printf("\n");
		printf("|");
		for (int i = 0; i < countComands; i++)
			printf("  %d  |", x[i]);
	}
	count = 0;
}

// ����� ���������, ��� 0 ������� � ������� �����������
void PrintResultWithZero()
{
	//	for (int i = 0; i < n; i++)
	//			printf(" %d", x[i]);
	//		printf("\n");
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (x[i] != 0)
		{
			count++;
		}
		else
			break;
	}

	if (count <= countComands)
	{
		printf("\n");
		printf("|");
		for (int i = 0; i < countComands; i++)
			printf("  %d  |", x[i]);

	}
	if (x[0] == n)
	{
		LastPrint();
	}

	count = 0;
}

// ����� ������������� ��������� 2=(2+0)=(0+2)
void LastPrint()
{
	for (int i = 0; i < countComands; i++)
	{
		x[i] = 0;
	}

	for (int i = 1; i < countComands; i++)
	{
		x[i] = n;
		printf("\n");
		printf("|");
		for (int j = 0; j < countComands; j++)
		{
			printf("  %d  |", x[j]);
		}
		x[i] = 0;
	}
}

int Min(int a, int b)
{
	if (a > b)
		return b;
	else
		return a;
}
