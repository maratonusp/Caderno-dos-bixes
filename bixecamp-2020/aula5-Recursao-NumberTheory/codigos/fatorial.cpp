#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll fatorial(ll n) {
    if (n == 0) return 1;
    return n*fatorial(n-1);
}

int main() {
    ll n;
    cin >> n;
    cout << fatorial(n) << endl;
    return 0;
}