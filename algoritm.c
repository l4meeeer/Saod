#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 6

int main()
{
	int a[size][size]; //матрица связей
	int d[size]; //минимальное расстояние
	int v[size]; //посещенные вершины
	int temp, minindex, min;
	int i,j;
	srand ( time(NULL) );
	//инициализация матрицы связей
	for (i = 0; i < size; i++)
		{
			a[i][i] = 0;
			for (j = i + 1; j < size; j++)
			{
				a[i][j] = rand() % 50 + 1;
				a[j][i] = rand() % 50 + 1;								
			} 
		}
		//вывод матрицы связей
		for (i = 0; i < size; i++){
			for (j = 0; j < size; j++)
				printf("%5d", a[i][j]);
			printf("\n");
		}
		//инициализация вершин и расстояний
		for (i = 0; i < size; i++){
			d[i] = 1000;
			v[i] = 1;
		}
		d[0] = 0;
		//шаг алгоритма
		do {
			minindex = 1000;
			min = 1000;
			for (i = 0; i < size; i++)
			{ // Если вершину еще не обошли и вес меньше min
				if ((v[i] == 1) && (d[i] < min))
				{
					// переписываем значения
					min = d[i];
					minindex = i;
				}
			}
			// Добавляем найденный минимальный вес к текущему весу
			// вершины и сравниваем с текущим
			// минимальным весом вершины
			if (minindex != 1000)
			{
				for (i = 0; i < size; i++)
				{
					if (a[minindex][i] > 0)
					{
						temp = min + a[minindex][i];
						if (temp < d[i])
							d[i] = temp;
					}
				}

				v[minindex] = 0;
			}

		} while (minindex < 1000);
		// вывод матрицы связей
		printf("\n");
		for (i = 0; i < size; i++)
		{
			printf("%5d \n", d[i]);
		}
		return 0;
}