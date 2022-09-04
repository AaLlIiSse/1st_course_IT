#include <stdio.h>

int main() {
    int n, m ;
    printf("Введите размерность матрицы: ");
    scanf("%d %d", &n, &m);
    int arr[n][m];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            scanf("%d", &arr[i][j]);
    }
    printf("Исходная матрица: \n");
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < m; ++j) {
        printf("%d ", arr[i][j]);
      }
      printf("\n");
   }
   printf("\n");

    int max = 0, min = 0;

    int min_index = 0, max_index = 0;

    for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++)    // находим сумму
                sum += arr[i][j];

            if (j < 1 || sum > max) {  // если считаем сумму в первый раз или она больше уже найденной
                max = sum;
                max_index = j;
            }

            if (j < 1 || sum < min) { // то же самое для минимума
                min = sum;
                min_index = j;
            }
        }

    for (int i = 0; i < n; i++){
        int temp = arr[i][min_index];
        arr[i][min_index] = arr[i][max_index];
        arr[i][max_index] = temp;
    }
    printf("Получившаяся матрица: \n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
 }
