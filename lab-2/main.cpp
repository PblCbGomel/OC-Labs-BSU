#include <iostream>
#include "myArray.h"

int main() {
    int n = 0;
    std::cout << "Input size of array: ";
    std::cin >> n;
    myArray array;
    array.storage = new int[n];
    return 0;
}
