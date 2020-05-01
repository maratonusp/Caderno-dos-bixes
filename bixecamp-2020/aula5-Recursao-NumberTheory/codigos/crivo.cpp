#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100005;

vector<ll> primes;
vector<bool> is_prime(MAXN+1, true);

void crivo(ll n) {
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (ll j = i*i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}

int main() {
    ll n;
    cin >> n;
    crivo(n);
    for (ll x: primes)
        cout << x << " ";
    cout << endl;
    return 0;
}