//https://www.spoj.com/problems/ACODE/
#include "bits/stdc++.h"
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

long long v[5050];
long long memo[5050];
string s;
int n;

long long dp(int ind){
	if(ind >= n) return 1;
	if(v[ind] == 0) return 0;
	if(ind == n-1) return 1;

	long long pdm = memo[ind];
	if(pdm != -1) return pdm;

	pdm = dp(ind + 1);
	if(v[ind]*10 + v[ind + 1] <= 26) pdm += dp(ind + 2);

	memo[ind] = pdm;
	return pdm;

}
int main(){

	fastio;

	getline(cin,s);

	while(s[0] != '0'){
		n = s.size();
		for(int i = 0; i<n; i++){
			v[i] = s[i] -'0';
			memo[i] = -1;
		}

		cout << dp(0) << endl;
		getline(cin,s);
	}

}
