#include<bits/stdc++.h>

using namespace std;

/*
    Definição mais formal de complexidade:
        Digamos que N é um dos parâmetros do meu algoritmo.
        O algoritmo tem complexidade O(f(X)), se existe uma
        constante c tal que para todo X suficientemente grande(i.e.
        existe N0 tal que para todo X >= N0), o número de operações 
        do meu algoritmo é <= c*f(x).

        Caso queira estudar mais a fundo isso: https://www.ime.usp.br/~song/mac5710/slides/01complex.pdf
*/

int main(){
    /*
        Ler um vetor
        O(n)
    */

    int v[100];
    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    /*
        cin >> v[0];
        cin >> v[1];
            ...
        cin >> v[n-1];
    */






    /*
        Ler uma matriz
        O(l*c)
    */

    int m[100][100];
    int l, c;
    cin >> l >> c;

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < c; j++){
            cin >> m[i][j];
        }        
    }






   /*
        A função sort tem complexidade nlog2(n)
    */
    sort(v, v + n);








    /*
        Colocar os dígitos do inteiro x num vetor
        O(log10(x))
    */

    int x;
    int d[100];
    cin >> x;

    int i = 0;
    while(x > 0){
        d[i] = x%10;
        x = x/10;
        i++;
    }





    for(int j = i-1; j >= 0; j--){
        cout << d[j];
    }

    cout << endl;
}