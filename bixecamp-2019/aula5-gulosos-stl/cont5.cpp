#include <bits/stdc++.h>

using namespace std;

int main() {
	// do maior pro menor
	//priority_queue<int> pq;
	
	// do menor pro maior
	priority_queue<int, vector<int>, greater<int>> pq;
	// outra possibilidade é inverter o sinal do numero
	// sempre que inseri-lo ou consulta-lo:
	// pq.push(-x)
	// -pq.top()
	
	pq.push(5);
	pq.push(2);
	pq.push(15);

	cout << pq.top() << " ";
	pq.pop();
	cout << pq.top() << " ";
	pq.pop();
	cout << pq.top() << "\n";

	return 0;
}