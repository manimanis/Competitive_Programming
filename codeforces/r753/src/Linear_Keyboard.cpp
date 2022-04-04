//============================================================================
// Name        : r753.cpp
// Author      : Mohamed Anis MANI
// Version     :
// Copyright   : 
// Description : Linear Keyboard
//============================================================================

#include <iostream>
using namespace std;

#ifdef LINEAR_KEYBOARD
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string keyboard, s;
		cin >> keyboard;
		cin >> s;

		int lastPos = -1;
		int sum = 0;
		for (char c : s) {
			int pos = keyboard.find(c);
			if (lastPos == -1) {
				lastPos = pos;
			}
			sum += abs(pos - lastPos);
			lastPos = pos;
		}
		cout << sum << endl;
	}
	return 0;
}
#endif
