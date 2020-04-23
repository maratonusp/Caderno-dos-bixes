#include<bits/stdc++.h>
using namespace std;

#define MAXN 100010

char resp[MAXN];
int n, k;

int main(){
    int t;
    cin >> t;

    while(t--){
        cin >> n >> k;
        
        for(int i = 1; i <= n; i++)
            resp[i] = 'a';

        for(int i = n-1; i >= 1; i--){
            if((n - i) >= k){
                resp[i] = 'b';
                resp[n + 1 - k] = 'b';
                break;
            }
            else 
                k -= (n-i);
        }

        for(int i = 1; i <= n; i++){
            cout << resp[i];
        }

        cout << "\n";
    }
}