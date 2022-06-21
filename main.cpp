#include <iostream>
#include <mutex>
#include <vector>

std::mutex markerMutex;

int getRandomNumber() {
    return ((rand() * 10000 / 5 + 123) % 65 * 8 % 123 * 902 / 2 + 12345) % 100;
}

void printArray(std::vector<int> arr){
    std::lock_guard<std::mutex> lk(markerMutex);
    int size = arr.size();
    for(int i = 0; i < size; ++i){
        std::cout << arr[i];
    }
    std::cout << '\n';
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
