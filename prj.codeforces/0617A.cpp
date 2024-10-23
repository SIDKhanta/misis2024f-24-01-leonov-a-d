#include <iostream>
 
int main()
{
    int x;
    std::cin >> x;
    if (x <= 5) {
        std::cout << 1;
    }   
    else {
        std::cout << ((x - 1) / 5 + 1);
    }
}
