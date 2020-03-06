#include <bits/stdc++.h>
using namespace std;

const int MAXN = 212345;

double s[10];


/*pos  v
 *     2 4 3 1 5
 * i       ^ 
	*/


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

int main (){
	for(int a=0;a<5;a++){
		scanf("%lf", s+a);
	}

	selection_sort();


	double soma = 0.0;
	for(int a=0;a<5;a++){
		soma += s[a];
	}

	soma = soma - s[0] - s[4];

	printf("%.1f\n", soma);
}

