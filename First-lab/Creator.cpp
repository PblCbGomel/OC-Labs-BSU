#include<iostream>
#include<fstream>
#include<string>
#include "employee.h"

void createBinFile(std::string fileName, std::ofstream& out) {
    out.open(fileName.c_str(), std::ios::binary|std::ios::app);
}

void writeOnBinFile(std::string fileName, employee elem) {
    std::ofstream out(fileName.c_str(), std::ios::binary|std::ios::app);
    out.write((char*)&elem, sizeof(elem));
    out.close();
}

void readFromFile(std::string fileName, employee elements[], int num) {
    
}
