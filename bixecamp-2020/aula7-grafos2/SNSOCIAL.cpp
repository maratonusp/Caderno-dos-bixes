// https://www.codechef.com/problems/SNSOCIAL

#include <bits/stdc++.h>
using namespace std;

const int N = 512;

int dist[N][N], v[N][N];
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

// só pra facilitar guardar os dois valores
struct pos {
    int x, y;
};

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, m; scanf("%d %d", &n, &m);
        int mx = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &v[i][j]);
                mx = max(mx, v[i][j]);
            }
        }
        memset(dist, -1, N * N * sizeof(int));
        queue<pos> q;
        /* dado como a BFS funciona, a gente consegue colocar vários vértices iniciais na fila
         * ao mesmo tempo, e a BFS vai encontrar o menor caminho pra um desses vértices */
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] == mx) {
                    pos p;
                    p.x = i;
                    p.y = j;
                    q.push(p);
                    dist[i][j] = 0;
                }
            }
        }
        while (q.size()) {
            pos p = q.front();
            q.pop();
            for (int i = 0; i < 8; i++) {
                int x = p.x + dx[i];
                int y = p.y + dy[i];
                if (x >= 0 && x < n && y >= 0 && y < m && dist[x][y] == -1) {
                    dist[x][y] = dist[p.x][p.y] + 1;
                    q.push({x, y});
                }
            }
        }
        int resp = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                resp = max(resp, dist[i][j]);
            }
        }
        printf("%d\n", resp);
    }
}
