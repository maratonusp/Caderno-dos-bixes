#include<bits/stdc++.h>
using namespace std;
const int MAX = 1123;
int a[MAX], b[MAX];
int memo[MAX][MAX];
int n;

int lcs(int i, int j){
    if(i == n || j == n) return 0; /*se chegamos no final de um dos vetores, paramos*/

    if(memo[i][j] != -1) return memo[i][j];

    if(a[i] == b[j]){
        return memo[i][j] = lcs(i+1, j+1)+1; /*se for igual (common) somamos um na resposta e avançamos os dois */
    }
    else{
        return memo[i][j] = max(lcs(i+1, j), lcs(i, j+1)); /* avaçamos um ou o outro */
    }
}

int main(){
    cin >> n;
    /* inicializa com -1 */
    for(int i = 0; i <= n+1; i++)
        for(int j = 0; j <= n+1; j++)
            memo[i][j] = -1;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = a[i]; /*copia*/
    }
    sort(b, b+n); /* ordena */
    cout << lcs(0, 0) << endl;
}