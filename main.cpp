#include <iostream>
#include <mutex>
#include <vector>
#include <condition_variable>
#include "thread.h"

std::mutex markerMutex;
std::mutex startMutex;

std::condition_variable startCV;
std::condition_variable stateChanged;

bool ready;
std::vector<bool> threadsPaused;

int getRandomNumber(int arg) {
    srand(time(NULL));
    return ((rand() * 10000 / 5 + 123) % 65 * 8 % 123 * 902 / 2 + 12345) % arg;
}

void printArray(std::vector<int> arr){
    std::lock_guard<std::mutex> lk(markerMutex);
    int size = arr.size();
    for(int i = 0; i < size; ++i){
        std::cout << arr[i];
    }
    std::cout << '\n';
}

bool allPaused(bool* arr, int n){
    for(int i = 0; i < n; i++){
        if(!arr[i])
            return false;
    }
    return true;
}

void marker(threadArgs* args){
    std::unique_lock<std::mutex> startlk(startMutex);
    startCV.wait(startlk, []()->bool{return ready;});
    startlk.unlock();
    std::cout << "Thread " << args->num << " has been started.\n";

    int count = 0;
    while (true) {
        std::unique_lock<std::mutex> lk(markerMutex);
        int i = getRandomNumber(args->n);

        if (args->arr[i] != 0) {
            std::cout << "Thread №" << args-> num << ", marked " << count << "elements, " << " unable to mark №" << i << '\n';

            threadsPaused[args->num - 1] = true;
            stateChanged.notify_all();
            lk.unlock();
            std::unique_lock<std::mutex> actionLock(args->actionMutex);
            
            args->doAction.wait(actionLock, [=]()->bool{return args->actions[1] || args->actions[0];});

            if(args->actions[1]){
                for(int i = 0; i < args->n; ++i) {
                    if (args->arr[i] == args->num) {
                        args->arr[i] = 0;
                    }
                }

                std::cout << "Thread" << args->num << "has been terminated.";
                break;
            }

            args->actions[0] = false;
        } else{
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
            ++count;
            args->arr[i] = args->num;
            lk.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
