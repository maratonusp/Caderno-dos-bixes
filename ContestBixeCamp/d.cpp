#include <bits/stdc++.h>

using namespace std;

#define MAXN 200010
#define ll long long

ll v[MAXN];
ll n;

int main(){

    cin >> n;
 
	for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
 
	ll p1 = 0, p3 = n+1, sum1 = 0, sum3 = 0, ans = 0;
 
	while(p1 < p3){
		if(sum1 == sum3){ 
			ans = max(ans, sum1);
        }

		if(sum1 > sum3){
			p3--;
			sum3 += v[p3];
		}
		else{
			p1++;
			sum1 += v[p1];
		}
	}
 
	cout << ans << endl;
}