#include <bits/stdc++.h>

using namespace std;

string add(string a, string b, int pa=0, int pb=0) {
    a = a + ((pa == 0) ? "" : string(pa, '0'));
    b = b + ((pb == 0) ? "" : string(pb, '0'));
    int na = a.length(), nb = b.length(), ns = max(na, nb)+1;
    string s(ns, '0');
    int i = na-1, j = nb-1, k = ns-1, carry = 0, ds;
    while (carry > 0 || i >= 0 || j >= 0) {
        ds = carry;
        if (i >= 0) ds += (a[i] - '0');
        if (j >= 0) ds += (b[j] - '0');
        if (ds <= 9) {
            s[k] = (ds + '0');
            carry = 0;
        } else {
            s[k] = ((ds - 10) + '0');
            carry = 1;
        }
        i--; j--; k--;
    }
    i = 0;
    while (i+1 < ns && s[i] == '0') i++;
    return (i > 0) ? s.substr(i) : s;
}

string sub(string a, string b) {
    int sn1 = a.length() - 1, 
        sn2 = b.length() - 1,
        sr = max(sn1, sn2),
        carry = 0;
    string res(max(sn1+1, sn2+1), '0');
    while (sr >= 0) {
        int s = -carry;
        if (sn1 >= 0) {
            s += (a[sn1] - 48);
        }
        if (sn2 >= 0) {
            s -= (b[sn2] - 48);
        }
        if (s < 0) {
            s += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        res[sr] = (char)(s + 48);
        sr--; sn1--; sn2--;
    }
    return res; 
}

string multiply(string a, string b) {
    int na = a.length(), nb = b.length();
    if (na <= 9 && nb <= 9) {
        return to_string(stol(a) * stol(b));
    }
    int p = max(na, nb) / 2;
    string a1 = (na <= p) ? "0" : a.substr(0, na-p);
    string a2 = (na <= p) ? a : a.substr(na-p, p);
    string b1 = (nb <= p) ? "0" : b.substr(0, nb-p);
    string b2 = (nb <= p) ? b : b.substr(nb-p, p);
    // cout << a1 << " " << a2 << endl;
    // cout << b1 << " " << b2 << endl;
    string a1b1 = multiply(a1, b1);
    string a2b2 = multiply(a2, b2);
    string a1b2_a2b1 = multiply(add(a1, a2), add(b1, b2));
    a1b2_a2b1 = sub(sub(a1b2_a2b1, a1b1), a2b2);
    
    string res = add(a1b1, a2b2, 2*p, 0);
    res = add(res, a1b2_a2b1, 0, p);
    return res;
}

int main() {
    string a;
    string b;
    //cin.ignore();
    getline(cin, a);
    getline(cin, b);
    cout << multiply(a, b) << endl;
}

/*
input:
123456123456123456123456123456123456
987987876876765765654654543543432432321321
output:
121973153300851295215956247283945278187966162014464020099359068031370037005376
input:
111111111
111111111
output:
12345678987654321
*/