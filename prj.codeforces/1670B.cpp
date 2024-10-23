#include <iostream>
#include <string>

int main()
{
    int t = 0;
    int n = 0;
    int k = 0;
    std::string s;
    char x;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        std::cin >> n;
        std::cin >> s;
        std::cin >> k;
        for (int j = 0; j < k; j++) {
            std::cin >> x;
            for (int l = 0; l < s.size(); l++) {
                if (s[l] == x) {
                    s[l] = '0';
                }
            }
        }
        int ans = 0;
        int l = 0, r = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                ans = std::max(ans, r - l);
                l = r;
                r = i;
            }
        }
        std::cout << std::max(ans, r - l) << '\n';
    }
}
