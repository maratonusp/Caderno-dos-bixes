#include <bits/stdc++.h>

using namespace std;

/*
	Título: Teste de primalidade

	Detalhes: Retorna se um número é primo ou não

	Se i é um divisor de a maior do que "raiz de a", 
	então "a / i" é um divisor de a menor que "raiz de a".

	Portanto, basta testar todos até "raiz de a"

	Complexidade: O(raiz de a)
*/

bool eh_primo(long long a){
	for(long long i = 2; i * i <= a; i++){
		if(a % i == 0) return false;
	}
	return true;
}

int main() {
	long long a, b;
	cin >> a >> b;
	
	cout << fastxp(a, b, MOD) << endl;
}	

