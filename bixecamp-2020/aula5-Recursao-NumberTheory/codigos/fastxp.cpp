#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1000000007;


ll pot(ll a, ll n) {
    if (n == 0) return 1;
    ll metade = pot(a, n/2);
    ll ans = (metade*metade)%MOD;
    if (n%2 == 1) ans = (ans*a)%MOD;
    return ans;
}

int main() {
    ll a, n;
    cin >> a >> n;
    cout << pot(a, n) << endl;
    return 0;
}