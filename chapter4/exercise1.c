#include <stdio.h>
#include <math.h>

double vandermonde(double x[], double y[], int n, double xval) {
    double matrix[10][11];
    double coef[10];
    int i, j, k;
    
    for(i = 0; i <= n; i++) {
        matrix[i][0] = 1;
        for(j = 1; j <= n; j++) {
            matrix[i][j] = matrix[i][j-1] * x[i];
        }
        matrix[i][n+1] = y[i];
    }
    
    for(i = 0; i <= n; i++) {
        double pivot = matrix[i][i];
        for(j = 0; j <= n+1; j++) {
            matrix[i][j] /= pivot;
        }
        
        for(k = 0; k <= n; k++) {
            if(k != i) {
                double factor = matrix[k][i];
                for(j = 0; j <= n+1; j++) {
                    matrix[k][j] -= factor * matrix[i][j];
                }
            }
        }
    }
    
    for(i = 0; i <= n; i++) {
        coef[i] = matrix[i][n+1];
    }
    
    double result = 0;
    for(i = n; i > 0; i--) {
        result = result * xval + i * coef[i];
    }
    
    return result;
}

int main() {
    double x[] = {50, 55, 60, 65};
    double y[] = {1.6990, 1.7404, 1.7782, 1.8129};
    int n = 3;
    double x0 = 50;
    
    double approx_derivative = vandermonde(x, y, n, x0);
    double exact_derivative = 1.0 / (x0 * log(10));
    double error = fabs(approx_derivative - exact_derivative);
    
    printf("Exercise 1: Derivative Approximation at x = 50\n");
    printf("================================================\n");
    printf("Approximate derivative: %.8f\n", approx_derivative);
    printf("Exact derivative:       %.8f\n", exact_derivative);
    printf("Absolute error:         %.8e\n", error);
    printf("Relative error:         %.6f%%\n", (error/exact_derivative)*100);
    
    return 0;
}
