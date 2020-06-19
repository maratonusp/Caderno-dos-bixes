//www.urionlinejudge.com.br/judge/en/problems/view/2665

#include "bits/stdc++.h"
using namespace std;

// definindo um ponto
typedef pair<int, int> point;
#define y first
#define x second

// testa se o ponto c esta a esquerda da reta a->b
int is_left(point a, point b, point c) {
    int det = (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
    if (det > 0) return 1;  // c esta a esquerda
    if (det < 0) return -1; // c esta a direita
    return 0;               // c é colinear
}

int main() {

    int n, xa, xb;
    cin >> n >> xa >> xb;

    point pt[n];
    for (int i = 0; i < n; i++)
        cin >> pt[i].x >> pt[i].y;

    sort(pt, pt+n);
    point pa = point(0, xa);
    point pb = point(0, xb);
    int memo[n], ans = 0;

    for (int i = 0; i < n; i++) {
        memo[i] = 1;
        for (int j = i-1; j >= 0; j--) 
            if (is_left(pt[i], pa, pt[j]) == 1 && is_left(pb, pt[i], pt[j]) == 1) 
                memo[i] = max(memo[i], memo[j]+1);
        ans = max(ans, memo[i]);
    }

    cout << ans << endl;
}