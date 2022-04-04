#define Minimum_Extraction

#ifdef Minimum_Extraction
//============================================================================
// Name        : r753.cpp
// Author      : Mohamed Anis MANI
// Version     :
// Copyright   :
// Description : LMinimum_Extraction
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stl_function.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		if (n == 1) {
			cout << a[0] << endl;
		} else {
			sort(a.begin(), a.end());
			int gmn = a[0], s = gmn, i = 1;
			while (i < n) {
				a[i] -= s;
				if (a[i] > gmn) {
					gmn = a[i];
				}
				s += a[i];
				i++;
			}
			cout << gmn << endl;
		}
	}
	return 0;
}
#endif
