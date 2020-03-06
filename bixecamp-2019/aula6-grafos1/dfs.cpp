#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000 //Número de vértices do grafo

vector<int> adj[MAXN]; //vetor de adjacências

int pai[MAX]; //array que guarda os pais de cada nó

void dfs(int v){
	for(auto x: adj[v]){
		if(pai[x] != -1) continue; //se o nó já tem pai significa que já o visitei
		pai[x] = v; //seto o pai do nó para o atual
		dfs(x); //chama a função para o nó
	}
}

int main(){

	for(int i = 0; i < MAX; i++) pai[i] = -1; //inicializo o array de pais com -1 para todos
	int root = 0; //valor da raíz
	pai[root] = root; //a raíz do meu grafo deve ser o próprio pai, para que não chame a dfs para ela

}