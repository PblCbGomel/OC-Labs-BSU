#include <iostream>

struct employee {
    int num;
    char name[10];
    double hours;

    void print(){
        std::cout << "ID: " << num << "\tName: " << name
            << "\tHours: " << hours << '\n';
    }
};

#ifndef LAB5_EMPLOYEE_H
#define LAB5_EMPLOYEE_H

#endif //LAB5_EMPLOYEE_H
