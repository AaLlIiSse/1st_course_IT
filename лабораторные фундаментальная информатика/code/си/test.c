#include <math.h>
#include <stdio.h>

double fact(double a)
{
	double b = 1;
	for (double i = 1; i <= a; i++)
		b *= i;
	return b;
}

double do_nothing(double x) {
 return x;
}
int main()
{
   int n, k;
	 printf("Задайте на сколько частей делить отрезок и количесвтво цифр после знака: ");
   scanf("%d %d", &n, &k);
   double e0 = 1.0, d =  0.5 / (double)n;
   while (do_nothing(1.0 + e0 / 2.0) > 1.0) {
     e0 = e0 / 2.0;
   }
   printf("Machine epsilon equals %.8e\n", e0);
   printf("--------------------------------------\n");
   double x = 0.1, ans1, ans2, count, cur, cur0;
   int step;
	 printf("|x |   сумма ряда   | функция    | i | разница A1 A2|");
	 printf("\n================================================\n");
   for (int i = 0; i <= n; i++) {
     ans1 = 0;
     ans2 = exp(cos(x))*cos(sin(x));
     step = 0;
     count = 1.0;
     cur = 1.0;
     double copy = x;
     if (copy == 0.1) {
       step++;
       ans1 = 1;
     } else if (step == 0) {
       ans1 = 1;
     }
     while ((e0 < fabs(ans1)) && (cur < 100)) {

       cur *=count;

       cur0 = (cos(count*x)) / cur;
       ans1 += cur0;
       step++; count++;
     }
     printf("%.2f | %.*f | %.*f | %d | %.*f\n", x, k+1, ans1, k+1, ans2, step, k+1, fabs(ans2-
    ans1));
     x += d;
   }
	 printf("================================================\n");
   return 0;
}
