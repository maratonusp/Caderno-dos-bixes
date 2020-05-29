//https://www.spoj.com/problems/PESADA04/
#include<stdio.h>

const int INF = 0x3f3f3f3f;
int dist[20][20];
int memo[20][5000];
int fullmask;
int n;


int dp(int i,int S){
	if(S == fullmask) return dist[i][0];
	
	int pdm = memo[i][S];
	if(pdm != -1) return pdm;

	pdm = INF;
	for(int j =0;j < n;j++){
		if((S&(1<<j)) == 0){
			int aux = dp(j,S|(1<<j)) + dist[i][j];
			if (pdm > aux) pdm = aux;

		} 
	}

	memo[i][S] = pdm;
	return pdm;

}

int main(){
	int T;

	scanf("%d", &T);

	while(T--){
		scanf("%d", &n);
		n++;


		fullmask = (1 << n) - 1; // ex: (n = 2) 1<<2 = 4; 4 - 1 = 3 = 11

		for(int i =0;i < 20;i++){
			for(int j =0 ;j < 5000;j++){
				memo[i][j] = -1;
			}
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i == j) continue;
				scanf("%d", &dist[i][j]);
			}
		}

		int x = dp(0,1);

		printf("%d\n",x);

	}
}