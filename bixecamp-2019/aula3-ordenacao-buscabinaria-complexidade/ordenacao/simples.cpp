#include <bits/stdc++.h>
using namespace std;

const int MAXN = 212345;

int n;
int s[MAXN];


void selection_sort(){
	for(int pos = 0;pos < n;pos++){
		int menor = INT_MAX, indiceMenor;
		for(int i = pos;i < n;i++){
			if(s[i] < menor){
				menor = s[i];
				indiceMenor = i;
			}
		}
		s[indiceMenor] = s[pos];
		s[pos] = menor;
	}
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", s+a);
	}

	//selection_sort();
	sort(s, s+n);

	for(int a=0;a<n;a++){
		printf("%d ", s[a]);
	}
	printf("\n");
}

