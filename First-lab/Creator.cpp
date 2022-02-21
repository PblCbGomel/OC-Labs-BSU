#include<iostream>
#include<fstream>
#include<string>
#include "employee.h"

void createBinFile(std::string fileName, std::ofstream& out) {
    out.open(fileName.c_str(), std::ios::binary);
}

void writeOnBinFile(std::string fileName, employee elem) {

}