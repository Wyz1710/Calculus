#include <iostream>
#include <cmath> 
#include <iomanip> 

using namespace std;

// Function: f(x) = 1 / ln(x)
double f_x(double x) {
    if (x > 1.0) {
        return 1.0 / std::log(x);
    }
    return 0.0;
}

// Function to calculate the definite integral using Simpson's 1/3 Rule
double simpsons_rule(double a, double b, int n) {
    if (n % 2 != 0 || n <= 0) {
        cerr << "Error: Simpson's Rule requires an even and positive number of intervals (n)." << endl;
        return 0.0;
    }

    // Step size (h)
    double h = (b - a) / n;
    
    // Initial sum: f(x0) + f(xn)
    double integral_sum = f_x(a) + f_x(b); 
    
    // Summation for internal points
    for (int i = 1; i < n; i++) {
        double x_i = a + i * h;
        
        if (i % 2 != 0) {
            // Coefficient 4 for odd indices (x1, x3, x5, ...)
            integral_sum += 4.0 * f_x(x_i); 
        } else {
            // Coefficient 2 for even indices (x2, x4, x6, ...)
            integral_sum += 2.0 * f_x(x_i); 
        }
    }
    
    // Final result: I = (h/3) * S
    return (h / 3.0) * integral_sum;
}

int main() {
    cout << fixed << setprecision(10); 

    // Parameters
    const double A = 100.0;
    const double B = 200.0;
    const int N = 100;

    // --- (a) Number of Integers ---
    int num_integers = (int)B - (int)A - 1; 
    
    // --- (b) Simpson's Rule Approximation ---
    double I_simpson = simpsons_rule(A, B, N);
    
    cout << "--- Calculation Summary (Integral Approximation) ---" << "\n";
    cout << "Function: f(x) = 1 / ln(x)" << "\n";
    cout << "Integration Range [A, B]: [" << A << ", " << B << "]" << "\n";
    cout << "Simpson Intervals (N): " << N << "\n";
    cout << "Step Size (h): " << (B - A) / N << "\n";
    cout << "\n";

    cout << "1. Count of Integers in (A, B): " << num_integers << "\n";
    cout << "2. Approximate Integral Value (I): " << I_simpson << "\n";
    
    cout << "\n";
    cout << "Observation: The integral value (" << I_simpson << ") closely approximates the integer count (" << num_integers << ")." << "\n";

    return 0;
}