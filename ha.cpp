#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Fixed-point iteration
double fixed_point_iteration(double (*g)(double), double x0, int n) {
    double x = x0;
    cout << "Fixed-point iteration steps:\n";
    for(int i=1; i<=n; i++) {
        x = g(x);
        cout << "Iteration " << i << ": x = " << setprecision(8) << x << endl;
    }
    return x;
}

// Bisection method 
double bisection(double (*f)(double), double a, double b, int n) {
    double c;
    cout << "Bisection method steps:\n";
    for(int i=1; i<=n; i++) {
        c = (a+b)/2.0;
        cout << "Iteration " << i << ": c = " << setprecision(8) << c << endl;
        if(f(a)*f(c) < 0) b = c;
        else a = c;
    }
    return c;
}

//Secant method
double secant(double (*f)(double), double x0, double x1, int n) {
    double x2;
    cout << "Secant method steps:\n";
    for(int i=1; i<=n; i++) {
        x2 = x1 - f(x1)*(x1-x0)/(f(x1)-f(x0));
        cout << "Iteration " << i << ": x = " << setprecision(8) << x2 << endl;
        x0 = x1;
        x1 = x2;
    }
    return x2;
}

//  Functions for problems
double g1(double x) { return 0.25 + 0.5*sin(x); } // Problem 1
double f2_3(double x) { return x*x*x - x - 1; }   // Problem 2 & 3
double f4(double x) { return x*x - 5; }           // Problem 4
double g5(double x) { return cbrt(x + 1000); }    // Problem 5

int main() {
    cout << fixed << setprecision(8);

    // Problem 1: Fixed-point iteration
    double x0 = 0.5; // initial guess
    fixed_point_iteration(g1, x0, 4);
    cout << endl;

    // Problem 2: Bisection method for x^3 - x -1 = 0
    bisection(f2_3, 1, 2, 4);
    cout << endl;

    // Problem 3: Secant method for x^3 - x -1 = 0
    secant(f2_3, 1, 2, 4);
    cout << endl;

    // Problem 4: Bisection method for sqrt(5)
    bisection(f4, 2, 3, 4);
    cout << endl;

    // Problem 5: Fixed-point iteration for x^3 - x -1000 = 0
    double x0_5 = 10; // initial guess
    fixed_point_iteration(g5, x0_5, 4);

    return 0;
}
