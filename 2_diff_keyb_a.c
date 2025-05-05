#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int choice;

  srand(time(NULL)); // Ініціалізація генератора випадкових чисел

  while (1) {
    printf("\nОберіть завдання:\n");
    printf("1. Ввести масив з клавіатури та виконати завдання.\n");
    printf("2. Згенерувати масив випадковими числами та виконати завдання.\n");
    printf("0. Вихід\n");
    printf("Ваш вибір: ");
    scanf("%d", &choice);

    if (choice == 0) {
      printf("Завершення програми.\n");
      break;
    } else if (choice == 1 || choice == 2) {
      int n;

      printf("Введіть розмірність масиву: ");
      scanf("%d", &n);

      if (n <= 0) {
        printf("Розмірність масиву повинна бути більше нуля.\n");
        continue;
      }

      int arr[n];
      if (choice == 1) {
        printf("Введіть елементи масиву:\n");
        for (int i = 0; i < n; i++) {
          printf("arr[%d]: ", i);
          scanf("%d", &arr[i]);
          while (arr[i] < 0) {
            printf("Будь ласка, введіть невід'ємне число для arr[%d]: ", i);
            scanf("%d", &arr[i]);
          }
        }
      } else {
        printf("Згенеровано масив:\n");
        for (int i = 0; i < n; i++) {
          arr[i] = (rand() % 201) -
                   100; // Генерація випадкових чисел від -100 до 100
          printf("%d ", arr[i]);
        }
        printf("\n");
      }

      // 1) Знайти максимальний елемент
      int max_element = arr[0];
      for (int i = 1; i < n; i++) {
        if (arr[i] > max_element) {
          max_element = arr[i];
        }
      }
      printf("Максимальний елемент масиву: %d\n", max_element);

      // 2) Сума елементів між першим та другим додатними елементами
      int first_positive_index = -1;
      int second_positive_index = -1;
      int sum_between = 0;

      for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
          if (first_positive_index == -1) {
            first_positive_index = i;
          } else if (second_positive_index == -1) {
            second_positive_index = i;
            break; // Знайшли другий додатний, далі не шукаємо
          }
        }
      }

      if (first_positive_index != -1 && second_positive_index != -1) {
        for (int i = first_positive_index + 1; i < second_positive_index; i++) {
          sum_between += arr[i];
        }
        printf("Сума елементів між першим і другим додатними елементами: %d\n",
               sum_between);
      } else {
        printf("В масиві менше двох додатних елементів.\n");
      }

    } else {
      printf("Невірний вибір. Спробуйте ще раз.\n");
    }
  }

  return 0;
}