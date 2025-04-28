#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int choice;

    while (1) {
        printf("\nОберіть дію:\n");
        printf("1. Обчислити різницю масивів (c[i] = a[i] - b[i])\n");
        printf("0. Вихід\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Завершення програми.\n");
            break; // Вихід з циклу while
        } else if (choice == 1) {
            int a[MAX_SIZE], b[MAX_SIZE], c[MAX_SIZE];
            int n, i;

            printf("Введіть кількість елементів масивів: ");
            scanf("%d", &n);

            if (n > MAX_SIZE) {
                printf("Перевищено максимальний розмір масиву (%d)\n", MAX_SIZE);
                continue; // Повернення до початку циклу while
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
        } else {
            printf("Невірний вибір. Спробуйте ще раз.\n");
        }
    }

    return 0;
}