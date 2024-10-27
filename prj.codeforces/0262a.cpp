#include <iostream>
#include <vector>
 
int main()
{
    int n,k,x;
    std::cin >> n >> k;
    std::vector<int> mass;
    for (int i = 0;i < n; i++) {
        std::cin >> x;
        mass.push_back(x);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int kolvo = 0;
        int l = mass[i];
        while (l != 0) {
            if (((l % 10) == 4) || ((l % 10) == 7)) {
                kolvo++;
            }
            l /= 10;
        }
        if (kolvo <= k) {
            ans++;
        }
    }
    std::cout << ans;
}
