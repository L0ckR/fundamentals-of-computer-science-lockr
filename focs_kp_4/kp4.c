#include <stdio.h>
#include <math.h>

typedef double dbl;

dbl epsilon() {
    dbl eps = 1.0;
    while (1 + eps / 2.0 != 1)
        eps /= 2.0;
    return eps;
}

dbl F9(dbl x) {
    return x*x - log(1 + x) - 3;
}

dbl F9_ot_x(dbl x) {
    return (log(1 + x) + 3)/x;
}

dbl F9_ot_x_first_derivative(dbl x) {
    return (-2*x - (1 + x)*log(1+x) - 3)/(x*x + x*x*x);
}

dbl F9_first_derivative(dbl x) {
    return 2*x - 1/(1+x);
}

dbl F9_second_derivative(dbl x) {
    return (2*x*x + 4*x + 3)/((1+x)*(1+x));
}


dbl F10(dbl x) {
    return 2*x*sin(x) - cos(x);
}

dbl F10_ot_x(dbl x) {
    return 1/(2*tan(x));
}

dbl F10_ot_x_first_derivative(dbl x) {
    return (-1/(sin(x)*sin(x)))/2;
}

dbl F10_first_derivative(dbl x) {
    return 3*sin(x) + 2*x*cos(x);
}

dbl F10_second_derivative(dbl x) {
    return 5*cos(x) - 2*x*sin(x);
}


dbl dichotomy(dbl (*F)(dbl), dbl a, dbl b, dbl relative_eps, dbl abs_eps) {
    dbl x = (a + b) / 2;
    if (F(a) * F(b) >= 0){
        return NAN;
    }
    while (fabs(a - b) > fmax(relative_eps * fabs(x), abs_eps)) {
        x = (a + b) / 2;
        if (F(x) * F(a) < 0) {
            b = x;
        }
        else {
            a = x;
        }
    }
    return x;
}

dbl iterations(dbl (*F_x)(dbl), dbl (*F_x_first_derivative)(dbl), dbl a, dbl b, dbl relative_eps, dbl abs_eps) {
    dbl x = (a + b) / 2;
    if (fabs(F_x_first_derivative(x)) >= 1) {
        printf("\n x - %lf; f -%lf debug printami\n", x, F_x_first_derivative(x));
        return NAN;
    }
    while (fabs(F_x(x) - x) >= fmax(relative_eps * fabs(x), abs_eps)) {
        x = F_x(x);
    }
    return x;
}

dbl newton(dbl (*F)(dbl), dbl (*F_first_derivative)(dbl), dbl (*F_second_derivative)(dbl), dbl a, dbl b, dbl relative_eps, dbl abs_eps) {
    dbl x = (a + b / 2);
    if (fabs(F(x) * F_second_derivative(x)) >= (F_first_derivative(x) * F_first_derivative(x))) {
        return NAN;
    }
    while (fabs(F(x) / F_first_derivative(x)) > fmax(relative_eps * fabs(x), abs_eps)) {
        x -= F(x) / F_first_derivative(x);
    }
    return x;
}

void result(dbl d, dbl i, dbl n) {
   if (d != NAN) printf("Dichotomy method: %.10f\n", d);
   else printf("The dichotomy method isn't suitable\n");
   if (i != NAN) printf("Iterations method: %.10f\n", i);
   else printf("The iterations method isn't suitable\n");
   if (n != NAN) printf("Newton's method: %.10f\n", n);
   else printf("The Newton's method isn't suitable\n");
}


int main() {
    dbl abs_eps = epsilon();
    dbl relative_eps = sqrt(abs_eps);
    dbl a9 = 2, b9 = 3, a10 = 0.4, b10 = 1;
    dbl d9 = dichotomy(F9, a9, b9, relative_eps, abs_eps);
    dbl i9 = iterations(F9_ot_x, F9_ot_x_first_derivative, a9, b9, relative_eps, abs_eps);
    dbl n9 = newton(F9, F9_first_derivative, F9_second_derivative, a9, b9, relative_eps, abs_eps);
    printf("Machine epsilon for long double = %.16e\n", abs_eps);
    printf(" x^2 - ln(1 + x) - 3 = 0 \n");
    result(d9, i9, n9);
    printf("\n\n");
    dbl d10 = dichotomy(F10, a10, b10, relative_eps, abs_eps);
    dbl i10 = iterations(F10_ot_x, F10_ot_x_first_derivative, a10, b10, relative_eps, abs_eps);
    dbl n10 = newton(F10, F10_first_derivative, F10_second_derivative, a10, b10, relative_eps, abs_eps);
    printf("Machine epsilon for long double = %.16e\n", abs_eps);
    printf(" 2*x*sin(x) - cos(x) = 0 \n");
    result(d10, i10, n10);
    return 0;
}