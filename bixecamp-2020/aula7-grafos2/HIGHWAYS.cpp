// https://www.spoj.com/problems/HIGHWAYS/

#include <bits/stdc++.h>
using namespace std;

const int N = 112345;

/* cada aresta precisa de duas informações, o vértice final e o custo dessa aresta
 * essa struct guarda essas duas informações e também tem o operador <. Esse
 * operador vai deixar a priority queue ordenar as informações corretamente do
 * maior custo pro menor. */
struct edge {
    int v, cost;
    bool operator< (const edge &o) const {
        return cost > o.cost;
    }
};
vector<edge> adj[N];
// cost[v] = menor distância até o vértice v
int cost[N];

int main() {
    int tt; scanf("%d", &tt);
    while (tt--) {
        int n, m, s, t; scanf("%d %d %d %d", &n, &m, &s, &t);
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            cost[i] = numeric_limits<int>::max();
        }
        for (int i = 0; i < m; i++) {
            int u, v, c; scanf("%d %d %d", &u, &v, &c);
            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
        }
        /* eu poderia usar um set aqui, basta mudar o nome das funções e mudar
         * a função de comparação pra ordenar do menor para o maior e usar o
         * valor de v na hora de comparar. */
        priority_queue<edge> pq;
        pq.push({s, 0});
        cost[s] = 0;
        while (pq.size()) {
            edge p = pq.top();
            pq.pop();
            /* eu posso acabar adicionando o mesmo vértice várias vezes na
             * priority queue, se isso acontecer, aqui eu noto que eu já
             * calculei a distância dele e ignoro */
            if (p.cost > cost[p.v])
                continue;
            for (auto e: adj[p.v]) {
                if (cost[e.v] > p.cost + e.cost) {
                    cost[e.v] = p.cost + e.cost;
                    pq.push({e.v, cost[e.v]});
                }
            }
        }
        if (cost[t] == numeric_limits<int>::max()) {
            printf("NONE\n");
        } else {
            printf("%d\n", cost[t]);
        }
    }
}
