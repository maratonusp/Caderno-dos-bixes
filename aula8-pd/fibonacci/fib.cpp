#include "bits/stdc++.h"
using namespace std;

typedef long long int ll;
const ll MOD = 1e9+7;

ll fib(ll x){

    if(x<=2)    return 1;
    return fib(x-1)+fib(x-2);

}

int main(int argc, char* argv[]){

    int n = stoi(argv[1]);

    printf("%lld\n",fib(n));

}