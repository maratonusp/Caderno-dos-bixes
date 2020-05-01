#include <bits/stdc++.h>
using namespace std;

#define V 100 // número máximo de vértices

int pai[V];
bool visitado[V]; // vetor que indica os vértices visitados
vector<int> adj[V]; // vetor de adjacências

void dfsUtil(int v) {
	visitado[v] = true; // marca como visitado
	// for (int av : adj[v])  também é possivel usar essa sintaxe
	for (int a = 0; a < adj[v].size(); a++) { 
		int av = adj[v][a];
		if (!visitado[av]) {
			cout << av << " "; // imprime o vértice adjacente
			dfsUtil(av); // chama dfs para o vértice adjacente não visitado
			pai[av] = v; // salva o pai do vértice av
		}
	}
}

void dfs(int r, int v) {
	for (int i = 0; i < v; i++) {
		visitado[i] = false;
		pai[i] = -1;
	}
	cout << r << " ";
	dfsUtil(r);
	cout << "\n";
}

int main() {
	int v, a;
	cin >> v >> a;
	for (int i = 0; i < a; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(0, v);
	for (int i = 0; i < v; i++) {
		cout << "pai de " << i << " = " << pai[i] << "\n";
	}
	return 0;
}