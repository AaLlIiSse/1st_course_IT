#include <stdio.h>
int main(void){
   int m;
   while (m != EOF){
     printf("Введите размер квадратной матрицы: ");
     scanf("%d", &m);
     int a[m][m];
     for (int i = 0; i < m; ++i) {
       for (int j = 0; j < m; ++j) {
         scanf("%d", &a[i][j]);
       }
    }
    printf("Исходная матрица: \n");
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < m; ++j) {
        printf("%d ", a[i][j]);
        if (j==m-1){
          printf("\n");
        }
      }
   }
   printf("\n");

     int k = 0, l = 1, shift = (m - 1);
     printf("Печать в строку по обходу матрицы: ");
     while (k < m + m - 1) {
       if (l % 2 != 0) {
         for (int i = 0; i < m; ++i) {
           for (int j = 0; j < m; ++j) {
             if (i + shift == j) {
             printf("%d ", a[i][j]);
             }
            }
         }
      } else {
         for (int i = 0; i < m; ++i) {
           for (int j = 0; j < m; ++j) {
             if (i + shift == j) {
             printf("%d ", a[i][j]);
             }
           }
         }
      }
       l++;
       shift--;
       k++;
     }
     printf("\n");
  }
return 0;
}
