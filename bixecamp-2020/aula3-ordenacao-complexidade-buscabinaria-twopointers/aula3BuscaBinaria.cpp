#include<bits/stdc++.h>

using namespace std;

int v[100010];
int n;

/*
    Essa função recebe um inteiro x e retorna 1 se x está
    presente em v, e retorna 0 caso x não está presente em v.
    
    Ela é O(log2(n))
*/
int bb(int x){
    int ini = 0, fim = n, meio;

    while(ini < fim - 1){
        meio = (ini + fim)/2;

        if(v[meio] == x){
            return 1;
        }
        else if(v[meio] < x){
            ini = meio;
        }
        else{
            fim = meio;
        }
    }

    return 0;
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v, v + n);

    int perguntas;
    cin >> perguntas;

    for(int i = 0; i < perguntas; i++){
        int x;
        cin >> x;

        cout << bb(x) << "\n";
    }
}