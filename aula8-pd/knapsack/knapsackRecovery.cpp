#include "bits/stdc++.h"
using namespace std;

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

void recover(int ind, int cap){

    if(ind==n)  return;

    int pega = cost[ind] + pd(ind+1, cap - wgt[ind]);
    int passa = pd(ind+1, cap);

    if(pega>=passa){
        caras.push_back(ind);
        recover(ind+1, cap - wgt[ind]);
    }
    else{
        recover(ind+1, cap);
    }

}

int main(){

    cin >> s >> n;

    string aux;

    for(int i=0;i<n;i++){
        cin >> wgt[i] >> cost[i];
    }

    memset(memo, -1, sizeof(memo));

    cout << pd(0,s) << endl;

    recover(0,s);

    int profit = 0;
    int total_wgt = 0;

    for(auto x : caras){
        profit+=cost[x];
        total_wgt+=wgt[x];
    }

    assert(profit == pd(0, s) && total_wgt<=s);

    for(auto x : caras)
        cout << x << " ";
    cout << "\n";

}