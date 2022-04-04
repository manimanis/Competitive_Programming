#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<string> forms(n+1, "");
    for (int i = 0; i < q; i++) {
        string qt, qf; 
        int index;
        cin >> qt >> qf >> index;
        if (qt == "set") {
            forms[index] = qf;
        } else if (qt == "get") {
            cout << (forms[index] == qf) << endl;
        }
    }
}