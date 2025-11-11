#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Bisection method
double bisection(double (*f)(double), double a, double b, int n) {
    double c;
    for(int i=1; i<=n; i++) {
        c = (a+b)/2.0;
        cout << "Iteration " << i << ": c = " << setprecision(8) << c << endl;
        if(f(a)*f(c) < 0) b = c;
        else a = c;
    }
    return c;
}

// Functions for problems
double f2(double x) { return x*x*x - x - 1; }    // Problem 2
double f4(double x) { return x*x - 5; }         // Problem 4

int main() {
    cout << fixed << setprecision(8);

    cout << "Problem 2: Bisection method\n";
    bisection(f2, 1, 2, 4);
    cout << endl;

    cout << "Problem 4: Bisection method\n";
    bisection(f4, 2, 3, 4);
    cout << endl;

    return 0;
}
