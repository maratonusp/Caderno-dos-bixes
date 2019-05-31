/*

Versão range-update/point-query:

query: valor na posição p
update: soma x nos elementos de ql a qr

Interpretação da seg:
O valor na posição i do vetor corresponde a soma
dos valores dos nós no caminho da raiz até a folha i
Isso permite "somar x" a todos os elementos de um nó
em O(1).

*/

#include <bits/stdc++.h>

using namespace std;

const int N = 112345;

int t[4*N];

void update(int i, int l, int r, int ql, int qr, int x) {
	if (ql <= l && r <= qr) {
		t[i] += x;
		return;
	}
	if (qr < l || r < ql) return;
	int m = (l+r)/2;
	update(2*i, l, m, ql, qr, x);
	update(2*i+1, m+1, r, ql, qr, x);
}

int query(int i, int l, int r, int p) {
	if (l == r) return t[i];
	int m = (l+r)/2;
	if (p <= m) {
		return t[i] + query(2*i, l, m, p);
	} else {
		return t[i] + query(2*i+1, m+1, r, p);
	}
}

int main() {
	
	return 0;
}

