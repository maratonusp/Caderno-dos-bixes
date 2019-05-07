#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> v = {1, 4, 6, 8};

	// lower_bound e upper_bound requerem que o vetor/array esteja ordenado
	// iterador para o primeiro elemento >= 3
	auto it = lower_bound(begin(v), end(v), 3);

	// removendo o intervalo [1, 3) do vetor
	v.erase(v.begin() + 1, v.begin() + 3);
	// for (int x : v) cout << x << endl;

	// removendo elementos repetidos (ordena -> unique -> erase)
	vector<int> u = {1, 4, 1, 5, 6};
	sort(begin(u), end(u));

	auto it2 = unique(begin(u), end(u));
	for (int x : u) cout << x << endl;
	u.erase(it2, u.end());
	for (int x : u) cout << x << endl;

	return 0;
}