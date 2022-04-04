#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, v;
    unsigned int s = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v;
        s += v;
    }
    cout << setprecision(5) << (double)s/n << endl;
    return 0;
}