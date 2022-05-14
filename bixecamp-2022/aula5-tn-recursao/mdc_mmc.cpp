#include <bits/stdc++.h>

using namespace std;

/*
	Título: Máximo divisor comum

	Detalhes: Retorna o mdc(a, b)

		Lema 1: mdc(a, b) = mdc(a % b, b)

	Quem quiser ver a prova desse Lema, só mandar no grupo.
	Usando fortemente esse lema, a função faz o que se pede

	O gcc tem uma função pré-implementada chamada __gcd(a, b),
	então não há necessidade de coda. No entanto, recomendo 
	fortemente entenderem o que o código faz.

	Complexidade: O( max(a, b) )

	Link útil: https://cp-algorithms.com/algebra/euclid-algorithm.html
*/


long long mdc(long long a, long long b){
	if(b == 0) return a;
	return mdc(b, a % b);
}


/*
	Título: Mínimo múltiplo comum

	Detalhes: Retorna o mmc(a, b)

		Lema 2: mdc(a, b) * mmc(a, b) = a * b

	Quem quiser ver a prova desse Lema, só mandar no grupo.
	Isolando mmc(a, b) = a * b / mdc(a, b)

	A partir do c++17, tem uma função pré-implementada chamada 
	lcm(a, b).No entanto, recomendo fortemente entenderem o que 
	o código faz, pois dependendo do compilador não vai ter ela

	Complexidade: O( max(a, b) )

*/

long long mmc(long long a, long long b){
	return a * b / mdc(a, b);
}

int main() {
	long long a, b;
	cin >> a >> b;
	
	cout << mdc(a, b) << endl;
	cout << __gcd(a, b) << endl;

	cout << mmc(a, b) << endl;
	
	// cout << lcm(a, b) << endl;   É compilador >= g++17 ?
}
	
