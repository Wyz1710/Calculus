#include <stdio.h>
#include <math.h>

double trapezoidal(double a, double b, int n, double (*f)(double)) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    
    int i;
    for (i = 1; i < n; i++) {
        sum = sum + 2 * f(a + i * h);
    }
    
    return (h / 2) * sum;
}

double simpson(double a, double b, int n, double (*f)(double)) {
    if (n % 2 == 1) n = n + 1;
    
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    
    int i;
    for (i = 1; i < n; i = i + 2) {
        sum = sum + 4 * f(a + i * h);
    }
    
    for (i = 2; i < n; i = i + 2) {
        sum = sum + 2 * f(a + i * h);
    }
    
    return (h / 3) * sum;
}

double func1(double x) {
    return 1.0 / (1.0 + x);
}

double func2(double x) {
    if (x == 0) return 1.0;
    return sin(x) / x;
}

double func3(double x) {
    return 1.0 / (1.0 + x * x);
}

int main() {
    double result_trap, result_simp, exact, error;
    
    printf("\n=== EXERCISE 2 ===\n");
    printf("Integrate: 1/(1+x) from 0 to 1\n");
    printf("Exact answer = ln(2) = 0.693147\n\n");
    
    result_trap = trapezoidal(0, 1, 10, func1);
    result_simp = simpson(0, 1, 10, func1);
    exact = log(2);
    
    printf("Trapezoidal (n=10): %.6f\n", result_trap);
    printf("Error: %.6f\n\n", fabs(exact - result_trap));
    
    printf("Simpson (n=10):     %.6f\n", result_simp);
    printf("Error: %.6f\n", fabs(exact - result_simp));
    
    
    printf("\n\n=== EXERCISE 3 ===\n");
    printf("Integrate: sin(x)/x from 0 to 1\n");
    printf("Exact answer = 0.946083\n\n");
    
    result_trap = trapezoidal(0, 1, 18, func2);
    result_simp = simpson(0, 1, 18, func2);
    exact = 0.946083;
    
    printf("Trapezoidal (n=18): %.6f\n", result_trap);
    error = fabs(exact - result_trap);
    printf("Error: %.6f\n", error);
    printf("Is error < 0.0003? %s\n\n", error < 0.0003 ? "YES" : "NO");
    
    printf("Simpson (n=18):     %.6f\n", result_simp);
    printf("Error: %.6f\n", fabs(exact - result_simp));
    
    
    printf("\n\n=== LECTURE EXAMPLE ===\n");
    printf("Integrate: 1/(1+x^2) from 0 to 1\n");
    printf("Exact answer = pi/4 = 0.785398\n\n");
    
    result_trap = trapezoidal(0, 1, 10, func3);
    result_simp = simpson(0, 1, 4, func3);
    exact = 3.14159265358979323846 / 4.0;
    
    printf("Trapezoidal (n=10): %.6f\n", result_trap);
    printf("Error: %.6f\n", fabs(exact - result_trap));
    printf("Lecture says: 0.784982 - Match? %s\n\n", 
           fabs(result_trap - 0.784982) < 0.001 ? "YES" : "NO");
    
    printf("Simpson (n=4):      %.6f\n", result_simp);
    printf("Error: %.6f\n", fabs(exact - result_simp));
    printf("Lecture says: 0.785392 - Match? %s\n", 
           fabs(result_simp - 0.785392) < 0.001 ? "YES" : "NO");
    
    
    printf("\n\n=== CONCLUSION ===\n");
    printf("Simpson's Rule is much more accurate than Trapezoidal!\n");
    printf("With same number of points, Simpson gives smaller error.\n\n");
    
    return 0;
}