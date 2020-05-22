#include<bits/stdc++.h>
using namespace std;
const int MAX = 2123;
const int INF = 1e9+7; /* 1000000007 */
/*const int INF = 0x3f3f3f3f;  outra maneira q constumamos fazer, 0x3f3f3f3f eh um número muito grande em base hexadecimal*/
int s, n; /* capacidade  da mochila e numero de objetos */
int v[MAX], p[MAX]; /* valor  e peso*/
int memo[MAX][MAX];
 
int pd(int i, int peso){
    if(peso > s) return -INF; /* se o peso q coletamos for maior do q oq a mochila aguenta, devolvemos -infinto, pra descartar esse caso */
    if(i == n) return 0; /* se chegamos no final do array */

    if(memo[i][peso] != -1) return memo[i][peso]; /* se ja calculamos, devolvemos o valor já*/
 
    /*caso contrario, calculamos */
    return memo[i][peso] = max(pd(i+1, peso), pd(i+1, peso+p[i]) + v[i]);
} 
 
int main(){
 
    /* inicializa o memo com -1 */
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX ; j++){
            memo[i][j] = -1;
        }   
    }
    cin >> s >> n;
 
    for(int i = 0; i < n; i++){
        cin >> p[i] >> v[i];
    }
 
    cout << pd(0, 0) << endl;
} 