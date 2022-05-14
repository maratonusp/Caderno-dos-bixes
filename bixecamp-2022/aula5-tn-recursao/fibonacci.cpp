#include <bits/stdc++.h>

using namespace std;


/*
	Título: Sequência de Fibonacci

	Detalhes: 
		A sequência de Fibonacci (F_i) é definida da seguinte maneira:
		
		F_0 = 0, F_1 = 1
		Para i > 1, F_i = F_{i - 1} + F_{i - 2}

	Link útil: https://pt.wikipedia.org/wiki/Sequ%C3%AAncia_de_Fibonacci
*/


// Retorna F_n
long long fib(long long n){
	if(n == 0) return 0;
	if(n == 1) return 1;
	
	return fib(n - 1) + fib(n - 2);
}
int main() {
	long long n;
	cin >> n;
	
	cout << fib(n) << endl;
}	
