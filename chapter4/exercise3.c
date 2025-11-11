#include <stdio.h>
#include <math.h>

double f(double x) {
    if(fabs(x) < 1e-10) {
        return 1.0;
    }
    return sin(x) / x;
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
    double target_error = 3e-4;
    
    double M2 = 2.0;
    
    int n = (int)ceil(sqrt((M2 * (b - a)) / (12.0 * target_error)));
    if(n % 2 != 0) n++;
    
    double h = (b - a) / n;
    
    double trap_error_bound = (M2 / 12.0) * h * h * (b - a);
    
    double M4 = 24.0;
    double simp_error_bound = (M4 / 180.0) * h * h * h * h * (b - a);
    
    double trap_result = trapezoidal(a, b, n);
    double simp_result = simpson(a, b, n);
    
    printf("Exercise 3: Integration of sin(x)/x from 0 to 1\n");
    printf("================================================\n");
    printf("Target error for trapezoidal: %.2e\n\n", target_error);
    
    printf("Part 1: Number of subintervals needed\n");
    printf("  n = %d (even number for Simpson's rule)\n", n);
    printf("  Step size h = %.6f\n\n", h);
    
    printf("Part 2: Error bounds\n");
    printf("  Trapezoidal error bound:  %.10e\n", trap_error_bound);
    printf("  Simpson's error bound:    %.10e\n\n", simp_error_bound);
    
    printf("Part 3: Calculated integrals (6 decimal places)\n");
    printf("  Trapezoidal Rule:  %.6f\n", trap_result);
    printf("  Simpson's Rule:    %.6f\n", simp_result);
    
    return 0;
}
