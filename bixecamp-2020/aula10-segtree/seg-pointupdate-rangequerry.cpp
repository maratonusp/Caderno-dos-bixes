#include <bits/stdc++.h>
using namespace std;

const int N = 112345;
int st[4 * N]; // array representando a seg
int arr[N];    // array dado no problema
int n, q;
int o, a, b, k;

void build(int i, int l, int r) {
	if (l == r) {       // se estamos numa folha
		st[i] = arr[l]; // então esse nó contém o próprio valor do segmento [l,l]
		                // (pois l=r)
	} else {
		int m = (l + r) / 2;

		// Construímos recursivamente o filho da esquerda e direita
		build(2 * i, l, m);
		build(2 * i + 1, m + 1, r);

		// Como o da esquerda possui a soma da metade esquerda do nosso segmento
		// e o da direita possui a soma da metade direita
		//
		// Então o nosso valor é a soma do filho esquerdo com o direito
		st[i] = st[2 * i] + st[2 * i + 1];
	}
}

void update(int i, int l, int r, int pos, int k) {
	if (l == r) {   // Se chegamos na folha, então pos = l = r
		st[i] += k; // Ao chegarmos na raiz, somamos k diretamente
	} else {
		int m = (l + r) / 2;

		// Se a posição que queremos atualizar está para a esquerda,
		if (pos <= m) update(2 * i, l, m, pos, k); // atualizamos a esquerda.
		// Se a posição que queremos atualizar está para a direita,
		else
			update(2 * i + 1, m + 1, r, pos, k); // atualizamos a direita.

		// Após atualizar um dos filhos, atualizamos o nó atual
		st[i] = st[2 * i] + st[2 * i + 1];
	}
}

int query(int i, int l, int r, int ql, int qr) {
	// Se o segmento da consulta [ql, qr] não intersecta o segmento atual [l, r]
	if (qr < l || r < ql) return 0; // Retornamos uma soma nula

	// Se o segmento atual está completamente contido no segmento da consulta
	if (ql <= l && r <= qr) return st[i]; // Retornamos a soma de l a r

	// Caso contrário, então o segmento atual possui apenas parte da soma desejada
	// e devemos quebrar esse nó nos seus dois subintervalos
	int m = (l + r) / 2;
	return query(2 * i, l, m, ql, qr) + query(2 * i + 1, m + 1, r, ql, qr);
}

int main() {
	cin >> n;
	// Cuidado com os índices! (não começa de zero)
	for (int i = 1; i <= n; i++) cin >> arr[i];

	build(1, 1, n);
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> o;
		if (o == 1) {
			cin >> a >> k;
			update(1, 1, n, a, k);
		} else if (o == 2) {
			cin >> a >> b;
			cout << query(1, 1, n, a, b) << endl;
		} else {
      for (int i = 1; i <= 2*n; i++) cout << i << ' ' << st[i] << endl;
    }
	}

	return 0;
}
