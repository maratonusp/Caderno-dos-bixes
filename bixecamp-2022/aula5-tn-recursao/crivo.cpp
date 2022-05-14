#include <bits/stdc++.h>

using namespace std;

/*
	Título: Crivo de Erastótenes

	Detalhes: Encontra todos os primos de 1 até N
	
	Complexidade: O( N log (log N) )

	
	Link útil: https://www.youtube.com/watch?v=r41zHGnv7co
	
		- Tem uma maneira de fazer em O(N): 
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

int main(){
	crivo();
	int lim;
	cin >> lim;
	for(int i = 1; i < lim; i++){
		if(eh_primo[i]) 
			cout << i << endl;
	}
}



















































