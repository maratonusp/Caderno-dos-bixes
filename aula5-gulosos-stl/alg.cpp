#include <bits/stdc++.h>

using namespace std;

int a[] = {4, 3, 2, 1, 5};

int main() {
	// ordenando array
	sort(a, a+5);

	for (int i = 0; i < 5; i++) cout << a[i] << " ";
	cout << "\n";

	// ordenando vector
	vector<int> v = {3, 1, 2, 4};
	sort(v.rbegin(), v.rend());

	for (int x : v) cout << x << endl;
	
	// invertendo a ordem dos elementos
	reverse(v.begin(), v.end());

	// iterador pro maior/menor elemento
	auto it = max_element(v.begin(), v.end());
	/*min_element*/

	// contar quantos elementos sao iguais a 2, tempo linear
	int qt = count(v.begin(), v.end(), 2);

	// se estiver ordenado, tempo log
	qt = upper_bound(v.begin(), v.end(), 2) - lower_bound(v.begin(), v.end(), 2);


	return 0;
}