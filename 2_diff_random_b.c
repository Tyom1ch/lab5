// file: array_random.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int n, i;
    int max, firstPos = -1, secondPos = -1, sum = 0;

    srand(time(NULL));

    printf("Введіть кількість елементів масиву: ");
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("Максимально дозволено %d елементів.\n", MAX_SIZE);
        return 1;
    }

    // Генерація псевдовипадкових чисел в діапазоні [-100, 100]
    printf("Згенерований масив:\n");
    for (i = 0; i < n; i++) {
        arr[i] = (rand() % 201) - 100;
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    // Пошук максимального елемента
    max = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }

    // Пошук першого і другого додатного елементу
    for (i = 0; i < n; i++) {
        if (arr[i] > 0) {
            if (firstPos == -1)
                firstPos = i;
            else {
                secondPos = i;
                break;
            }
        }
    }

    if (firstPos != -1 && secondPos != -1) {
        for (i = firstPos + 1; i < secondPos; i++) {
            sum += arr[i];
        }
    } else {
        printf("У масиві менше двох додатних елементів.\n");
    }

    printf("Максимальний елемент: %d\n", max);
    if (secondPos != -1)
        printf("Сума між першим і другим додатним елементом: %d\n", sum);

    return 0;
}
