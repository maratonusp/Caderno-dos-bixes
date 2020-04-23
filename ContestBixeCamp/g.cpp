#include<bits/stdc++.h>

using namespace std;

#define MAXN 10010

int n;
set<int> freePos;
priority_queue<pair<int, int>> fila;
int d, g;

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> g >> d;
		fila.push(make_pair(g, -d));
	}

	for(int i = 1; i < MAXN; i++){
		freePos.insert(-i);
	}

	int ans = 0;

	for(int i = 1; i <= n; i++){
		auto x = freePos.lower_bound(fila.top().second);

		if(x != freePos.end()){
			ans += fila.top().first;
			freePos.erase((*x));
		}

		fila.pop();
	}

	cout << ans << endl;
}
