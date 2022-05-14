#include <bits/stdc++.h>

using namespace std;

/*
	Título: Exponenciação rápida de matriz

	Detalhes: Retorna a matriz ( a^e )
	
	Complexidade: O( (log e) * |a|^3 )

	Link útil: https://www.youtube.com/watch?v=5_KawI8rQSc
		-> Essa aula é bem mais extensa e utiliza algumas técnicas
		matemáticas mais avançadas
*/


#define matriz vector<vector<long long>>
#define MOD 1000000007

matriz multiplica(matriz a, matriz b, int tam){
	matriz resp(tam, vector<long long>(tam, 0));
	
	for(int i = 0; i < tam; i++){
		for(int j = 0; j < tam; j++){
			for(int k = 0; k < tam; k++){
				resp[i][j] = (resp[i][j] + a[i][k] * b[k][j]) % MOD;
			}
		}	
	}
	return resp;
}
matriz fastxp(matriz b, int e, int tam){
	if(e == 1) return b;
	
	matriz resp = fastxp(b, e / 2, tam);
	resp = multiplica(resp, resp, tam);
	
	if(e%2 == 1) resp = multiplica(resp, b, tam);
	
	return resp;
}

int main() {
	matriz m = {{1, 1}, {1, 0}};
	m = fastxp(m, 5, 2);

	cout << m[0][0] << " " << m[0][1] << endl;
	cout << m[1][0] << " " << m[1][1] << endl;
}	

