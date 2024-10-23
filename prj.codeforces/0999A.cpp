#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n = 0, k = 0, x = 0;
    int ans = 0;
    int ind = n - 1;
    bool flag = true;
    std::cin >> n >> k;
    std::vector<int> mass;
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        mass.push_back(x);
        if ((x <= k) && (flag)) {
            ans++;
            ind = i;
        }
        else if ((x > k) && (flag)) {
            flag = false;
        }
    }
    int j = n - 1;
    if (ind != n - 1) {
        while (mass[j] <= k) {
            ans++;
            j--;
        }
    }
    std::cout << ans;

}
