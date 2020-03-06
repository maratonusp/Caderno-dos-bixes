#include <bits/stdc++.h>
using namespace std;

int soma(int v[]) {
    v[3] = 99;
    return v[3];
}

int main() {
    int v[5];
    for(int i = 0; i < 5; i++)
        v[i] = -i;
    cout << soma(v) << endl;
    cout << v[3] << endl;
}

