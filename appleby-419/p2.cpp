#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, l;
    string love;
    cin >> n >> l;
    cin.ignore();
    getline(cin, love);
    for (char car : love) {
        cout << (char)((car == ' ') ? ' ' : ((car - 'a' + l) % 26 + 'a'));
    }
    cout << endl;
    return 0;
}