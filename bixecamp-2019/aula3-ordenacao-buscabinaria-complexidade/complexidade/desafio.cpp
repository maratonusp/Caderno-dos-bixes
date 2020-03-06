#include <bits/stdc++.h>
using namespace std;

const int MAXN = 112345;
int n;
int s[MAXN];

int raiz(){
	int sq;
	for(sq = 1;sq * sq <= n;sq++){
	}
	sq--;

	return sq;
}

void mult2(){
	for(int a=0;a<n;a++)
		s[a] = s[a]*2;

	for(int a=0;a<n;a++)
		printf("%d ", s[a]);
	printf("\n");
}

void selection_sort(){
	for(int pos = 0;pos < 5;pos++){
		double menor = DBL_MAX;
		int indiceMenor;

		for(int i=pos;i < 5;i++){
			if(s[i] < menor){
				menor = s[i];
				indiceMenor = i;
			}
		}

		s[indiceMenor] = s[pos];
		s[pos] = menor;
	}
}

void for1e8() {
	for(int i=0;i<100000000;i++){
		bool nao_faz_nada = true;		
	}
}


int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++)
		scanf("%d", s+a);
	
	raiz();
	sort(s, s+n);
	mult2();
	selection_sort();
	for1e8();
}


