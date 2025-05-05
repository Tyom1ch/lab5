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
            } else if (n < 1) {
                printf("Кількість елементів має бути більшою за нуль!\n");
                continue; // Повернення до початку циклу while
            }

            printf("Введіть елементи масиву a (не менше 0):\n");
            for (i = 0; i < n; i++) {
                do {
                    printf("a[%d] = ", i);
                    scanf("%d", &a[i]);
                    if (a[i] < 0) {
                        printf("Введіть невід'ємне число!\n");
                    }
                } while (a[i] < 0);
            }

            printf("Введіть елементи масиву b (не менше 0):\n");
            for (i = 0; i < n; i++) {
                do {
                    printf("b[%d] = ", i);
                    scanf("%d", &b[i]);
                    if (b[i] < 0) {
                        printf("Введіть невід'ємне число!\n");
                    }
                } while (b[i] < 0);
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
