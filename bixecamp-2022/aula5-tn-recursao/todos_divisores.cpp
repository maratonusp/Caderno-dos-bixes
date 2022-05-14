#include <bits/stdc++.h>

using namespace std;

/*
	Título: Todos os divisores

	Detalhes: Retorna uma lista com todos os divisores de a

	Se i é um divisor de a maior do que "raiz de a", 
	então "a / i" é um divisor de a menor que "raiz de a".

	Portanto, basta passar por todos até "raiz de a"

	Complexidade: O(raiz de a)
*/
vector<long long> all_divisors(long long a){
	vector<long long> resp;
	
	for(long long i = 1; i * i <= a; i++){
		if(a % i == 0) {
			resp.push_back(i);
			if(i * i < a) resp.push_back(a / i);
		}
	}
	return resp;
}

int main() {
	long long n;
	cin >> n;
	
	vector<long long> v = all_divisors(n);
	for(long long d : v) {
		cout << d << " ";
	}
	cout << endl;
}	

