#include <iostream>

int main() {
    int n = 0, k = 0, ans = 0, mn_el = 1000000;
    std::cin >> n >> k;
    int x = 0;
    int first_el = 0;
    bool zero_flag = false;
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        if (x == 0) {
            zero_flag = true;
        }
        if (x > 0) {
            k %= 2;
        }
        if ((x < 0) && (k > 0)) {
            ans += (-1) * x;
            k -= 1;
        }
        else {
            ans += x;
        }
        if (abs(x) < mn_el) {
            mn_el = abs(x);
        }
    }
    k %= 2;
    if ((k) && (!zero_flag)) {
        ans -= 2 * mn_el;
    }
    std::cout << ans;
}
