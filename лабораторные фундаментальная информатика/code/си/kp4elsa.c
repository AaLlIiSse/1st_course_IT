#include <math.h>
#include <stdio.h>
typedef struct root_x root;
struct root_x{
double x;
int steps;
};
double square(double x) {
return x * x;
}
double do_nothing(double x){
return x;
}
root solve_binary_search(double f(double), double l, double r, int k, double
acc) {
int step = 0;
double m;
while(r - l > acc) {
step++;
m = (l + r) / 2.0;
if (f(m) * f(l) < 0) {
r = m;
} else {
l = m;
}
}
root ans = {m, step};
return ans;
}
root solve_iteration(double f(double), double x0, int k, double acc) {
int step = 0;
double cur = x0;
double prev = cur + 1;

while (fabs(cur - prev) > acc) {
prev = cur;
cur = f(prev);
step++;
}
root ans = {cur, step};
return ans;
}
root solve_newton(double f(double), double derivative_f(double), double x0,
int k, double acc) {
int step = 0;
double cur = x0;
double prev = cur + 1;
while (fabs(cur - prev) > acc) {
prev = cur;
cur=prev - f(prev) / derivative_f(prev);
step++;
}
root ans = {cur, step};
return ans;
}
double f13(double x) {
return 3 * x - log(x) - 5;
}
double f14(double x) {
return cos(2 / x) - 2 * sin(1 / x) + 1 / x;
}
double squeeze_f13(double x) {
return x - f13(x) / 1.666667;
}
double squeeze_f14(double x) {
return x - f14(x) / 1.118067;
}
double d_dx_f13(double x) {

return 3 - (4 / x);
}
double d_dx_f14(double x) {
return (2 * sin(2/ x) / (x * x)) + (2 * cos(1 / x) / (x * x)) - (1 / (x * x));
}
int main()
{
int k;
scanf("%d", &k);
double e0 = 1.0;
while(do_nothing(1.0 + e0 / 2.0) > 1.0) {
e0 = e0 / 2.0;
}
printf("Machine epsilon equals %.8e\n", e0);
printf("--------------------------------------\n");
double acc=e0 * pow(10, 16 - k);
root x0;
printf("Answer for 3x-4ln(x)-5=0\n");
x0 = solve_binary_search(f13, 2.0, 4.0, k, acc);
printf("%.*f | %d\n", k, x0.x, x0.steps);
x0 = solve_iteration(squeeze_f13, (2.0+4.0)/2.0, k, acc);
printf("%.*f | %d\n", k, x0.x, x0.steps);
x0 = solve_newton(f13, d_dx_f13, (2.0+4.0)/2.0, k, acc);
printf("%.*f | %d\n", k, x0.x, x0.steps);
printf("Answer for cos(2/x)-2sin(1/x)+1/x=0\n");
x0 = solve_binary_search(f14, 1.0, 2.0, k, acc);
printf("%.*f | %d\n", k, x0.x, x0.steps);
x0 = solve_iteration(squeeze_f14, (1.0+2.0)/2.0, k, acc);
printf("%.*f | %d\n", k, x0.x, x0.steps);
x0 = solve_newton(f14, d_dx_f14, (1.0+2.0)/2.0, k, acc);
printf("%.*f | %d\n", k, x0.x, x0.steps);

return 0;
}
