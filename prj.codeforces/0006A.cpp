#include <iostream>

int TRIANGLE(int a, int b, int c, int d) {
	return (((a + b > c) && (a + c > b) && (b + c > a)) || ((a + c > d) && (a + d > c) && (c + d > a)) || ((a + b > d) && (a + d > b) && (b + d > a)) || ((b + c > d) && (b + d > c) && (c + d > b)));
}

int SEGMENT(int a, int b, int c, int d) {
	return ((a + b == c) || (a + c == b) || (b + c == a) || (a + c == d) || (a + d == c) || (c + d == a) || (a + b == d) || (a + d == b) || (b + d == a) || (b + c == d) || (b + d == c) || (c + d == b));
}

int main() {
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	std::cin >> a >> b >> c >> d;
	if (TRIANGLE(a, b, c, d)) {
		std::cout << "TRIANGLE";
	}
	else if (SEGMENT(a, b, c, d)) {
		std::cout << "SEGMENT";
	}
	else {
		std::cout << "IMPOSSIBLE";
	}
}
