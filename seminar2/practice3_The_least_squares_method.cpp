#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

int main() {
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
    double sx2=0, sx3=0, sx4=0, sx2y=0;
    for (int i=0;i<n;i++){ sx2+=x[i]*x[i]; sx3+=x[i]*x[i]*x[i]; sx4+=x[i]*x[i]*x[i]*x[i]; sx2y+=x[i]*x[i]*y[i]; }
    double D = n*(sx2*sx4 - sx3*sx3) - sx*(sx*sx4 - sx2*sx3) + sx2*(sx*sx3 - sx2*sx2);
    double Da = sy*(sx2*sx4 - sx3*sx3) - sx*(sxy*sx4 - sx2y*sx3) + sx2*(sxy*sx3 - sx2y*sx2);
    double Db = n*(sxy*sx4 - sx2y*sx3) - sy*(sx*sx4 - sx2*sx3) + sx2*(sx*sx2y - sx2*sy);
    double Dc = n*(sx2*sx2y - sx3*sxy) - sx*(sx*sx2y - sx2*sy) + sy*(sx*sx3 - sx2*sx2);
    double A=Da/D, B=Db/D, C=Dc/D;
    cout << "Quadratic fit:  y = " << A << " + " << B << "x + " << C << "x^2\n";

    // 3️⃣ Power model: y = a * x^b  → ln(y)=ln(a)+b ln(x)
    double Sx=0, SyL=0, SxxL=0, SxyL=0;
    for (int i=0;i<n;i++){
        double lx=log(x[i]), ly=log(y[i]);
        Sx+=lx; SyL+=ly; SxxL+=lx*lx; SxyL+=lx*ly;
    }
    double bL=(n*SxyL - Sx*SyL)/(n*SxxL - Sx*Sx);
    double aL=(SyL - bL*Sx)/n;
    double aExp=exp(aL);
    cout << "Power fit:      y = " << aExp << " * x^" << bL << "\n";

    return 0;
}
