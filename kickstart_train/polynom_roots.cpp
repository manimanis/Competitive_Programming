#include <bits/stdc++.h>

using namespace std;

double polynom(int n, double* coef, double x) {
    double s = 0.0, px = 1.0;
    for (int i = 0; i <= n; i++) {
        s += coef[i] * px;
        px *= x;
    }
    return s;
}

int main() {
    int n;
    double coef[6];
    
    cout.precision(16);

    cin >> n;
    for (int i = n; i >= 0; i--) {
        cin >> coef[i];
    }
    double a = -1, b = 1, eps = 1e-6, mid;
    while (polynom(n, coef, a) * polynom(n, coef, b) > 0) {
        a *= 10;
        b *= 10;
    }
    double fa = polynom(n, coef, a), fm;
    while (abs(b-a)/2 >= eps) {
        mid = (a + b) / 2;
        fm = polynom(n, coef, mid);
        // cout << a << " " << b << " " << fm << endl;
        if (fa * fm < 0) {
            b = mid;
        } else {
            a = mid;
        }
    }
    cout << mid;
}