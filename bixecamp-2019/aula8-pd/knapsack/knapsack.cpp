#include "bits/stdc++.h"
using namespace std;

//https://www.spoj.com/problems/KNAPSACK/

int memo[2020][2020];
int wgt[2020],cost[2020];
int s,n;
vector<int> caras;

const int INF = 0x3f3f3f3f;

int pd(int ind, int cap){

    if(cap<0)   return -INF;
    if(ind==n)  return 0;

    int& pdm = memo[ind][cap];
    if(pdm!=-1) return pdm;

    return pdm = max( pd(ind+1, cap), cost[ind] + pd(ind+1, cap - wgt[ind]) );

}

int main(){

    cin >> s >> n;

    for(int i=0;i<n;i++)
        cin >> wgt[i] >> cost[i];

    memset(memo, -1, sizeof(memo));

    cout << pd(0,s) << endl;

}