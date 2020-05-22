#include<bits/stdc++.h>
using namespace std;
const int MAX = 100000;
int memo[MAX]; /* guarda os valores já calculados de fibonacci */
/* vetor de "memoização"*/

int fib(int n){
    if(memo[n] == -1) memo[n] = fib(n-1) + fib(n-2); /* se ainda não calculamos */
    return memo[n]; 
}

int main(){
    /*importante, não esquecer de inicializar com -1 pra lembrar q ainda não calculamos */
    for(int i = 0; i < MAX; i++){
        memo[i] = -1;
    }

    /* base */
    memo[0] = 1;
    memo[1] = 1;
    cout << fib(50) << endl;
}