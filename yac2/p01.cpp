#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, a, b, c, d;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> a >> b >> c >> d;
        double res = (double)((b-a)*(d-c))/(a*c);
        // cout << "res=" << res << endl;
        if (res > 1) 
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }

    return 0;
}