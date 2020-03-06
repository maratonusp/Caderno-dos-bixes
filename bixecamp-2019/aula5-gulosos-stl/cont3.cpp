#include <bits/stdc++.h>

using namespace std;

int main() {
	deque<double> d;

	d.push_front(1);
	d.push_front(2);
	d.push_back(3);

	cout << d[0] << d[1] << d[2] << endl;

	// deque possui pop_front() e pop_back()
	// alem de permitir acessar o i-esimo elemento
	// em tempo constante
	return 0;
}