/* Código da BFS
   Bixe Camp 2019 - Aula 7	

*/
#include "bits/stdc++.h"
using namespace std;

#define 1001000  MAXV
#define pair<int,int> pii;

int n,distancia[MAXV];
vector<pii> adj[MAXV];

void BFS(int fonte){
	for(int i=0;i<MAXV;i++)//Marca os vértices como não visitados
		distancia[i]=-1;

	queue<int> fila;
	fila.push(fonte);//Insere a fonte na fila
	distancia[fonte]=0;//Iniciando a distancia da fonte como zero	

	int aux;
	while(!fila.empty()){
		aux=fila.front();//Pega o primeiro elemento da fila
		fila.pop();//Apaga o primeiro elemento da fila
	
		for(auto viz:adj[aux]){
			if(distancia[viz]!=-1)//Se foi visitado, não adiciona na fila
				continue;
			
			distancia[viz]=distancia[aux]+1;
			fila.insert(viz);
		}
	}

}