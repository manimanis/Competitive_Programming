#include <bits/stdc++.h>

#define PI 3.141592653589793238462643383279502884L

using namespace std;

class Vector
{
public:
    double angle;
    int idx;
    Vector(double px, double py, int pidx): idx(pidx) {
        angle = atan2(py, px);
    }
    Vector(int pangle, int pidx): idx(pidx), angle(pangle * PI / 180.0) { 
        angle = (angle <= PI) ? angle : (angle - 2 * PI);
    }

    friend ostream& operator<<(ostream& stream, const Vector& vect) {
        stream << vect.idx << ":(" << vect.angle << ")";
        return stream;
    }
};

int main()
{
    int n, a;
    vector<Vector> vectors;
    cin >> n >> a;
    vectors.push_back(Vector(a, 0));
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        vectors.push_back(Vector(x, y, i + 1));
    }
    // for (int i = 0; i <= n; i++) {
    //     cout << vectors[i] << endl;
    // }
    int minp = 1; 
    double da, minda = abs(vectors[0].angle - vectors[1].angle);
    for (int i = 2; i <= n; i++) {
        da = abs(vectors[0].angle - vectors[i].angle);
        if (abs(da) < abs(minda)) {
            minda = da;
            minp = i;
        }
    }
    cout << vectors[minp].idx << endl;
}