#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct Coefs { double A, B, C; };

// Compute coefficients of Lagrange basis polynomial Li(x)
Coefs lagrangeBasisCoeffs(double xi, double xj, double xk) {
    double numA = 1.0;
    double numB = -(xj + xk);
    double numC = xj * xk;
    double denom = (xi - xj) * (xi - xk);
    return { numA / denom, numB / denom, numC / denom };
}

int main() {
    cout << "\n========== PRACTICE 1: LAGRANGE INTERPOLATION ==========\n";
    double x1 = 0.78, y1 = 2.50;
    double x2 = 1.56, y2 = 1.20;
    double x3 = 2.34, y3 = 1.12;

    Coefs L1 = lagrangeBasisCoeffs(x1, x2, x3);
    Coefs L2 = lagrangeBasisCoeffs(x2, x1, x3);
    Coefs L3 = lagrangeBasisCoeffs(x3, x1, x2);

    double a = y1 * L1.A + y2 * L2.A + y3 * L3.A;
    double b = y1 * L1.B + y2 * L2.B + y3 * L3.B;
    double c = y1 * L1.C + y2 * L2.C + y3 * L3.C;

    cout << fixed << setprecision(6);
    cout << "Given 3 points:\n";
    cout << " (x1,y1)=("<<x1<<","<<y1<<"), (x2,y2)=("<<x2<<","<<y2<<"), (x3,y3)=("<<x3<<","<<y3<<")\n";
    cout << "Interpolating polynomial:\n";
    cout << "y = " << a << "x^2 + " << b << "x + " << c << endl;

    auto eval = [&](double X) { return a*X*X + b*X + c; };
    cout << "\nVerification:\n";
    cout << "P("<<x1<<")="<<eval(x1)<<",  P("<<x2<<")="<<eval(x2)<<",  P("<<x3<<")="<<eval(x3)<<"\n";

    return 0;
}
