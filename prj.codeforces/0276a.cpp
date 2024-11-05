#include <iostream>
#include <algorithm>
 
int main() {
	long long n = 0, k = 0;
	long long mx = -200000000000;
	long long fi = 0, ti = 0;
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> fi >> ti;
		if (ti > k) {
			mx = std::max(mx, fi - (ti - k));
		}
		else {
			mx = std::max(mx, fi);
		}
	}
	std::cout << mx;
}
