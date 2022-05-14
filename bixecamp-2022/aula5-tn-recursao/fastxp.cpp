#include <bits/stdc++.h>

using namespace std;

/*
	Título: Exponenciação rápida

	Detalhes: Retorna o valor ( b^e (mod m) )
	
	Complexidade: O( (log e) )

	Link útil: https://www.youtube.com/watch?v=5_KawI8rQSc
		-> Essa aula é bem mais extensa e utiliza algumas técnicas
		matemáticas mais avançadas
*/


// Retorna b^e (mod m)
// Complexidade: O(log e)
long long fastxp(long long b, long long e, long long m){
	if(e == 0) return 1;
	
	long long resp = fastxp(b, e / 2, m);
	resp = resp * resp % m;
	
	if(e%2 == 1) resp = resp * b % m;
	
	return resp;
}

int main() {
	long long a, b;
	cin >> a >> b;
	
	cout << fastxp(a, b, MOD) << endl;
}	

