#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
const ll MOD = 1e9+7;

int main(int argc, char* argv[]){

    int n = stoi(argv[1]);

    ll fib = 0;
    ll nxt = 1;

    for(int i=1;i<=n;i++){
        fib+=nxt;
        swap(fib, nxt);
        fib%=MOD;
        nxt%=MOD;
    }

    cout << fib << endl;

}