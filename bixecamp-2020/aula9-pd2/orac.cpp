//https://codeforces.com/problemset/problem/1350/B
#include "bits/stdc++.h"
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int v[100100];
int n;
int memo[100100];

int dp(int ind){
	if(ind == n) return 1; 

	int pdm = memo[ind]; 
	if(pdm != -1) return pdm; 

	pdm = 1;

	int j = ind;

	while(j <= n){ 
		if(v[j] > v[ind])
			pdm = max(pdm,1 + dp(j));
		j += ind;
	}

	memo[ind] = pdm; 
	return pdm;
}

int main(){

	fastio;
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		for(int i =1; i <= n; i++){
			cin >> v[i];
			memo[i] = -1;
		}

		int mx = -1;

		for(int i = 1;i <= n; i++){ 
			mx = max(mx,dp(i));
		}

		cout << mx << endl;


	}

}
