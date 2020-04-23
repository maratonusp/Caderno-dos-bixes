// 
#include<bits/stdc++.h>

using namespace std;

int frH[30], frP[30];
string p, h;

int isEqual(){
	for(int i = 0; i < 26; i++){
		if(frP[i] != frH[i])
			return 0;
	}

	return 1;
}

int main(){
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	while(t--){
		cin >> p >> h;

        if(h.size() < p.size()){
            cout << "NO\n";
            continue;
        }

		for(int i = 0; i < 26; i++){
			frH[i] = frP[i] = 0;
		}

		for(int i = 0; i < p.size(); i++){
			frH[h[i] - 'a']++;
			frP[p[i] - 'a']++;
        }

		int deu = 0;

		if(isEqual()){
			deu = 1;
		}

		for(int i = 0; i + p.size() < h.size(); i++){
			frH[h[i] - 'a']--;
			frH[h[i + p.size()] - 'a']++;

			if(isEqual()){
				deu = 1;
			}
		}

		if(deu) cout << "YES\n";
		else cout << "NO\n";
	}
}
