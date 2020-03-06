#include <bits/stdc++.h>
using namespace std;

const int MAXN = 112345;

int main (){
	int n;
	int s[MAXN];
	scanf("%d", &n);
	for(int a=0;a<n;a++)
		scanf("%d", s+a);

	for(int a=0;a<n;a++)
		s[a] = s[a]*2;

	for(int a=0;a<n;a++)
		printf("%d ", s[a]);
}

