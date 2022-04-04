#include <bits/stdc++.h>

using namespace std;

int buyMaximumHouses(int* costOfHouses, int numberOfHouses, int budget) {
    sort(costOfHouses, costOfHouses + numberOfHouses);
    int count = 0, i = 0;
    while (i < numberOfHouses && budget >= costOfHouses[i]) {
        count++;
        budget -= costOfHouses[i];
        i++;
    }
    return count;
}

int main() {
    int testCases;
    cin >> testCases;
    for (int testCase = 1; testCase <= testCases; testCase++) {
        int numberOfHouses, budget;
        cin >> numberOfHouses;
        cin >> budget;
        int costOfHouses[numberOfHouses];
        for (int index = 0; index < numberOfHouses; index++) {
            cin >> costOfHouses[index];
        }
        int ans = buyMaximumHouses(costOfHouses, numberOfHouses, budget);
        cout << "Case #" << testCase << ": " << ans << "\n";
    }
    return 0;
}