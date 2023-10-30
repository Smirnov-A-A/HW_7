/* 4. Задан массив из 30 вещественных чисел. Найти элемент (индекс),
имеющий максимальное значение в массиве*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const int N = 5;
    const int M = 6;
    double ar[5][6];

    double *pAr = ar[0];
    double *pMax = ar[0];

    //Заполнение массива
    srand(time(NULL));
    for (int i = 0; i < N * M; ++i, ++pAr) {
        *pAr = ((double)rand() / RAND_MAX) * 100;
    }

    //вывод массива
    printf("Массив ar:\n");
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            printf("%3f  ", ar[i][j]);
        }
    printf("\n");
    }

    //Поиск максимального значения
    pAr = ar[0];
    for (int i = 0; i < N * M; ++i, ++pAr) {
        if (*pAr > *pMax) {
            pMax = pAr;
        }
    }

    printf("\nМаксимальное число в массиве: %f\n", *pMax);
    printf("Его индекс: ar[%ld][%ld]\n", ((pMax - ar[0]) / M), (pMax - ar[0]) % M);

    return 0;
}
