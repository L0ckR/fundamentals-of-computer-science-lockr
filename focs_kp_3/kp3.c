#include <stdio.h>
#include <math.h>

#define MAX_ITER 100

typedef long double ldbl;

const ldbl k = 10e2;

ldbl epsilon() {
    ldbl eps = 1.0;
    while (1 + eps / 2.0 != 1)
        eps /= 2.0;
    return eps;
}

ldbl function(ldbl x) {
    return (3*x - 5)/(x*x - 4*x + 3);
}

ldbl Taylor(ldbl x, int n) {
    ldbl sum = 0;
    for (ldbl i = 0.0; i <= n; i++) {
      sum -= (1 + 2.0/pow(3.0, i + 1))*pow(x, i);
    }
    return sum;
}

int main() {
    ldbl abs_eps = epsilon();
    ldbl relative_eps = sqrt(abs_eps);
    ldbl a = 0.0, b = 0.5, result;
    int n;
    printf("Enter the number of iterations: ");
    scanf("%d", &n);
    printf("Machine epsilon for long double = %.16Le\n", abs_eps);
    ldbl step = (b - a) / n;
    printf("Taylor series value table for function f(x) = (3*x - 5)/(x^2 - 4*x + 3)\n");
    printf("|_______________________________________________________________________| \n");
    printf("|    x    |       sum of row        |         function        |  iter   |\n");
    printf("|_________|_________________________|_________________________|_________|\n");
    for (ldbl x = a; x <= b step/2; x += step) {
      for (n = 0; n < MAX_ITER; n++) {
        result = Taylor(x, n);
        if (fabs(result) <= fmax(relative_eps * fabs(result), abs_eps)) {
          break;
        }
      }
      printf("| %.5Lf | %.20Lf | %.20Lf |   %d\t|\n", x, result, function(x), n);
      result = 0.0;
    }
    printf("|_________|_________________________|_________________________|_________|\n");
    return 0;
}
