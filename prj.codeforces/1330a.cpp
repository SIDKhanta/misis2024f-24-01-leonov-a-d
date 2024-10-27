#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int t;
    int n, x;
    std::cin >> t;
    std::vector<int> mass;
    for (int i = 0; i < t; i++) {
        std::cin >> n >> x;
        std::vector<int> schet(101);
        int mx = 0, ind = 0;
        int l;
        for (int i = 0; i < n; i++) {
            std::cin >> l;
            if (schet[l] == 0) {
                mass.push_back(l);
            }
            schet[l] = 1;
        }
        std::sort(mass.begin(), mass.end());
        for (int j = 0; j < mass.size(); j++) {
            if (x - mass[j] + j + 1 >= 0) {
                mx = mass[j];
                ind = j;
            }
        }
        if (mx == 0) {
            std::cout << x << '\n';
        }
        else {
            std::cout << x + ind + 1 << '\n';
        }
        mass.clear();
        schet.clear();
    }
}
