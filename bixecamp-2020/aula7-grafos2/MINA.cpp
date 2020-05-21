// https://neps.academy/problem/65

#include <bits/stdc++.h>
using namespace std;

const int N = 112;

struct info {
    int x, y;
    int cost;
    bool operator< (const info& o) const {
        return cost > o.cost;
    }
};
int cost[N][N], v[N][N];

int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &v[i][j]);
        }
    }
    memset(cost, 0x5f, N * N * sizeof(int)); // colocando inf (0x5f5f5f5f) em todos os valores
    priority_queue<info> pq;
    pq.push({0, 0, 0});
    cost[0][0] = 0;
    while (pq.size()) {
        info f = pq.top();
        pq.pop();
        if (f.cost > cost[f.x][f.y])
            continue;
        for (int i = 0; i < 4; i++) {
            int x = f.x + dx[i];
            int y = f.y + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < n && cost[x][y] > f.cost + v[x][y]) {
                cost[x][y] = f.cost + v[x][y];
                pq.push({x, y, cost[x][y]});
            }
        }
    }
    printf("%d\n", cost[n-1][n-1]);
}
