#include <iostream>

int main() {
	int t = 0;
	std::cin >> t;
	int n, m, sx, sy, d;
	while(t --) {
	    std::cin >> n >> m >> sx >> sy >> d;
	    if((sy - d <= 1 && sx - d <= 1) || (sx + d >= n && sy + d >= m)) {
	        std::cout << "-1\n";
	    }
	    else if((sx - d <= 1 && sx + d >= n) || (sy - d <= 1 && sy + d >= m)) {
	        std::cout << "-1\n";
	    }
	    else {
	        std::cout << n - 1 + m - 1 << "\n";
	    }
	}
}
