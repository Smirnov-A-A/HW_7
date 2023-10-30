/*3. Изучить вопрос создания многомерного динамического массива
3.1 Создание многомерного динамического массива через массив указателей
*/

#include <stdio.h>
#include <stdlib.h>


int main() {

    const int N = 3;
    const int M = 4;
    const int L = 5;

    //выделение памяти для массива указателей на массив указателей на строки
    int ***pAr = (int***)calloc(N, sizeof(int**));

    //Каждый указатель в массиве pAr[i] - адрес начала слоя
    for (int i = 0; i < N; ++i) {
        pAr[i] = (int**)calloc(M, sizeof(int*));

        //Каждый указатель в массиве pAr[i][j] - адрес строки в соответствующем слое
        for (int j = 0; j < L; ++j) {
            pAr[i][j] = (int*)calloc(L, sizeof(int));
        }
    }

   //заполнение массива
   for (int i = 0; i < N; ++i) {
       for (int j = 0; j < M; ++j) {
           for (int k = 0; k < L; ++k) {
               pAr[i][j][k] = rand() % 100;
           }
       }
   }

    //Вывод массива
    for (int i = 0; i < N; ++i) {
        printf("Slice %d: \n", i);
        for (int j = 0; j < M; ++j) {
            for (int k = 0; k < L; ++k) {
                printf("%2d ", pAr[i][j][k]);
            }
        printf("\n");
        }
    }

    //Освобождение памяти
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            free(pAr[i][j]);
            pAr[i][j] = NULL;
        }
        free(pAr[i]);
        pAr[i] = NULL;
    }
    free(pAr);
    pAr = NULL;

    return 0;

}

