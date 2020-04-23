#include<bits/stdc++.h>

using namespace std;

#define MAXN 100010

int n, m;
int towers[MAXN], p[MAXN];
 
int findBestR(int ind){
	if(p[ind] < towers[1])
		return towers[1] - p[ind];
	else if(p[ind] > towers[m])
		return p[ind] - towers[m];
 
	int ini = 1, fim = m, mid;
 
	while(ini < fim - 1){
		mid = (ini + fim)/2;
 
        if(towers[mid] == p[ind])
			return 0;
		else if(towers[mid] > p[ind])
			fim = mid;
		else
			ini = mid;
	}
 
	return min(towers[fim] - p[ind], p[ind] - towers[ini]);
}
 
int main(){
	ios::sync_with_stdio(false);
 
	cin >> n >> m;
    
    for(int i = 1; i <= n; i++)
        cin >> p[i];

    for(int i = 1; i <= m; i++)
        cin >> towers[i];

	sort(towers + 1, towers + m + 1);
 
	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans = max(ans, findBestR(i));
	}
 
	cout << ans << endl;
}