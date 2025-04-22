// file: array_diff.c
#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int a[MAX_SIZE], b[MAX_SIZE], c[MAX_SIZE];
    int n, i;

    printf("Введіть кількість елементів масивів: ");
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("Перевищено максимальний розмір масиву (%d)\n", MAX_SIZE);
        return 1;
    }

    printf("Введіть елементи масиву a:\n");
    for (i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    printf("Введіть елементи масиву b:\n");
    for (i = 0; i < n; i++) {
        printf("b[%d] = ", i);
        scanf("%d", &b[i]);
    }

    for (i = 0; i < n; i++) {
        c[i] = a[i] - b[i];
    }

    printf("Масив c (a[i] - b[i]):\n");
    for (i = 0; i < n; i++) {
        printf("c[%d] = %d\n", i, c[i]);
    }

    return 0;
}
