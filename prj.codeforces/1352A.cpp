#include <iostream>
#include <vector>
#include <cmath>
 
int main() {
	int n = 0;
	int x = 0;
	std::cin >> n;
	std::vector<int> mass;
	for (int i = 0; i < n; i++) {
		std::cin >> x;
		int step_of_zero = 0;
		while (x != 0) {
			int element = x % 10;
			if (element != 0) {
				mass.push_back(element * pow(10, step_of_zero));
				step_of_zero++;
			}
			else {
				step_of_zero++;
			}
			x /= 10;
		}
		std::cout << mass.size() << "\n";
		for (int j = 0; j < mass.size(); j++) {
			std::cout << mass[j] << " ";
		}
		std::cout << "\n";
		mass.clear();
	}
}
