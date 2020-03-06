/*

Exemplo de Seg Tree beats.
Solução do problema https://codeforces.com/problemset/problem/444/C
Further reading: https://codeforces.com/blog/entry/57319?

A ideia da seg tree beats é deixar a condição de "estar completamente
contido" mais forte. Nesse problema, atualizaremos um nó se ele estiver
contido no intervalo E se todos os números no intervalo são iguais.

Essa solução é rápida por causa da natureza do problema, essa mesma idéia
pode não ser suficiente para outros problemas!

*/

#include <bits/stdc++.h>

using namespace std;

const int N = 112345;

typedef long long ll;

ll t[4*N];
ll lzs[4*N], lzm[4*N];

int a[4*N], b[4*N];

void build(int i, int l, int r) {
	if (l == r) {
		a[i] = b[i] = l;
	} else {
		int m = (l+r)/2;
		build(2*i, l, m);
		build(2*i+1, m+1, r);
		a[i] = l; // = a[2*i];
		b[i] = r; // = b[2*i+1];
	}
}

void push(int i, int l, int r) {
	if (lzs[i]) {
		t[i] += 1ll* lzs[i] * (r-l+1);
		if (l != r) {
			lzs[2*i] += lzs[i];
			lzs[2*i+1] += lzs[i];
		}
		lzs[i] = 0;
	}
	if (lzm[i]) {
		a[i] = b[i] = lzm[i];
		if (l != r) {
			lzm[2*i] = lzm[i];
			lzm[2*i+1] = lzm[i];
		}
		lzm[i] = 0;
	}
}

ll query(int i, int l, int r, int ql, int qr) {
	push(i, l, r);
	if (ql <= l && r <= qr) return t[i];
	if (qr < l || r < ql) return 0;
	int m = (l+r)/2;
	return query(2*i, l, m, ql, qr)
		 + query(2*i+1, m+1, r, ql, qr);
}

/*void update(int i, int l, int r, int p, int x) {
	if (l == r) {
		t[i] = x;
	} else {
		int m = (l+r)/2;
		if (p <= m) update(2*i, l, m, p, x);
		else update(2*i+1, m+1, r, p, x);
		t[i] = t[2*i] + t[2*i+1];
	}
}*/

void update(int i, int l, int r, int ql, int qr, int x) {
	// nao esqueçam!!!
	push(i, l, r);
	if (qr < l || r < ql) return;
	if (ql <= l && r <= qr && a[i] == b[i]) {
		lzs[i] += abs(x-a[i]);
		lzm[i] = x;
		push(i, l, r);
	} else {
		int m = (l+r)/2;
		update(2*i, l, m, ql, qr, x);
		update(2*i+1, m+1, r, ql, qr, x);
		
		t[i] = t[2*i] + t[2*i+1];
		a[i] = min(a[2*i], a[2*i+1]);
		b[i] = max(b[2*i], b[2*i+1]);
	}
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	build(1, 1, n);
	while (m--) {
		int op; scanf("%d", &op);
		if (op == 1) {
			int l, r, x; scanf("%d%d%d", &l, &r, &x);
			update(1, 1, n, l, r, x);
		} else {
			int l, r; scanf("%d%d", &l, &r);
			printf("%lld\n", query(1, 1, n, l, r));
		}
	}
	return 0;
}

