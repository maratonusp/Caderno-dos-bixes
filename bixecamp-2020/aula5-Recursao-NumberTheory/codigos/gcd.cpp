#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// (condição) ? (a) : (b)

ll gcd(ll a, ll b) {
    return (b == 0) ? a : gcd(b, a%b);
}

int main() {
    ll a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    cout << __gcd(a, b) << endl;
    return 0;
}