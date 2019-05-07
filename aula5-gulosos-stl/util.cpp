#include <bits/stdc++.h>

using namespace std;

int main() {
	pair<int, string> p(2, "oie");
	cout << p.first << " " << p.second << endl;

	pair<int, string> q(2, "p");
	cout << (q < p) << endl;

	tuple<int, int, string, double> t1(1, 2, "xd", 3.14);
	cout << get<2>(t1) << endl;

	int a, b;
	tie(a, b, ignore, ignore) = t1;
	
	cout << a << " " << b << " " << endl;

	return 0;
}