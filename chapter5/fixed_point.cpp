#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Fixed-point iteration function
double fixed_point_iteration(double (*g)(double), double x0, int n) {
    double x = x0;
    for(int i=1; i<=n; i++) {
        x = g(x);
        cout << "Iteration " << i << ": x = " << setprecision(8) << x << endl;
    }
    return x;
}

// Functions for problems
double g1(double x) { return 0.25 + 0.5*sin(x); }     // Problem 1
double g5(double x) { return cbrt(x + 1000); }        // Problem 5

int main() {
    cout << fixed << setprecision(8);

    cout << "Problem 1: Fixed-point iteration\n";
    fixed_point_iteration(g1, 0.5, 4);
    cout << endl;

    cout << "Problem 5: Fixed-point iteration\n";
    fixed_point_iteration(g5, 10, 4);
    cout << endl;

    return 0;
}
