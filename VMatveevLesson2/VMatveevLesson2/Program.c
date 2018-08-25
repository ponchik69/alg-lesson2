/*
* Выполнил: Владимир Матвеев
*
* Задача:
* Есть M человек, нужно показать всевозможные разбиения на N команд.
*
* Решение задачи сводится к разбиению числа M на N слогаемых.
*
* Допущения принятые при решении:
* 1) Кол-во людей и кол-во команд задаются в коде программы. (предложить пользователю ввести эти значения не сложно, на алгоритм это не влияет)
* 2) 1+2 и 2+1 - это разные варианты, т.к. в превом случае Team1 - 1 человек, Team2 - 2 человек, а во втором Team1 - 2 человек, Team2 - 1 человек (в строке 72 это можно исправить
*                                                           и тогда, программа исключает повторяющиеся варианты и выводит просто возможноые деления людей, без привязки к командам).
* 3) Допускаются команды с нулевым кол-вом игроков (в строках 67-68 это можно исправить)
*
* Алгоритм решения был выбран следующий: Мы перебираем композиции числа, заносим эти данные в массив размерности PLAYERS, недостающие слогаемые забиваем нулями 3=(1+1+1)=(1+2+0)=(2+1+0)=(3+0+0),
* затем мы сверяем кол-во ненулевых элементов массива с числол команд (COMANDS), в случае когда допускаются нулевые значения в командах, значения ненулевых элементов массива меньше либо равно кол-ву команд,
* если нулевое кол-во игроков в командах не допускается, то значения ненулевых элементов массива должно быть равно кол-ву команд.
*
*/
#include <math.h>
#include <locale.h>
#include <conio.h>
#include <stdio.h>

#define PLAYERS 5 // Кол-во людей для распределения по командам
#define COMANDS 3 // Кол-во команд

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
		printf("Некорректные значения");

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

		PrintResultWithZero(); // Вывод вариантов, где 0 человек в команде допускается
//		PrintResultWithoutZero(); // Вывод вариантов, где 0 человек в команде не допускается
	}
	else
	{
		for (i = 1; i <= number; i++) // Если заменть на (i = 1; i <= Min(max, number); i++) то исключатся повторяющиеся вырианты 
									  // (варианты, где слагаемые меняются местами), например при разложении 3 будет 3=(1+1+1)=(1+2)=(3) вместо 3=(1+1+1)=(1+2)=(2+1)=(3)
		{
			x[pos] = i;
			Partitions(pos + 1, i, number - i);
		}
	}
}

// Вывод вариантов, где 0 человек в команде не допускается
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

// Вывод вариантов, где 0 человек в команде допускается
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

// Вывод повторяющихся вариантов 2=(2+0)=(0+2)
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
