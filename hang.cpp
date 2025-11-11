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

// Function to check if a number is prime
bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// Function to calculate the definite integral using Simpson's 1/3 Rule
double simpsons_rule(double a, double b, int n) {
    if (n % 2 != 0 || n <= 0) {
        cerr << "Error: Simpson's Rule requires an even and positive number of intervals (n)." << endl;
        return 0.0;
    }

    double h = (b - a) / n;
    double integral_sum = f_x(a) + f_x(b);
    
    for (int i = 1; i < n; i++) {
        double x_i = a + i * h;
        if (i % 2 != 0) {
            integral_sum += 4.0 * f_x(x_i);
        } else {
            integral_sum += 2.0 * f_x(x_i);
        }
    }
    
    return (h / 3.0) * integral_sum;
}

int main() {
    cout << fixed << setprecision(10);

    const double A = 100.0;
    const double B = 200.0;
    const int N = 100;

    // --- (a) Count primes between 100 and 200 ---
    int prime_count = 0;
    for (int num = (int)A + 1; num < (int)B; num++) {
        if (is_prime(num)) {
            prime_count++;
        }
    }

    // --- (b) Simpson's Rule Approximation ---
    double I_simpson = simpsons_rule(A, B, N);

    cout << "--- Calculation Summary ---" << "\n";
    cout << "Function: f(x) = 1 / ln(x)" << "\n";
    cout << "Integration Range [A, B]: [" << A << ", " << B << "]" << "\n";
    cout << "Simpson Intervals (N): " << N << "\n";
    cout << "Step Size (h): " << (B - A) / N << "\n";
    cout << "\n";

    cout << "(a) Number of primes in (100, 200): " << prime_count << "\n";
    cout << "(b) Approximate Integral I = " << I_simpson << "\n";
    cout << "Comparison: prime_count - I ≈ " << prime_count - I_simpson << "\n";

    return 0;
}
