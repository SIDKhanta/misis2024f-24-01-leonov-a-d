#include <iostream>
#include <string>

int main() {
	int t = 0;
	std::string s;
	std::cin >> t;
	int n, k;
	for (int i = 0; i < t; i++) {
		std::cin >> n >> k;
		std::cin >> s;
		int count = 0, ans = 0;
		for (int j = 0; j < n; j++) {
			if (count > 0 && count < k) {
				count++;
			}
			else if (count == k) {
				if (s[j] == 'B') {
					count = 1;
				}
				else {
					count = 0;
				}
				ans++;
			}
			else if (count == 0 && s[j] == 'B') {
				count++;
			}
		}
		if (count > 0) {
			ans++;
		}
		std::cout << ans << '\n';
	}
}
