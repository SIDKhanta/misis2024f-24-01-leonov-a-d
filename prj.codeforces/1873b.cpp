#include <iostream>

int main() {
	int t = 0;
	int n = 0;
	int x = 0;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::cin >> n;
		std::cin >> x;
		int uvel = x + 1;
		int proizv = x + 1;
		for (int j = 1; j < n; j++) {
			std::cin >> x;
			if ((proizv / uvel) * (uvel - 1) * (x + 1) > proizv * x) {
				proizv = (proizv / uvel) * (uvel - 1) * (x + 1);
				uvel = x + 1;
			}
			else {
				proizv *= x;
			}
		}
		std::cout << proizv << '\n';
	}
}