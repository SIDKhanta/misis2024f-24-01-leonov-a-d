#include <iostream>
#include <string>

int main()
{
    int x = 0;
    std::cin >> x;
    std::string s;
    std::cin >> s;
    int count = 0;
    int i = 1;
    while (i < s.size() - 1) {
        if (s[i - 1] == 'x' && s[i + 1] == 'x' && s[i] == 'x') {
            s = s.erase(i - 1, 1);
            count++;
        }
        else {
            i++;
        }
    }
    std::cout << count;
}
