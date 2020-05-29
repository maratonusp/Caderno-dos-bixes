//https://codeforces.com/problemset/problem/1042/b
#include "bits/stdc++.h"
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int INF = 0x3f3f3f3f;

int n;
int memo[1010][10];
int p[1010];
int A[1010];

bool in(char a,string s){
	for(int i = 0; i < s.size();i++) if(s[i] == a) return true;
	return false;
}

int dp(int ind,int mask){
	if(mask == 7) return 0;
	if(ind == n) return INF;

	int pdm = memo[ind][mask];
	if(pdm != -1) return pdm;

	pdm = min(dp(ind+1,mask),p[ind] + dp(ind+1,mask|A[ind]));

	memo[ind][mask] = pdm;
	return pdm;
}
int main(){

	fastio;
	cin >> n;
	string s;
	for(int i = 0; i < 1010;i++){
		for(int j = 0;j<10;j++){
			memo[i][j] = -1;
		}
	}
	for(int i = 0; i< n; i++){
		cin >> p[i];
		cin >> s;

		if(in('A',s)) A[i]|= 1<<2;
		if(in('B',s)) A[i]|= 1<<1;
		if(in('C',s)) A[i]|= 1<<0;
	}

	int x = dp(0,0);
	if(x >= INF) x =-1;

	cout << x << endl;

}
