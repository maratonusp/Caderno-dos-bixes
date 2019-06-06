#include<bits/stdc++.h>
using namespace std;

/* Função que conta inversões usando mergesort */
int ic(vector<int> &v){

    /* Contagem inicial é sempre 0 */
	int inv = 0;

    /* Caso base, todo vetor unitario esta ordenado */
	if (v.size() == 1) return 0;

    /* Vetores que representarão cada metade de v */
	vector<int> u1, u2;

    /* Copiando */
	for (int i = 0; i < v.size()/2; i++)
		u1.push_back(v[i]);
	for (int i = v.size()/2; i < v.size(); i++)
		u2.push_back(v[i]);

    /* Chamada recursiva para cada parte, tecnica de divisão e conquista */
	inv += ic(u1);
	inv += ic(u2);

    /* Adicionando limites para contagem a seguir */
	u1.push_back(INT_MAX);
	u2.push_back(INT_MAX);

	int ini1 = 0, ini2 = 0;

    /* Ordenando o vetor v, com as duas metades ordenadas */
	for (int i = 0; i < v.size(); i++){

		/* Se o menor de u1 for menor que o de u2 */
		if (u1[ini1] <= u2[ini2])
			v[i] = u1[ini1++];

        /* Caso contrario */
		else {
			v[i] = u2[ini2++];

			/* Incremento com o numero de elementos em u1 */
			inv += u1.size() - ini1 - 1;
		}
	}

    /* Ao final da iteração, o vetor v vai estar ordenado */

	return inv;
}
