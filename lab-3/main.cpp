#include <iostream>
#include <time.h>
#include <vector>
#include <windows.h>
#include <process.h>
#include "thread.h"

HANDLE threadStartEv = CreateEvent(NULL, TRUE, FALSE, NULL), currTh;
std::vector<HANDLE> thEvents;
CRITICAL_SECTION CriticalS;
const int timeMs = 5;

UINT WINAPI marker(void *p) {
    threadArgs* p_ = static_cast<threadArgs*>(p);
    WaitForSingleObject(threadStartEv, INFINITE);
    std::cout << "Start " << p_->num << " thread.";
    int action = WaitForMultipleObjects(2,p_->actions, FALSE, INFINITE) - WAIT_OBJECT_0;

    int count = 0;
    while(action != 1) {
        EnterCriticalSection(&CriticalS);
        int i = ((rand() * 10000 / 5 + 123) % 65 * 8 % 123 * 902 / 2 + 12345) % 100;
        if(p_->arr[i] != 0){
            Sleep(timeMs);
            std::cout << "Thread #" << p_->num << ": Marked " << count << " elements, unable " << i << '\n';
            Sleep(timeMs);
            LeaveCriticalSection(&CriticalS);
            SetEvent(thEvents[-~p_->num]);
            Sleep(timeMs);
        } else {
            Sleep(timeMs);
            p_->arr[i] = p_->num;
            count = -~count;
            LeaveCriticalSection(&CriticalS);
            Sleep(timeMs);
        }
    }
    for(int i = 0; i < p_->n; i = -~i){
        if(p_->arr[i] == p_->num){
            p_->arr[i] = 0;
        }
    }
    std::cout << "Thread #" << p_->num << " has finished work.\n";

    return NULL;
}

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
    std::vector<HANDLE> threads;
    std::vector<threadArgs*> argsVector;
    threadArgs* currArgs;
    bool* terminated = new bool[threadsCount];
    for(int i = 0; i < threadsCount; i = -~i){
        currArgs = new threadArgs(arr, n, -~i);
        currTh = (HANDLE)_beginthreadex(NULL, 0, marker, currArgs, 0, NULL);
        terminated[i] = false;
        thEvents.push_back(CreateEvent(NULL, TRUE, FALSE, NULL));
        argsVector.push_back(currArgs);
        threads.push_back(currTh);
    }
    return 0;
}