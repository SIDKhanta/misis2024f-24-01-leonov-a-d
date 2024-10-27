#include <iostream>
 
int main()
{
    int x;
    std::cin >> x;
    x += 1;
    bool flag = true;
    while (flag) {
        int a,b,c,d;
        a = x / 1000;
        b = (x / 100) % 10;
        c = (x / 10) % 10;
        d = x % 10;
        if ((a != b) && (a != c) && (a != d) && (b != c) && (b != d) && (c != d)) {
            std::cout << x;
            flag = false;
        }
        x += 1;
    }
}
