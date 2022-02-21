#pragma once
#ifndef CREATOR_H
#define CREATOR_H

#include <string>
#include "employee.h"

void createBinFile(std::string fileName, std::ofstream& out);
void writeOnBinFile(std::string fileName, employee elem);

#endif