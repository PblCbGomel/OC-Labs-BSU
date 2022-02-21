#include<iostream>
#include<fstream>
#include<string>
#include <cstdlib>
#include "Creator.h"
#include "employee.h"

int main() {
    std::cout << "Input initial filename: ";
    std::string initialFileName;
    std::cin >> initialFileName;

    std::ofstream out;
    createBinFile(initialFileName, out);

    if(!out.is_open()) {
        std::cerr << "Open file failed.\n";
        return 0;
    } else {
        std::cout << "File is open.\n";
        int workTemp = 0;
        while(workTemp != 2) {
            std::cout << "Input 1 to input records in file, 2 to continue: ";
            std::cin >> workTemp;
            if(workTemp == 1) {
                std::cout << "Input number of records what you wont to write: ";
                int recordsNumberToWrite;
                std::cin >> recordsNumberToWrite;
                std::cout << "Input all records.\n";
                for(int i = 0; i < recordsNumberToWrite; ++i) {
                    std::cout << i + 1 << ") ";
                    std::string tempStr;
                    std::cin >> tempStr;
                    int num_ = atoi(tempStr.c_str());
                    std::cin >> tempStr;
                    char *name_;
                    strcpy(name_, tempStr.c_str());
                    std::cin >> tempStr;
                    double hours_ = atof(tempStr.c_str());
                    employee e1(num_, name_, hours_);
                    e1;
                }
            }
        }
        system ("cls");

        std::cout << "Input number of records in file: ";
        int recordsNumber;
        std::cin >> recordsNumber;
    }

    system("pause");
    return 0;
}