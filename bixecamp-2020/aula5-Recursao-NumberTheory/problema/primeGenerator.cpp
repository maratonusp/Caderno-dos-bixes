#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

typedef long long ll;

vector<ll> primes;
vector<ll> is_prime(MAXN+1, true);

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i <= MAXN; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (ll j = i*i; j <= MAXN; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

void sieve_intervalado(ll l, ll r) {
    ll n = r - l + 1;
    vector<bool> aux(n, true);
    for (ll p: primes) {
        ll min = (l/p) * p;
        if (min < l) min += p;
        if (min == p) min += p;
        for (ll j = min; j <= r; j += p)
            aux[j - l] = false;
    }
    for (ll i = l; i <= r; i++)
        if (aux[i - l] && i != 1) 
            cout << i << endl;
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    sieve();
    while (t--) {
        ll m, n;
        cin >> m >> n;
        sieve_intervalado(m, n);
    }
}