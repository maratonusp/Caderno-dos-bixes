#include <bits/stdc++.h>
using namespace std;

const int MAXN = 112345;

int n, m;

int s[MAXN];

int main (){
	scanf("%d %d", &n, &m);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
	}
	for(int a=0;a<m;a++){
		int valor;
		scanf("%d", &valor);

		int de = 0, ate = n-1;
		while(de < ate){
			int meio = (de + ate)/2;

			if(s[meio] < valor){
				// o valor esta na direita do meio!
				de = meio + 1;
			}
			else if(s[meio] > valor){
				ate = meio - 1;	
			}
			else{
				ate = meio;
			}
		}
		if(s[de] == valor)
			printf("%d\n", de);
		else
			printf("-1\n");
	}
}
