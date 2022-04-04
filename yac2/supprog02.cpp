#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 3;
    srand(time(NULL));
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 25;
    }
    for (int i = 0; i < n; i++) cout << v[i] << ", ";
    cout << endl;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        int val = v[i];
        for (int j = i+1; j < n; j++) {
            val ^= v[j];
            grid[i][j] = val;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}