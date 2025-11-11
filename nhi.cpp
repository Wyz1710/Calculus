#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

//=================== STRUCTS & UTILITIES ===================
struct Coefs { double A, B, C; };
double deg2rad(double d) { return d * M_PI / 180.0; }

//=================== PRACTICE 1: LAGRANGE (3 POINTS) ===================
Coefs lagrangeBasisCoeffs(double xi, double xj, double xk) {
    double numA = 1.0;
    double numB = -(xj + xk);
    double numC = xj * xk;
    double denom = (xi - xj) * (xi - xk);
    return { numA / denom, numB / denom, numC / denom };
}

void practice1() {
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
}

//=================== PRACTICE 2: LAGRANGE ERROR FOR SIN(X) ===================
void practice2() {
    cout << "\n========== PRACTICE 2: ERROR OF L5(x) FOR sin(x) ==========\n";
    vector<double> xdeg = {0,5,10,15,20,25};
    vector<double> y;
    for (double d : xdeg) y.push_back(sin(deg2rad(d)));

    double x = 12.5; // 12°30′
    double L5 = 0;
    for (int i = 0; i < 6; ++i) {
        double term = y[i];
        for (int j = 0; j < 6; ++j) if (i != j)
            term *= (x - xdeg[j]) / (xdeg[i] - xdeg[j]);
        L5 += term;
    }
    double trueVal = sin(deg2rad(x));
    double err = trueVal - L5;

    cout << fixed << setprecision(10);
    cout << "x = " << x << " degrees\n";
    cout << "True sin(x) = " << trueVal << "\n";
    cout << "L5(x)       = " << L5 << "\n";
    cout << "Error (sin - L5) = " << err << "\n";
}

//=================== PRACTICE 3: LEAST SQUARES FITTING ===================
void practice3() {
    cout << "\n========== PRACTICE 3: LEAST SQUARES FITTING ==========\n";
    vector<double> x = {2,4,6,8,10,12};
    vector<double> y = {7.32,8.24,9.20,10.19,11.01,12.05};
    int n = x.size();

    cout << fixed << setprecision(6);

    // 1️⃣ Linear: y = a + b x
    double sx=0, sy=0, sxx=0, sxy=0;
    for (int i=0;i<n;i++){ sx+=x[i]; sy+=y[i]; sxx+=x[i]*x[i]; sxy+=x[i]*y[i]; }
    double b=(n*sxy - sx*sy)/(n*sxx - sx*sx);
    double a=(sy - b*sx)/n;
    cout << "Linear fit:     y = " << a << " + " << b << "x\n";

    // 2️⃣ Quadratic: y = a + b x + c x^2
    double sx3=0, sx4=0, sx2=0, sxy2=0;
    for (int i=0;i<n;i++){ sx2+=x[i]*x[i]; sx3+=x[i]*x[i]*x[i]; sx4+=x[i]*x[i]*x[i]*x[i]; sxy2+=x[i]*x[i]*y[i]; }
    double D = n*(sx2*sx4 - sx3*sx3) - sx*(sx*sx4 - sx2*sx3) + sx2*(sx*sx3 - sx2*sx2);
    double Da = sy*(sx2*sx4 - sx3*sx3) - sx*(sxy*sx4 - sxy2*sx3) + sx2*(sxy*sx3 - sxy2*sx2);
    double Db = n*(sxy*sx4 - sxy2*sx3) - sy*(sx*sx4 - sx2*sx3) + sx2*(sx*sxy2 - sx2*sy);
    double Dc = n*(sx2*sxy2 - sx3*sxy) - sx*(sx*sxy2 - sx2*sy) + sy*(sx*sx3 - sx2*sx2);
    double A=Da/D, B=Db/D, C=Dc/D;
    cout << "Quadratic fit:  y = " << A << " + " << B << "x + " << C << "x^2\n";

    // 3️⃣ Power model: y = a * x^b  → ln(y)=ln(a)+b ln(x)
    double Sx=0, SyL=0, SxxL=0, SxyL=0;
    for (int i=0;i<n;i++){ double lx=log(x[i]), ly=log(y[i]);
        Sx+=lx; SyL+=ly; SxxL+=lx*lx; SxyL+=lx*ly; }
    double bL=(n*SxyL - Sx*SyL)/(n*SxxL - Sx*Sx);
    double aL=(SyL - bL*Sx)/n;
    double aExp=exp(aL);
    cout << "Power fit:      y = " << aExp << " * x^" << bL << "\n";
}

//=================== MAIN PROGRAM ===================
int main() {
    cout << "========== PRACTICE 4: IMPLEMENTATION & VERIFICATION ==========\n";
    cout << "Language: C++ | Objective: Verify results of Practices 1 - 3\n";

    practice1();
    practice2();
    practice3();

    cout << "\n========== END OF PRACTICE 4 ==========\n";
    return 0;
}
