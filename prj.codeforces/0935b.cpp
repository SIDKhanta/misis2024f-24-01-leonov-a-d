#include <iostream>
#include <string>

int main() {
	int n = 0;
	int ans = 0;
	int x = 0, y = 0;
	int flag = 0;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	for (int i = 0; i < n; i++) {
		if ((x == y) and (flag)) {
			if ((flag == 1) && (s[i] == 'R')) {
				ans++;
				x++;
				flag = 2;
			}
			else if ((flag == 2) && (s[i] == 'U')) {
				ans++;
				y++;
				flag = 1;
			}
			else if ((flag == 1) && (s[i] == 'U')) {
				y++;
			}
			else if ((flag == 2) && (s[i] == 'R')) {
				x++;
			}
		}
		else {
			if (s[i] == 'R') {
				if (y > x) {
					flag = 1;
				}
				else if (y < x) {
					flag = 2;
				}
				x++;
			}
			else {
				if (y > x) {
					flag = 1;
				}
				else if (y < x) {
					flag = 2;
				}
				y++;
			}
		}
	}
	std::cout << ans;
}