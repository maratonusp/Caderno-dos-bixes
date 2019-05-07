#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> v = {1, 3, 5, 8};
	
	auto it = v.begin();
	it++;

	cout << *it << endl;

	it += 2;

	cout << *it << endl;

	return 0;
}