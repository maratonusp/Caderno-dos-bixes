#include <bits/stdc++.h>
using namespace std;

int x = 0;

int expo(int base, int exp) {
    x = x+1;
    int resp = 1;
    while(exp > 0) {
        resp = resp * base;
        exp = exp - 1;
    }
    cout << "Em expo, exp vale = " << exp << endl;
    return resp;
}

int main() {
    x = x+1;
    int base = 3;
    int exp = 4;
    cout << expo(base, exp) + expo(exp, base) << endl;
    cout << "Em main, exp vale = " << exp << endl;

    cout << "x = " << x << endl;
}

