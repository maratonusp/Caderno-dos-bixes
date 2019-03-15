#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000008;
bool presente[MAX];

int main() {
    for(int i = 0; i < MAX; i++) {
        presente[i] = false;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int vi;
        cin >> vi;
        presente[vi] = true;
    }

    int resp = 0;
    for (int i = 0; i < MAX; i++) {
        if(presente[i]) {
            resp++;
        }
    }
    cout << resp << endl;
}

