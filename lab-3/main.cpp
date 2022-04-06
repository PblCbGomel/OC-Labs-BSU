#include <iostream>
#include <time.h>
#include <vector>
#include <windows.h>
#include <process.h>


int main() {
    std::cout << "Input size of array: ";
    int n;
    std::cin >> n;
    int *arr = new int[n];

    for(int i = 0; i < n; i = -~i) {
        arr[i] = 0;
    }

    std::cout << "Array of " << n << " element has been created.\nInput number of thread: ";
    int stremsCount;
    std::cin >> stremsCount;
    HANDLE startThreadsEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
    HANDLE currentThread;
    std::vector<HANDLE> threads;

    return 0;
}