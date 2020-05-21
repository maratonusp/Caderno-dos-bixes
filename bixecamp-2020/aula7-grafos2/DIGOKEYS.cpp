// https://www.spoj.com/problems/DIGOKEYS/

#include <bits/stdc++.h>
using namespace std;

const int N = 112345;

vector<int> adj[N]; // adj[i] = todas as caixas que eu consigo abrir a partir de i
int dist[N]; // dist[v] = menor caminho até v
int p[N]; // p[v] = u significa que v foi "descoberto" na BFS a partir de u

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }
        for (int i = 1; i < n; i++) {
            int m; scanf("%d", &m);
            while (m--) {
                int k; scanf("%d", &k);
                adj[i].push_back(k);
            }
            /* o problema quer a menor rota, desempatando pela menor lexograficamente
             * se eu ordenar a lista de adjacência eu vou olhar os caminhos na ordem
             * lexografica, e quando achar o menor ele vai ser o menor lexograficamente tbm. */
            sort(adj[i].begin(), adj[i].end());
        }
        memset(dist, -1, N * sizeof(int));
        queue<int> q;
        q.push(1);
        dist[1] = 0;
        p[1] = -1;
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (auto v: adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    p[v] = u;
                    q.push(v);
                }
            }
        }
        printf("%d\n", dist[n]);
        if (dist[n] != -1) {
            vector<int> path;
            /* aqui eu pego o caminho até a caixa n, basta começar nela e ir "subindo" pela lista
             * p (i.e. p[n], p[p[n]], ...) até encontrar o pai do 1, que é -1 */
            while (p[n] != -1) {
                n = p[n];
                path.push_back(n);
            }
            // esse caminho tá ao contrário, essa função aqui inverte ele, c++ tem várias coisas prontas
            reverse(path.begin(), path.end());
            for (auto u: path) {
                printf("%d ", u);
            } printf("\n");
        }
    }
}
