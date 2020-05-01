#include<bits/stdc++.h>

using namespace std;

int main(){
    int v[100];
    int n;
    
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }


    /*
        SELECTION SORT
        O(n²)
    */

    for(int i = 0; i < n; i++){
        int menor = i;

        for(int j = i; j < n; j++){
            if(v[j] < v[menor]){
                menor = j;
            }
        }

        /*
            n - i operações
        */

        swap(v[i], v[menor]);
    }

    /*
        n + n - 1 + n - 2 + ... + 1 = n*(n + 1)/2
        Isso é O(n²) 

        para n = 10⁵, já da errado.
    */

    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }

    cout << "\n";





}