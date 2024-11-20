#include <arrayd/arrayd.hpp>
#include <iostream>

int main() {
    dynarr arr;

    std::cout << "Adding elements to the array...\n";
    arr.pushBack(5);
    arr.pushBack(10);
    arr.pushBack(15);

    std::cout << "Current elements:\n";
    for (size_t i = 0; i < arr.getSize(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Removing the last element...\n";
    arr.popBack();

    std::cout << "Current elements:\n";
    for (size_t i = 0; i < arr.getSize(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    try {
        std::cout << "Accessing element at index 5 (out of range)...\n";
        std::cout << arr[5] << "\n";
    }
    catch (const std::out_of_range& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    std::cout << "Clearing the array...\n";
    arr.clear();
    std::cout << "Size after clear: " << arr.getSize() << "\n";

    return 0;
}
