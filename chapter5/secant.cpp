#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Secant method
double secant(double (*f)(double), double x0, double x1, int n) {
    double x2;
    for(int i=1; i<=n; i++) {
        x2 = x1 - f(x1)*(x1-x0)/(f(x1)-f(x0));
        cout << "Iteration " << i << ": x = " << setprecision(8) << x2 << endl;
        x0 = x1;
        x1 = x2;
    }
    return x2;
}

// Function for Problem 3
double f3(double x) { return x*x*x - x - 1; }

int main() {
    cout << fixed << setprecision(8);

    cout << "Problem 3: Secant method\n";
    secant(f3, 1, 2, 4);
    cout << endl;

    return 0;
}
