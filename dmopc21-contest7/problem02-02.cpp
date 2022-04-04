#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, q, l, r, k;
    cin >> n >> q;
    stack<int> scarf, s1, s2, s3;
    for (int i = 1; i <=n; i++) {
        scarf.push(i);
    }
    for (int i = 0; i < q; i++) {
        bool foundr = false, foundk = false, foundl = false;
        cin >> l >> r >> k;
        while (!foundk && !foundr) {
            foundk = scarf.top() == k;
            foundr = scarf.top() == r;
            if (!foundk && !foundr) {
                s1.push(scarf.top());
                scarf.pop();
            }
        }
        if (foundr) {
            while (!foundl) {
                foundl = scarf.top() == l;
                s2.push(scarf.top());
                scarf.pop();
            }
            while (!foundk && !scarf.empty()) {
                foundk = scarf.top() == k;
                if (!foundk) {
                    s3.push(scarf.top());
                    scarf.pop();
                }
            }
            while (!s2.empty()) {
                scarf.push(s2.top()); s2.pop();
            }
            while (!s3.empty()) {
                scarf.push(s3.top()); s3.pop();
            }
            while (!s1.empty()) {
                scarf.push(s1.top()); s1.pop();
            }
        } else {
            while (!foundr && !scarf.empty()) {
                foundr = scarf.top() == r;
                if (!foundr) {
                    s3.push(scarf.top());
                    scarf.pop();
                }
            }
            while (!foundl) {
                foundl = scarf.top() == l;
                s2.push(scarf.top());
                scarf.pop();
            }
            while (!s3.empty()) {
                scarf.push(s3.top()); s3.pop();
            }
            while (!s2.empty()) {
                scarf.push(s2.top()); s2.pop();
            }
            while (!s1.empty()) {
                scarf.push(s1.top()); s1.pop();
            }
        }
    }
    while (!scarf.empty()) {
        s1.push(scarf.top());
        scarf.pop();
    }
    int idx = 0;
    while (!s1.empty()) {
        if (idx > 0) cout << " ";
        cout << s1.top();
        s1.pop();
        idx++;
    }
    cout << endl;
}