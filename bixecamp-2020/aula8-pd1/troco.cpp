#include<bits/stdc++.h>
using namespace std;
const int MAX = 1123;
int n, troco;
int a[MAX];
int dp[MAX];

/* 2 5 7
dp[0] = 1;
dp[1] = 0;
dp[2] = 1;
dp[3] = 0;
dp[4] = 0;
...
*/

int main(){
    /*OBS: no problema do neps ele pede apenas para calcular se dá ou não para conseguir exatamente o troco*/
    /* esse codigo abaixo calcula também de quantas maneiras conseguimos chegar nesse troco */
    cin >> n >> troco;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    dp[0] = 1; /* base */

    /* iterativo */
    for(int i = 0; i <= troco; i++){
        for(int j = 0; j < n; j++){
            int aux = a[j];
            if(i-aux >= 0){
                dp[i] += dp[i-aux];
            }
        }
    }

    if(dp[troco]){ /* se dp[troco] != 0, ou seja, conseguimos alguma forma de calcular o troco*/
        cout << "S\n";
    }
    else{
        cout << "N\n";
    }
}