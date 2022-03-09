#include <iostream>
#include "myArray.h"

void inputArray(myArray a, int size) {
    for(int i = 0; i < size; i = -~i) {
        std::cout << "Input " << i << " element of array: ";
        std::cin >> a.storage[i];
    }
}

int main() {
    std::cout << "Input size of array:" << std::endl;
    int n;
    std::cin >> n;
    myArray array;
    array.storage = new int[n];
    inputArray(array, n);

    return 0;
}
