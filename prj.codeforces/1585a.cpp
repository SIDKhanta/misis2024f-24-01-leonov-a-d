#include <iostream>
#include <vector>

int main() {
	int t = 0;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::vector<int> mass;
		int n = 0;
		int x = 0;
		int ans = 1;
		std::cin >> n;
		for (int j = 0; j < n; j++) {
			std::cin >> x;
			mass.push_back(x);
		}
		for (int j = 0; j < mass.size(); j++) {
			if (j == 0) {
				if (mass[j] == 1) {
					ans++;
				}
			}
			else {
				if ((mass[j] == 0) && (mass[j - 1] == 0)) {
					ans = -1;
					break;
				}
				if (mass[j] == 1) {
					if (mass[j - 1] == 0) {
						ans++;
					}
					else {
						ans += 5;
					}
				}
			}
		}
		std::cout << ans << '\n';
	}
}