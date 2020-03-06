/*

Versão com lazy propagation:

query: soma dos elementos de ql a qr
update: soma x aos elementos de ql a qr

Ideia da lazy:
Quando estamos atualizando um intervalo, prosseguimos
como na query em que "quebramos" até o nó atual estar
ou completamente fora ou completamente dentro do intervalo
a ser atualizado.
Quando um nó está completamente dentro, atualizamos sua soma
acumulada em O(1), e marcamos seus filhos (com a função push)
para que seja possível atualizá-los na próxima vez que passarmos
por eles.

*/

#include <bits/stdc++.h>

using namespace std;

const int N = 112345;

int t[4*N], lz[4*N];

int a[N];

void build(int i, int l, int r) {
	if (l == r) {
		t[i] = a[l];
	} else {
		int m = (l+r)/2;
		build(2*i, l, m);
		build(2*i+1, m+1, r);
		t[i] = t[2*i] + t[2*i+1];
	}
}

void push(int i, int l, int r) {
	if (lz[i]) {
		t[i] += lz[i] * (r-l+1);
		if (l != r) {
			lz[2*i] += lz[i];
			lz[2*i+1] += lz[i];
		}
		lz[i] = 0;
	}
}

int query(int i, int l, int r, int ql, int qr) {
	push(i, l, r);
	if (ql <= l && r <= qr) return t[i];
	if (qr < l || r < ql) return 0;
	int m = (l+r)/2;
	return query(2*i, l, m, ql, qr)
		 + query(2*i+1, m+1, r, ql, qr);
}

void update(int i, int l, int r, int ql, int qr, int x) {
	// nao esqueçam!!!
	push(i, l, r);
	if (qr < l || r < ql) return;
	if (ql <= l && r <= qr) {
		lz[i] += x;
		push(i, l, r);
	} else {
		int m = (l+r)/2;
		update(2*i, l, m, ql, qr, x);
		update(2*i+1, m+1, r, ql, qr, x);
		
		t[i] = t[2*i] + t[2*i+1];
	}
}

int main() {
	
	return 0;
}

