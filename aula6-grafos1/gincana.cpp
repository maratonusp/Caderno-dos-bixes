#include <bits/stdc++.h>
using namespace std;

#define V 1010

bool visitado[V];
vector<int> adj[V];

void dfs(int r) {
	visitado[r] = true;
	for (int va : adj[r]) {
		if (!visitado[va]) {
			dfs(va);
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int nTimes = 0;
	for (int i = 0; i < n; i++) {
		if (!visitado[i]) {
			nTimes++;
			dfs(i);
		}
	}
	cout << nTimes << endl;

	return 0;
}