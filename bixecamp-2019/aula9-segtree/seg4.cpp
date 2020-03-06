/*

Merge Sort Tree:

Permite contar quantos elementos do intervalo
[ql, qr] possuem valor em [a, b]

Ideia: cada nó da segtree guarda um vetor ordenado
dos elementos da subarray que representa, permitindo
fazer busca binária para contarmos quantos estão
entre a e b;

*/

#include <bits/stdc++.h>

using namespace std;

const int N = 112345;

vector<int> t[4*N];

int a[N];

void build(int i, int l, int r) {
	if (l == r) {
		t[i].push_back(a[l]);
	} else {
		int m = (l+r)/2;
		build(2*i, l, m);
		build(2*i+1, m+1, r);
		merge(t[2*i].begin(), t[2*i].end(), t[2*i+1].begin(), t[2*i+1].end(), back_inserter(t[i]));
	}
}

int query(int i, int l, int r, int ql, int qr, int a, int b) {
	if (ql <= l && r <= qr) {
		return upper_bound(t[i].begin(), t[i].end(), b)
		- lower_bound(t[i].begin(), t[i].end(), a);		
	}
	if (qr < l || r < ql) return 0;
	int m = (l+r)/2;
	return query(2*i, l, m, ql, qr, a, b)
		 + query(2*i+1, m+1, r, ql, qr, a, b);
}


int main() {
	
	return 0;
}

