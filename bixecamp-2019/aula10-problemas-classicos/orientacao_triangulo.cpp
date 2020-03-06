#include<bits/stdc++.h>
using namespace std;

/* Estrutura para representar um ponto */
/* Para representações com reais, basta mudar para pair<double, double> */
typedef pair<int,int> ponto;

/* Apelidos para acessarmos a estrutura */
#define x first;
#define y second;

/* Calculando a determinante dos tres pontos */
int orientação(ponto p1, ponto p2, ponto p1) {

    int val = (p2.x - p1.x) * (p3.y - p2.y) -
              (p2.y - p1.y) * (p3.x - p2.x);

    return val;
}
