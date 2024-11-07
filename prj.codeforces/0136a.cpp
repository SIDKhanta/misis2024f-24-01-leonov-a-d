#include <iostream>
#include <vector>

int main() {
	int n = 0;
	int x = 0;
	std::cin >> n;
	std::vector<int> mass(n);
	for (int i = 0; i < n; i++) {
		std::cin >> x;
		mass[x - 1] = i + 1;
	}
	for (int i = 0; i < n; i++) {
		std::cout << mass[i] << ' ';
	}
}