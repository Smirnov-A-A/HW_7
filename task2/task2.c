/*2. Сортировка методом пузырька при помощи указателей*/

#include <stdio.h>

int main() {

    const int N = 6;
    int ar[6] = {1,1,-10,1,0,-7};
    int *pAr = ar + (N - 1);             //последний элемент массива

    //Вывод исходного массива
    printf("Исходный массив:\n");
    for (int i = 0; i < N; ++i) {
        printf("%4d", ar[i]);
    }

    //Сортировка методом пузырька
    for (int i = 0; i < (N - 1); ++i) {
        int temp = 0;
        int *pCur = pAr;

        for (int j = N - 1; j > i; --j)  {
            if (*pCur < *(pCur - 1)) {
                temp = *(pCur - 1);
                *(pCur - 1) = *pCur;
                *pCur = temp;
            }
            --pCur;
        }
    }

    //Вывод отсортированного массива
    printf("\nОтсортированный массив:\n");
    for (int i = 0; i < N; ++i) {
        printf("%4d", ar[i]);
    }
    printf("\n");
    return 0;
}
