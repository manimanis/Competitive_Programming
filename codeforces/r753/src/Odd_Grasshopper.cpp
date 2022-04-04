#ifdef ODD_GRASS_HOPPER
//============================================================================
// Name        : r753.cpp
// Author      : Mohamed Anis MANI
// Version     :
// Copyright   :
// Description : Odd Grasshopper
//============================================================================

#include <iostream>
using namespace std;

typedef long long ll;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		ll x0, n, xn;
		cin >> x0 >> n;

		if (n % 4 == 0) {
			xn = x0;
		} else if (n % 4 == 1) {
			xn = x0 + ((x0 % 2 == 0) ? -n : n);
		} else if (n % 4 == 2) {
			xn = x0 + ((x0 % 2 == 0) ? 1 : -1);
		} else {
			xn = x0 + ((x0 % 2 == 0) ? (n+1) : -(n+1));
		}
		cout << xn << endl;
	}
	return 0;
}
#endif
