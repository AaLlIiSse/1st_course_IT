#include <stdio.h>
#include <math.h>
double fact(double a)
{
	double b = 1;
	for (double i = 1; i <= a; i++)
		b *= i;
	return b;
}
void main() {
	float a = 0.1, b = 0.6;
	double x = a, step, sum, znach, eps = 1, prom, sum_prom = 1; double e = 2.7182818;
	int n, steps, k = 1;
	while (1 + eps / 2 > 1)
		eps /= 2;
	printf("Mashinnoe epsilon = %.20f\n\n", eps);
	printf("Vvedite chislo razbieniya otrezka [%1.1f, %1.1f]: ", a, b);
	scanf("%d", &steps);
	step = (b - a) / steps;
	eps *= k;
	printf("\n==========================================================================\n");
	printf("|| Shag\t  x\t     summa ryada               function           i     ||\n");
	printf("||----------------------------------------------------------------------||\n");
	for (int i = 0; i <= steps; i++) {
		sum = 0;
		n = 0;
		prom = x;
		do {
			znach = cos(n*prom) / fact(n);
			sum += znach;
			n++;
	} while ((znach> eps || znach< -eps) && n < 100);
		printf("|| %2d\t %.2f\t %.17f\t %.17f\t %2d\t||\n", i, x, sum, pow(e, cos(x))*cos(sin(x)) , n);
		x += step;
	}
	printf("==========================================================================\n");
}
