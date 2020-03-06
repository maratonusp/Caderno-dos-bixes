int fat (int n) {
	
	// Base da recursão
	if (n <= 1)
		return 1;

	// Recursão em si
	return n*fat(n-1);
}
