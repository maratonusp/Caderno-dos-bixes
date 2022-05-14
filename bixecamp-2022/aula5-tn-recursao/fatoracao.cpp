#include <bits/stdc++.h>

using namespace std;



/*
	Título: Fatoração em primos de um número

	Detalhes: Todo número tem uma fatoração em primos única
	Por exemplo, 120 = (2^3) * (3^1) * (5^1)

	A função retorna uma lista de pares {primo, expoente}.
	No caso do 120, ela retornaria {{2, 3}, {3, 1}, {5, 1}}

	Para isso, eu também preciso do Crivo de Erastótenes

	Complexidade: O(raiz de a + |quantidade de primos|)
		-> Na verdade é um pouco melhor...

	Links úteis:
		Usando o crivo linear dá pra fazer em O(log a)
		https://cp-algorithms.com/algebra/prime-sieve-linear.html
*/

const int N = 1000010;
bool eh_primo[N];
vector<int> primos;

void crivo(){
	for(int i = 2; i < N; i++){
		eh_primo[i] = true;
	}
		
	for(int i = 2; i < N; i++){
		if(eh_primo[i]){
			primos.push_back(i);
			
			for(int j = 2; j * i < N; j++){
				eh_primo[j * i] = false;
			}
		}
	}
}


vector<pair<int, int>> fatoracao(long long n){
	int i = 0;
	vector<pair<int, int>> resp;
	while(i < primos.size() && primos[i] * primos[i] <= n){
		if(n % primos[i] == 0){
			int e = 0;
			while(n % primos[i] == 0){
				n /= primos[i];
				e++;
			}
				
			resp.push_back({primos[i], e});
		}
		
		i++;
	}
	
	if(n > 1){
		resp.push_back({n, 1});
	}
	
	return resp;
}

int main(){
	crivo();

	long long n;
	cin >> n;
	vector<pair<int, int>> fat = fatoracao(n);
	for(pair<int, int> p : fat){
		cout << p.first << " " << p.second << endl;
 	}
}



















































