#include <bits/stdc++.h>

using namespace std;

/*
	Título: Inverso multiplicativo

	Detalhes: Seja 'p' primo e 'a' que não é múltiplo de p
	Retorna x tal que a * x = 1 (mod p)
	
	Pelo Teorema de Fermat, sabemos que a^{p - 1} = 1 (mod p)
	Então, a * a^{p - 2} = 1 (mod p).
	Portanto, faça x = a ^ {p - 2} (mod p)

	Complexidade: O( (log p) )

	Link útil: 
		- Pequeno Teorema de Fermat: https://www.youtube.com/watch?v=q0azW4TyGV0
		- Pra quem quiser aprofundar: https://cp-algorithms.com/algebra/module-inverse.html
*/


long long fastxp(long long b, long long e, long long m){
	if(e == 0) return 1;
	
	long long resp = fastxp(b, e / 2, m);
	resp = resp * resp % m;
	
	if(e%2 == 1) resp = resp * b % m;
	
	return resp;
}

// Seja 'p' primo e 'a' que não é múltiplo de p
// Retorna x tal que a * x = 1 (mod p)
// O( log p )
long long inverso(long long a, long long p){
	return fastxp(a, p - 2, p) % p;
}

int main() {
	long long a, p;
	cin >> a >> p;
	
	cout << inverso(a, p) << endl;
}	

