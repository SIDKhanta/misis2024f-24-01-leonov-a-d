#include <iostream>
#include <cmath>

int main()
{
    int t = 0;
    std::cin >> t;
    double a, b, c;
    for (int i = 0; i < t; i++) {
        std::cin >> a >> b >> c;
        double ans = ceil((abs(a - b) * 1.0 / 2) / c);
        if (a != b) { 
            std::cout << ans << '\n';
        } else {
            std::cout << 0 << '\n';
        }
    }
}
