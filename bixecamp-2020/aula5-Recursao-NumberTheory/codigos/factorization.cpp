#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> factors;

void factorization(ll n) {
    for (ll i = 2; i*i <= n; i++) {
        while (n%i == 0) {
            factors.push_back(i);
            n = n/i;
        }
    }
    if (n > 1) factors.push_back(n);
}

int main() {
    ll n;
    cin >> n;
    factorization(n);
    for (ll x: factors)
        cout << x << " ";
    cout << endl;
    return 0;
}