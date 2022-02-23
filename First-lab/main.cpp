#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <iomanip>
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

void printFromBinFile(std::string fileName) {
    std::ifstream in(fileName.c_str(), std::ios::in|std::ios::binary|std::ios::ate);
    in.seekg(0, std::ios::end);
    int n = in.tellg()/sizeof(employee);
    in.seekg(0, std::ios::beg);
    employee* emps = new employee[n];
    in.read((char*)emps, n*sizeof(employee));
    in.close();
    for(int i = 0; i < n; i++){
        std::cout << std::setw(5) << emps[i].num
             << std::setw(10) << emps[i].name
             << std::setw(5)<< emps[i].hours << '\n';
    }
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
        std::cout << "File " << initialFileName << " created.\n";
        printFromBinFile(initialFileName);
        std::string recorderFile;
        std::cout << "Input recorder file name: ";
        std::cin >> recordsNumber;
    }

    system("pause");
    return 0;
}