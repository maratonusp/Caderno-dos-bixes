#include "bits/stdc++.h"
using namespace std;

//https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/problem

#define dbg(x) cout << #x << " = " << x << endl

int a[1010], b[1010];
int memo[1010][1010];

vector<int> bestSequence;

int n, m;

const int INF = 0x3f3f3f3f;

int pd(int i, int j){

    if(i==n || j==m)
        return 0;

    int& pdm = memo[i][j];
    if(pdm!=-1) return pdm;

    pdm=0;

    if(a[i]==b[j])
        pdm=max(pdm, 1 + pd(i+1,j+1));

    return pdm = max({pdm, pd(i+1,j), pd(i,j+1)});

}

void recover(int i, int j){
    
    if(i==n || j==m)    return;

    int passa1 = pd(i+1, j);
    int passa2 = pd(i, j+1);
    int pega = (a[i]==b[j] ? 1 + pd(i+1, j+1) : -INF);

    if(pega>=passa1 && pega>=passa2)
        bestSequence.push_back(a[i]), recover(i+1,j+1);

    else if(passa1>=passa2)
        recover(i+1, j);
    
    else
        recover(i, j+1);

}

int main(){

    cin >> n >> m;

    for(int i=0;i<n;i++)
        cin >> a[i];
    
    for(int i=0;i<m;i++)
        cin >> b[i];

    memset(memo, -1, sizeof(memo));

    recover(0, 0);

    for(auto x : bestSequence)
        cout << x << " ";
    cout << "\n";

}