#include<iostream>
#include<fstream>
#include<string>

void createBinFile(std::string fileName, std::ofstream& out) {
	out.open(fileName.c_str(), std::ios::binary);
}