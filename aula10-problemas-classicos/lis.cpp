#include<bits/stdc++.h>
using namespace std;

/* Vetor que me retorna o tamanho da maior subsequencia crescente */
int lis(vector<int> &v) {

    int n = v.size();
    vector<int> aux(n+1, INT_MAX);
    d[0] = INT_MIN;

    for (int i = 0; i < n; i++) {

        /* Fazendo a busca binaria para pegar o maior indice */
        int j = upper_bound(aux.begin(), aux.end(), v[i]) - aux.begin();
        if (aux[j-1] < v[i] && v[i] < aux[j])
            aux[j] = v[i];
    }

    for (int i = n; i >= 0; i--)
        if (aux[i] < INT_MAX)
            return i;
}
