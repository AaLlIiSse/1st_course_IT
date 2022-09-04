#include <stdio.h>
#include <math.h>
double fact(double a)
{
	double b = 1;
  if ( a == 0 ){
    return b;
  }
	else {for (double i = 1; i <= a; i++){
		b *= i;
	  return b;
  }
}
}

int main() {
  double x, a = 0.1, b = 0.6, h = (b-a)/10, s, d, eps = 1, znam, d1; double e = 2.7182818;
  int n, q;
  while (1 <1+eps) eps/=2;
  printf("eps = %.16f\n", eps);
  printf("----------------------------------------------------\n");
  printf("| x      |     sum       |    f     | n      |\n");
  printf("----------------------------------------------------\n");
  for (x = a; x < b+0.001; x+=h){
    s = 0; d = 1; n = 0.1; d1 = x;
    while (fabs(d) > eps) {
      znam = fact(n);
      if (n==0) {d = d1;}
      else { d = cos(d*n);}
      s += d/znam; n++;
    }
    printf("| %.2f | %.16f | %.16f | %d |\n", x, s, pow(e, cos(x))*cos(sin(x)), n);
}
  printf("----------------------------------------\n");
}
