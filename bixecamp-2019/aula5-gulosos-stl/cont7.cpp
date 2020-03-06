#include <bits/stdc++.h>

using namespace std;

int main() {
	/*unordered_*/map<int, string> m;
	m[3] = "oie";
	m[4] = "bla";
	m[3] = "x";

	cout << m[6] << endl;

	auto it = m.find(3);
	cout << (*it).first << " " << (*it).second << endl;

	return 0;
}