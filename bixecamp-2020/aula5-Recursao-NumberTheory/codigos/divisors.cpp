#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> divi;

void divisors(ll n) {
    for (ll i = 2; i*i <= n; i++) {
        if (n%i == 0) {
            divi.push_back(i);
            ll j = n/i;
            if (j != i) divi.push_back(j);
        }
    }
    divi.push_back(n);
}

int main() {
    ll n;
    cin >> n;
    divisors(n);
    sort(divi.begin(), divi.end());
    for (ll x: divi)
        cout << x << " ";
    cout << endl;
    return 0;
}