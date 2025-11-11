#include <stdio.h>
#include <math.h>

double f(double x) {
    return 1.0 / (1.0 + x);
}

double trapezoidal(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    int i;
    
    for(i = 1; i < n; i++) {
        sum += 2 * f(a + i * h);
    }
    
    return (h / 2.0) * sum;
}

double simpson(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    int i;
    
    for(i = 1; i < n; i++) {
        if(i % 2 == 1) {
            sum += 4 * f(a + i * h);
        } else {
            sum += 2 * f(a + i * h);
        }
    }
    
    return (h / 3.0) * sum;
}

int main() {
    double a = 0.0;
    double b = 1.0;
    int n = 10;
    
    double exact = log(2);
    double trap_result = trapezoidal(a, b, n);
    double simp_result = simpson(a, b, n);
    
    double trap_error = fabs(exact - trap_result);
    double simp_error = fabs(exact - simp_result);
    
    double h = (b - a) / n;
    double M2 = 2.0;
    double trap_error_bound = (M2 / 12.0) * h * h * (b - a);
    
    double M4 = 24.0;
    double simp_error_bound = (M4 / 180.0) * h * h * h * h * (b - a);
    
    printf("Exercise 2: Integration of 1/(1+x) from 0 to 1\n");
    printf("================================================\n");
    printf("Number of subintervals: %d\n", n);
    printf("Step size h: %.4f\n\n", h);
    
    printf("Exact value (ln 2):     %.10f\n\n", exact);
    
    printf("Trapezoidal Rule:\n");
    printf("  Approximate value:    %.10f\n", trap_result);
    printf("  Absolute error:       %.10e\n", trap_error);
    printf("  Error bound:          %.10e\n", trap_error_bound);
    printf("  Relative error:       %.6f%%\n\n", (trap_error/exact)*100);
    
    printf("Simpson's Rule:\n");
    printf("  Approximate value:    %.10f\n", simp_result);
    printf("  Absolute error:       %.10e\n", simp_error);
    printf("  Error bound:          %.10e\n", simp_error_bound);
    printf("  Relative error:       %.6f%%\n", (simp_error/exact)*100);
    
    return 0;
}
