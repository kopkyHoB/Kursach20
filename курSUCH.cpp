#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <locale.h>
#include <time.h>

using namespace std;
int i, j, m, n, v;
int** graph;

int main()
{
	setlocale(LC_ALL, "Rus");
	printf("Размерность:  ");
	scanf_s("%d", &m);
	n = m;
	graph = new int* [m];
	for (int i = 0; i < m; i++) {
		graph[i] = new int[m];
	}
	//генерация матрицы
	int t;
	printf("1 - Автоматическая генерация\n2 - Ручной ввод\n> ");
	scanf_s("%d", &t);
	if (t == 1) {
		srand(time(NULL));
		for (i = 0; i < m; ++i) {
			for (j = i; j < m; ++j) {
				graph[i][j] = graph[j][i] = rand() % 2;
			}
			graph[i][i] = 0; //обнуление вершины
		}
	}
	else {
		printf("Вводите элементы матрицы (0 и 1):\n");
		for (i = 0; i < m; ++i) {
			for (j = i; j < m; ++j) {
				if (i != j) {
				ret:
					printf("a[%d][%d] = ", i, j);
					scanf_s("%d", &graph[i][j]);
					if (graph[i][j] > 1 || graph[i][j] < 0) {
						printf("\nНекорректный ввод!\n");
						goto ret;
					}
				}
			}
			graph[i][i] = 0;
		}
	}
	for (i = 0; i < n; i++) //отзеркаливание матрицы
		{
		for (j = 0; j < n; j++)
			{
				graph[j][i] = graph[i][j];
			}
		}


	printf("Матрица смежности: \n");
	//нумерование столбцов
	printf("\n     ");
	for (int i = 0; i < n; i++) {
		printf("[%d] ", i + 1);
	}

	printf("\n");

	//нумерование строк
	for (i = 0; i < m; ++i)
	{
		printf("[%d] ", i + 1);
		for (j = 0; j < m; ++j) {
			if ((i + 1) < 10)
			{
				if (j < 10)
					printf("%3d ", graph[i][j]);
				else
					printf(" %3d ", graph[i][j]);

			}

			else if ((i + 1) < 100)
			{
				if (j == 0)
					printf(" %d", graph[i][j]);
				else if (j < 10)
					printf("   %d", graph[i][j]);
				else
					printf("    %d", graph[i][j]);

			}

		}
		printf("\n");
}

	printf("\nМатрица инцидентности: \n");
	int reb = 0;
	int ch = 0;

	while (ch != n)
		for (int i = 0; i < n; i++)
		{
			for (int j = 0 + ch; j < n; j++)
				if (graph[i][j] != 0)
					reb++;
			ch++;
		}
	/////

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (graph[i][j] != 0)
				graph[j][i] = 0;

	int** inc;

	inc = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		inc[i] = (int*)malloc(reb * sizeof(int));
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < reb; j++)
			inc[i][j] = 0;

	int	ch1 = reb;
	reb = 0;
	for (int i = 0; i < n; i++)				//создание матрицы инцидентности
	{
		for (int j = 0; j < n; j++)
			if (graph[i][j] != 0)
			{
				inc[i][reb] = 1;				//начало
				inc[j][reb] = 1;				//конец
				reb++;
			}
	}

	printf("\n    ");
	for (int i = 0; i < ch1; i++) {
		printf("[%d] ", i + 1);
	}
	for (int i = 0; i < n; i++)
	{
		printf("\n[%d]", i + 1);

		for (int j = 0; j < reb; j++)
		{
			if ((i + 1) < 10)
			{
				if (j < 10)
					printf("%3d ", inc[i][j]);
				else
					printf(" %3d ", inc[i][j]);

			}

			else if ((i + 1) < 100)
			{
				if (j == 0)
					printf(" %d", inc[i][j]);
				else if (j < 10)
					printf("   %d", inc[i][j]);
				else
					printf("    %d", inc[i][j]);

			}

		}
	}
	printf("\n");
	printf("Независимые рёбра:\n");
	for (int i = 0; i < reb; i++) {
		bool sr = false;
		for (int j = i + 1; j < reb; j++) {
			sr = false;
			for (int k = 0; k < n; k++) {
				if (inc[k][i] == 1 && inc[k][j] == 1) {
					sr = true;
				}
			}
			if (sr == false) { printf("%d - %d\n", i + 1, j + 1); }
		}
	}
	return 0;
}