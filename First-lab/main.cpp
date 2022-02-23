#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <windows.h>
#include "employee.h"

bool createBinFile(std::string fileName, int count) {
    STARTUPINFO si;
    PROCESS_INFORMATION piApp;
    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);
    char num[10];
    itoa(count, num, 10);
    std::string arg = "Creator.exe " + std::string(num) + " " + fileName;
    char args[255];
    strcpy(args, arg.c_str());
    bool isStarted = CreateProcess(NULL, args, NULL,
                                   NULL, FALSE, CREATE_NEW_CONSOLE,
                                   NULL, NULL, &si, &piApp);
    WaitForSingleObject(piApp.hProcess, INFINITE);
    CloseHandle(piApp.hThread);
    CloseHandle(piApp.hProcess);
    return isStarted;
}

int main(int argc, char *argv[]) {
    std::cout << "Input initial filename: ";
    std::string initialFileName;
    std::cin >> initialFileName;

    std::ofstream out;

    std::cout << "Input number of records in file: ";
    int recordsNumber;
    std::cin >> recordsNumber;

    bool isCreate = createBinFile(initialFileName, recordsNumber);
    if(isCreate) {
        system("cls");
        std::cout << "File " << initialFileName << " created.";
    }

    system("pause");
    return 0;
}