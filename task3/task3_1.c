/*3. Изучить вопрос создания многомерного динамического массива
3.1 Создание массива при помощи одного указателя*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int N = 3;
    const int M = 4;
    const int L = 5;

    int ar1[N][M][L];

    int *pAr1 = (int*)calloc(N*M*L, sizeof(int));
    if (pAr1 == NULL) exit (1);

    //Заполнение массива
     for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int k = 0; k < L; ++k) {
               *(pAr1 + i*N*M + j*M + k) = rand() % 100;
            }
        }
     }

    //Вывод массива
    for (int i = 0; i < N; ++i) {
        printf("Slice %d: \n", i);
        for (int j = 0; j < M; ++j) {
            for (int k = 0; k < L; ++k) {
                printf("%2d ", *(pAr1 + i*N*M + j*M + k));
            }
        printf("\n");
        }
    }
    free(pAr1);
    pAr1 = NULL;

    return 0;
}
