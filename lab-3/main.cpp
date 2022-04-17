#include <iostream>
#include <time.h>
#include <vector>
#include <windows.h>
#include <process.h>
#include "thread.h"

void printArr(int* arr, int size) {
    for(int i = 0; i < size; i = -~i) {
        std::cout << arr[i];
    }
}


int main() {
    std::cout << "Input size of array: ";
    int n;
    std::cin >> n;
    int *arr = new int[n];

    for(int i = 0; i < n; i = -~i) {
        arr[i] = 0;
    }

    std::cout << "Array of " << n << " element has been created.\nInput number of thread: ";
    int threadsCount;
    std::cin >> threadsCount;
    HANDLE threadStartEv = CreateEvent(NULL, TRUE, FALSE, NULL), currTh;
    std::vector<HANDLE> threads;
    std::vector<threadArgs*> argsVector;
    threadArgs* currArgs;
    std::vector<HANDLE> thEvents;
    bool* terminated = new bool[threadsCount];
    for(int i = 0; i < threadsCount; i = -~i){
        currArgs = new threadArgs(arr, n, -~i);
        //currTh = (HANDLE)_beginthreadex(NULL, 0, marker, currArgs, 0, NULL);
        terminated[i] = false;
        thEvents.push_back(CreateEvent(NULL, TRUE, FALSE, NULL));
        argsVector.push_back(currArgs);
        threads.push_back(currTh);
    }
    return 0;
}