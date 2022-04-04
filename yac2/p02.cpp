#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, n1, v;
    cin >> n;
    vector<int> res(n + 1);
    map<pair<int, int>, int> grid;
    if (n % 2 == 0)
        n1 = n-1;
    else 
        n1 = n;
    cout << "? " << 1 << " " << n1 << endl
         << flush;
    cin >> v;
    grid[{1, n1}] = v;
    for (int i = 1; i < n; i++)
    {
        cout << "? " << i << " " << i + 1 << endl
             << flush;
        cin >> v;
        grid[{i, i + 1}] = v;
    }
    int t1n1 = 0;
    for (int i = 1; i < n; i+=2) {
        t1n1 ^= grid[{i,i+1}];
    }
    res[n] = t1n1 ^ grid[{1, n1}];
    for (int i = n-1; i >= 1; i--) {
        res[i] = res[i+1] ^ grid[{i, i+1}];
    }
    cout << "!";
    for (int i = 1; i <= n; i++)
        cout << " " << res[i];
    cout << endl;
    return 0;
}