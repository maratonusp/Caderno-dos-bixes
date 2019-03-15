#include <bits/stdc++.h>
using namespace std;

int main() {
    int unicos[100005];
    int n, qt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        // 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8.... + n ~= n^2
        int vi;
        cin >> vi;
        bool apareceu = false;
        for (int j = 0; j < qt; j++) {
            if(unicos[j] == vi) {
                apareceu = true;
                break;
            }
        }
        if (apareceu == false) {
            unicos[qt] = vi;
            qt = qt + 1;
        }
    }
    cout << qt << endl;

}

