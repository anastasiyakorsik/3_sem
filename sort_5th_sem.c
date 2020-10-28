#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int Comparing(const void* a, const void* b) {
    int x = *(const int*) a; // as a result we have int
    int y = *(const int*) b;
    return y - x;
}

void Sorting(void* a, int size_of_el, int n, int (*Comparing)(void*, void*)) { //массив размер эл-та кол-во э-ов в массиве и функцию
    char* arr = (char*)a; // приводим массив к типу char*

    char* buffer = (char*)malloc(size_of_el); //указатель на эл-т массива определенного размера

    int comp_res = 0;
    for (int i = 0; i < size_of_el * n; i += size_of_el) {
        for (int j = 0; j < size_of_el * n; j += size_of_el) {
            comp_res = Comparing(a + i, a + j); //сравниваем два эл-та из двух циклов
            if (comp_res >= 0) { //если все ок меняем местами
                memcpy(buffer, arr + i, size_of_el); //копирует в буфер от туда то один эл-т далее аналогично
                memcpy(arr + i, arr + j, size_of_el);
                memcpy(arr + j, buffer, size_of_el);
            }
        }
    }
    free(buffer);
}

int main() {
    int a[3] = {1, 2, 3};


    Sorting(a, sizeof(int), 3, Comparing);

    for (int i = 0; i < 3; i++)
        printf("%d\n", a[i]);
    return 0;
}