#include <bits/stdc++.h>

using namespace std;

int main() {
	/*multi*/set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(5);
	s.insert(7);


/*
	auto it = s.rbegin();
	while (it != s.rend()) {
		cout << *it << endl;
		it++;
	}
*/

	cout << s.count(3) << "\n";
	auto it = s.find(3);
	if (it == s.end()) {
		cout << "nao ta dentro\n";
	} else {
		cout << "ta dentro\n";
	}


	it = s.upper_bound(5);
	cout << *it << endl;


/*
	s.erase(5);
	s.erase(s.begin());

	for (auto x : s) {
		cout << x << "\n";
	}
	*/
	
	return 0;
}