#include <math.h>
#include <stdio.h>
typedef struct root_x root;
struct root_x{
double x;
int steps;
};


double do_nothing(double x){
return x;
}

root solve_binary_search(double f(double), double l, double r, double
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

root solve_iteration(double f(double), double x0, double acc) {
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

root solve_newton(double f(double), double derivative_f(double), double x0, double acc) {
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
return sin(log(x))-cos(log(x))+2*log(x);
}
double f14(double x) {
return x - 2 + sin(1/x);
}
double squeeze_f13(double x) {
return x - f13(x) / 1.25602;
}
double squeeze_f14(double x) {
return x - f14(x) / (1.000153);
}
double d_dx_f13(double x) {

return (sin(log(x))+cos(log(x))+2)/x;
}
double d_dx_f14(double x) {
return 1 - (cos(1/x)/(x*x));
}

int main()
{
  double e0 = 1.0;
  while(do_nothing(1.0 + e0 / 2.0) > 1.0) {
    e0 = e0 / 2.0;
  }
  printf("Machine epsilon equals %.8e\n", e0);
  printf("--------------------------------------\n");

  double acc=10*e0;

  root x0;

  printf("Answer for: sin(ln(x)) - cos(ln(x)) + 2*ln(x) = 0 \n");

  x0 = solve_binary_search(f13, 1.0, 3.0, acc);
  printf("Методом дихотомии: %.16f | %d\n", x0.x, x0.steps);
  x0 = solve_iteration(squeeze_f13, (1.0+3.0)/2.0, acc);
  printf("Методом итераций: %.16f | %d\n", x0.x, x0.steps);
  x0 = solve_newton(f13, d_dx_f13, (1.0+3.0)/2.0, acc);
  printf("Методом Ньютона: %.16f | %d\n\n", x0.x, x0.steps);

  printf("Answer for:  x - 2 + sin(1/x) = 0 \n");
  x0 = solve_binary_search(f14, 1.2, 2.0, acc);
  printf("Методом дихотомии: %.16f | %d\n", x0.x, x0.steps);
  x0 = solve_iteration(squeeze_f14, (1.2+2.0)/2.0, acc);
  printf("Методом итераций: %.16f | %d\n", x0.x, x0.steps);
  x0 = solve_newton(f14, d_dx_f14, (1.2+2.0)/2.0, acc);
  printf("Методом Ньютона: %.16f | %d\n", x0.x, x0.steps);

  return 0;
}
