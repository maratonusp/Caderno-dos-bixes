#include<bits/stdc++.h>

using namespace std;

#define MAXN 1000010

int main(){
    int t;
    cin >> t;
    while(t--){
        int v[MAXN];
        int n, l;
        cin >> l >> n;

        int maior = 0, menor = 0;

        for(int i = 1; i <= n; i++){
            cin >> v[i];

            maior = max(max(l - v[i], v[i]), maior);
            menor = max(min(l - v[i], v[i]), menor);
        }

        cout << menor << " " << maior << endl;
    }
}