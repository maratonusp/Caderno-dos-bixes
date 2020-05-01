#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool primo(ll n) {
    for (int i = 2; i*i <= n; i++) {
        if (n%i == 0) return false;
    }
    return true;
}

int main() {
    ll n;
    cin >> n;
    cout << primo(n) << endl;
    return 0;
}