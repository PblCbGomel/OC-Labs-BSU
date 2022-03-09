#include <iostream>
#include "myArray.h"
#include <windows.h>
#include <process.h>

void inputArray(myArray a, int size) {
    for(int i = 0; i < size; i = -~i) {
        std::cout << "Input " << i + 1 << " element of array: ";
        std::cin >> a.storage[i];
    }
}

UINT WINAPI min_max(void* temp){
    myArray* array = static_cast<myArray*>(temp);
    int maxI = 0;
    int minI = 0;
    for(int i = 1; i < array->size; i = -~i) {
        if(array->storage[maxI] < array->storage[i]){
            maxI = i;
        }
        if(array->storage[minI] > array->storage[i]){
            minI = i;
        }
        Sleep(7);
    }
    std::cout << "Max element is: " << array->storage[maxI] << ", index: " << maxI << '\n';
    array->maxElement = maxI;
    std::cout << "Min element is: " << array->storage[minI] << ", index: " << minI << '\n';
    array->minElement = minI;
    return 0;
}

int main() {
    std::cout << "Input size of array: ";
    int n;
    std::cin >> n;
    
    myArray* array = new myArray();
    array->storage = new int[n];
    array->size = n;
    inputArray(*array, n);

    HANDLE handle_min_max =
            (HANDLE) _beginthreadex(NULL, 0, min_max, array, 0, NULL);
    if (handle_min_max == NULL) {
        return GetLastError();
    }
    WaitForSingleObject(handle_min_max, INFINITE);


    return 0;
}
