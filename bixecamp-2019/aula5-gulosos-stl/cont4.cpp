#include <bits/stdc++.h>

using namespace std;

int main() {
	// stack possui push(), size() e pop(), dentre outros
	stack<int> st;
	// queue possui push(), size() e front(), dentre outros
	queue<int> fl;

	st.push(1); st.push(2);
	cout << st.top() << " ";
	st.pop();
	cout << st.top() << "\n";
	st.pop();

	fl.push(1);
	fl.push(2);

	cout << fl.front() << " ";
	fl.pop();
	cout << fl.front() << "\n";

	return 0;
}