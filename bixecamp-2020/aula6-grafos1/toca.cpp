#include <bits/stdc++.h>
using namespace std;

#define V 1010

int dist[V][V];
int mat[V][V];
int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};
int n, m;

void dfs(int i, int j) {
	for (int k = 0; k < 4; k++) {
		int ai = i + di[k];
		int aj = j + dj[k];
		if (ai >= 0 && ai < n && aj >= 0 && aj < m && dist[ai][aj] == -1 && mat[ai][aj] != 0) {
			dist[ai][aj] = dist[i][j] + 1;
			dfs(ai, aj);
		} 
	}
}

int main() {
	int ai, aj;
	int ei, ej;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 2) {
				ai = i;
				aj = j;
			} else if (mat[i][j] == 3) {
				ei = i;
				ej = j;
			}
			dist[i][j] = -1;
		}
	}

	dist[ai][aj] = 1;
	dfs(ai, aj);

	cout << dist[ei][ej] << "\n";

	return 0;
}