#include <bits/stdc++.h>
using namespace std;

int main() {
    int m[4][6];
    m[0][0] = -1;
    m[1][0] = 33;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            m[i][j] = i+j;
        }
    }
}

