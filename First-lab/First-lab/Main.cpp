#include<iostream>
#include<fstream>
#include<string>
#include "Creator.h"

int main() {
	std::cout << "Input initial filename: ";
	std::string initialFileName;
	std::cin >> initialFileName;
	std::cout << "Input number of records in file: ";
	int recordsNumber;
	std::cin >> recordsNumber;

	std::ofstream out;
	createBinFile(initialFileName, out);

	if(!out.is_open()) {
		std::cerr << "Open file failed.\n";
		return 0;
	} else {
		std::cout << "File is open.\n";	
	}

	system("pause");
	return 0;
}