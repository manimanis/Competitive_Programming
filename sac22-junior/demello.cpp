#include <bits/stdc++.h>

using namespace std;

int main() {
    string w;
    string vowels = "oiyeau";
    int vowelsCount = 0;
    cin >> w;
    for (char car : w) {
        if (vowels.find(car) != -1) {
            vowelsCount++;
        }
    }
    cout << ((vowelsCount >= 2) ? "good" : "bad") << endl;
}