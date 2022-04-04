#include <bits/stdc++.h>

using namespace std;

void eatSpaces(string& exp, int& pos) {
    while (pos < exp.length() && exp[pos] == ' ') pos++;
}

int parseInt(string& exp, int& pos) {
    int v = 0;
    while (pos < exp.length() && exp[pos] >= '0' && exp[pos] <= '9') {
        v = v * 10 + (exp[pos] - '0');
        pos++;
    }
    return v;
}

int evaluate(string& exp, int& pos) {
    char op;
    int a, b;
    if (exp[pos] == '(') {
        op = exp[pos+1];
        pos += 2;
        eatSpaces(exp, pos);
        a = evaluate(exp, pos);
        eatSpaces(exp, pos);
        b = evaluate(exp, pos);
        pos++;
        int res = ((op == '+') ? (a+b) : (a-b));
        // cout << a << op << b << "=" << res << endl;
        return res;
    } else if (exp[pos] >= '0' && exp[pos] <= '9') {
        return parseInt(exp, pos);
    } else if (exp[pos] == '-') {
        pos++;
        return -parseInt(exp, pos);
    }
    return 0;
}

int main() {
    string expression;
    int pos = 0;
    getline(cin, expression);
    cout << evaluate(expression, pos) << endl;
    return 0;
}