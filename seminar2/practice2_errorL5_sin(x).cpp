#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

double deg2rad(double d) { return d * M_PI / 180.0; }

int main() {
    cout << "\n========== PRACTICE 2: ERROR OF L5(x) FOR sin(x) ==========\n";

    vector<double> xdeg = {0, 5, 10, 15, 20, 25};
    vector<double> y;
    for (double d : xdeg)
        y.push_back(sin(deg2rad(d)));

    double x = 12.5; // 12°30′
    double L5 = 0;
    for (int i = 0; i < 6; ++i) {
        double term = y[i];
        for (int j = 0; j < 6; ++j)
            if (i != j)
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

    return 0;
}
