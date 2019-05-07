#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> v = {4, 1, 2, 3, 8};

	// pegar next_ ou prev_ permutation: (altera o vetor passado!)
	next_permutation(begin(v), end(v));

	for (int x : v) cout << x << " ";
	cout << "\n";

	// iterar por todas as permutacoes:
	// 1 - ordena
	sort(begin(v), end(v));
	// 2 - itera
	do {
		// usa o vetor v aqui
	} while (next_permutation(begin(v), end(v)));
	// next_ (respectivamente prev_) permutation retornam
	// false quando não há permutacao posterior (resp. anterior)

	return 0;
}