#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x, y;
    cin >> n;
    set<int> xcoords, ycoords;
    map<int, set<int>> ptsx, ptsy;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        ptsx[x].insert(y);
        ptsy[y].insert(x);

        xcoords.insert(x);
        ycoords.insert(y);
    }
    int ysel, area = 0;
    for (int x : xcoords)
    {
        if (ptsx[x].size() < 2)
            continue;
        int idx = 0;
        for (int y : ycoords)
        {
            if (ptsx[x].find(y) == ptsx[x].end() || ptsy[y].size() < 2)
                continue;
            if (idx == 0) {
                ysel = y;
                idx++;
                continue;
            }
            int x1mx = INT_MIN;
            for (int x1 : ptsy[y]) {
                if (ptsy[ysel].find(x1) != ptsy[ysel].end()) {
                    x1mx = max(x1, x1mx);
                }
            }
            if (x1mx != INT_MIN) {
                area = max(area, abs(x-x1mx) * abs(y-ysel));
            }
        }
    }
    cout << area << endl;
}