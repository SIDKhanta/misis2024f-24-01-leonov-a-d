#include <iostream>
#include <string>
int main() {
    int t = 0;
    int ans = 0;
    int x = 0, y = 0;
    std::string s;
    std::cin >> t;
    for (int k = 0; k < t; k++) {
        ans = 0;
        for (int i = 0; i < 10; i++) {
        std::cin >> s;
        if (i >= 5) {
            x = 4 - i % 5;
        }
        else {
            x = i % 5;
        }
            for (int j = 0; j < 10; j++) {
                if (j >= 5) {
                    y = 4 - j % 5;
                }
                else {
                    y = j % 5;
                }
                if (s[j] == 'X') {
                    ans += std::min(x,y) + 1;
                }
            }
            
        }
        std::cout << ans << '\n';
    }
}
