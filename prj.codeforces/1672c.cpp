#include <iostream>
#include <vector>

int main() {
	int t = 0;
	std::cin >> t;
	std::vector < std::vector <int> > mass(8, std::vector <int>(8));
	for (int i = 0; i < t; i++) {
		for (int i1 = 0; i1 < 8; i1++) {
			for (int i2 = 0; i2 < 8; i2++) {
				char x;
				std::cin >> x;
				if (x == '#') {
					mass[i1][i2] = 1;
				}
				else {
					mass[i1][i2] = 0;
				}
			}
		}
		for (int i1 = 1; i1 < 7; i1++) {
			for (int i2 = 1; i2 < 7; i2++) {
				if ((mass[i1 - 1][i2 - 1] == 1) && (mass[i1 - 1][i2 + 1] == 1) && (mass[i1 + 1][i2 - 1]) && (mass[i1 + 1][i2 + 1] == 1) && (mass[i1][i2] == 1)) {
					std::cout << i1 + 1 << ' ' << i2 + 1 << '\n';
				}
			}
		}
	}
}