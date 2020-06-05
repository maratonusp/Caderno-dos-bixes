#include <bits/stdc++.h>
using namespace std;

const int N = 112345;
int st[4 * N]; // array representando a seg
int lz[4 * N]; // array representando as ataulizações pendentes
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

	// A única mudança desse método:
	// Não temos nenhuma mudança em nenhum nó inicialmente
	lz[i] = 0;
}

// um método novo que verifica se há mudanças pendentes
// se sim, ele faz a mudança no nó atual e empurra o "lembrete" de atualizações
// para os filhos
void push(int i, int l, int r) {
	// se temos mudanças pendentes
	if (lz[i] != 0) {
		// atualizamos (vamos discutir essa fórmula depois)
		st[i] += lz[i] * (r - l + 1);

		if (l != r) { // se não é uma folha
			// passamos a pendência para os filhos
			lz[2 * i] += lz[i];
			lz[2 * i + 1] += lz[i];
		}

		// como fizemos a atualização, não há mais pendências
		lz[i] = 0;
	}
}

void update(int i, int l, int r, int ql, int qr, int k) {
	// Se tinha alguma mudança pra ser feita, fazemos ela antes de mais nada
	push(i, l, r);

	if (qr < l || r < ql) return;
	if (ql <= l && r <= qr) {
		// Se chegamos num ponto que podemos parar, vamos atualizar só
		// esse nó e marcar nossos filhos.

		// O jeito mais rápido (de codar) é somar k no lz[i] e chamar o push
		lz[i] += k;
		push(i, l, r);
		return;
	}

	int m = (l + r) / 2;
	update(2 * i, l, m, ql, qr, k);
	update(2 * i + 1, m + 1, r, ql, qr, k);
	st[i] = st[2 * i] + st[2 * i + 1];
}

int query(int i, int l, int r, int ql, int qr) {
	// A única diferença na query é que devemos, sempre que visitamos um nó,
	// chegar se há alguma mudança pendente e, se houver, atualizar antes de
	// mais nada.
	push(i, l, r);

	if (qr < l || r < ql) return 0;

	if (ql <= l && r <= qr) return st[i];

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
			cin >> a >> b >> k;
			update(1, 1, n, a, b, k);
		} else if (o == 2) {
			cin >> a >> b;
			cout << query(1, 1, n, a, b) << endl;
		} else {
			for (int i = 1; i <= 2 * n; i++) cout << i << ' ' << st[i] << ' ' << lz[i] << endl;
		}
	}

	return 0;
}
