#include <iostream>
#include <vector>

int main()
{
    std::vector<int> mass;
    std::vector<int> schet(1001);
    std::vector<int> ans;
    int n = 0;
    int x = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        mass.push_back(x);
        schet[x] += 1;
    }
    for (int i = 0; i < n; i++) {
        if (schet[mass[i]] > 1) {
            schet[mass[i]] -= 1;
        } else {
            ans.push_back(mass[i]);
        }
    }
    std::cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << ' ';
    }
}
