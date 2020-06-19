//codeforces.com/contest/908/problem/C

#include "bits/stdc++.h"
using namespace std;    

int main() {

    int n, r;
    cin >> n >> r;

    int x[n];
    for (int i = 0; i < n; i++)
        cin >> x[i];

    double y[n];
    for (int i = 0; i < n; i++) {
        y[i] = double(r);

        for (int j = i-1; j >= 0; j--) {
            if (abs(x[i]-x[j]) > 2*r) continue;
            double dx = double( abs(x[i]-x[j]) );
            double dy = sqrt( 4*r*r - dx*dx );
            y[i] = max(y[i], y[j] + dy); 
        }
    }

    cout << setprecision(6) << fixed;
    for (int i = 0; i < n; i++)
        cout << y[i] << " \n"[i == n-1];       
}