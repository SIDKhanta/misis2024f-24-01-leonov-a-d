#include <iostream>
#include <vector>

int main() {
	long long n = 0;
	long long m = 0;
	long long pref = 1;
	long long now = 0;
	long long ans = 0;
	std::cin >> n >> m;
	for (int i = 0; i < m; i++) {
		std::cin >> now;
		if (now - pref >= 0) {
			ans += (now - pref);
		}
		else {
			ans += (now - pref + n);
		}
		pref = now;
	}
	std::cout << ans;
}
