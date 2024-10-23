#include <iostream>
 
int main() {
	int n = 0;
	int ans = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			std::cin >> n;
			if (n == 1) {
				ans = abs(i - 2) + abs(j - 2);
			}
		}
	}
	std::cout << ans;
}
