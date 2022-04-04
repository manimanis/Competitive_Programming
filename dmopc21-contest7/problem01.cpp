#include <bits/stdc++.h>

using namespace std;

void print(vector<vector<int>> grid) {
    for (vector<int> vect : grid) {
        for (int i = 0; i< vect.size(); i++) {
            if (i > 0) cout << " ";
            cout << vect[i];
        }
        cout << endl;
    }
}

int main() {
    int n, m, rowmin, colmin;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            rowmin = 0;
        } else {
            rowmin = grid[i-1][0];
        }
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) {
                rowmin = rowmin + 1;
                if (i == 0 || j == 0) {
                    grid[i][j] = rowmin;
                } else {
                    grid[i][j] = max(grid[i][j-1], grid[i-1][j])+1;
                }
            } else {
                rowmin = grid[i][j];
            }
        }
    }
    bool valid = true;
    for (int i = 0; valid && i < n; i++) {
        for (int j = 0; valid && j < m; j++) {
            if (i == 0 && j == 0) {
                continue;
            } else if (i == 0 && j > 0) {
                valid = grid[i][j] > grid[i][j-1];
            } else if (j == 0 && i > 0) {
                valid = grid[i][j] > grid[i-1][j];
            } else {
                valid = grid[i][j] > max(grid[i][j-1], grid[i-1][j]);
            }
        }
    }
    if (valid)
        print(grid);
    else
        cout << -1 << endl;
}