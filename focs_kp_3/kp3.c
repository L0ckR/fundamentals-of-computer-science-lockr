#include <stdio.h>
#include <math.h>

#define MAX_ITER 50

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
    ldbl three = 3;
    ldbl x_i = 1;
    for (int i = 0; i <= n; i++) {
      sum -= (1 + 2.0/three)*x_i;
      three *= 3.0;
      x_i *= x;
    }
    return sum;
}

int main() {
    ldbl abs_eps = epsilon();
    ldbl a = 0.0, b = 0.5, result;
    int n;
    printf("Enter the number of iterations: ");
    scanf("%d", &n);
    printf("Machine epsilon for long double = %.16Le\n", abs_eps);
    ldbl step = (b - a) / n;
    printf("Taylor series value table for function f(x) = (3*x - 5)/(x^2 - 4*x + 3)\n");
    printf("|_____________________________________________________________ \n");
    printf("|    x    |       sum of row        |         function        |\n");
    printf("|_________|_________________________|_________________________|\n");
    for (ldbl x = a; x <= b + epsilon(); x += step) {
      result = Taylor(x, MAX_ITER);
      printf("| %.5Lf | %.20Lf | %.20Lf |\n", x, result, function(x));
      result = 0.0;
    }
    printf("|_________|_________________________|_________________________|\n");
    return 0;
}