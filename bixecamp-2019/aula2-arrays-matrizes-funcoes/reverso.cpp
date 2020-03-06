#include <bits/stdc++.h>
using namespace std;

int main() {
    int v[1002];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++) {
        cout << v[n-i-1] << endl;
    }
}

