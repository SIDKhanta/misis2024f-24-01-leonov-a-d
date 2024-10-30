#include <iostream>

int main() {
	int n = 0;
	int k = 0;
	int x = 0;
	std::cin >> n >> k;
	int mn = k;
	for (int i = 0; i < n; i++) {
		std::cin >> x;
		if ((k % x == 0) && (k / x < mn)) {
			mn = k / x;
		}
	}
	std::cout << mn;
}