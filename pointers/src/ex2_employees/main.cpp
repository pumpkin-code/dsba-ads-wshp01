/*******************************************************************************
 *
 *  ADS Workshop 1 // Employees Problem
 *
 *  Solve the problem according instructions in file "Workshops ADS-1, 2.pdf"
 *
 ******************************************************************************/

#include <iostream>
#include <cassert>              // for assert macro
#include "employee.h"

using std::cout;
using std::cin;

void sample1()
{
    {
        EmployeeRegister someRegister;
        std::vector<double> dummy;
        someRegister.createNewEmployee("Ivan", 30, dummy);
        someRegister.createNewEmployee("Ivan1", 31, dummy);
        someRegister.createNewEmployee("Ivan2", 32, dummy);
//    createNewEmployee(someRegister, "Ivan", 30, dummy);
//    createNewEmployee(someRegister, "Ivan1", 31, dummy);
//    createNewEmployee(someRegister, "Ivan2", 32, dummy);
        assert(someRegister.getCount() == 3);
    }
}

// the entrypoint of the application
int main()
{
    sample1();
    cout << "Hello world!\n\n";
    cout << "\n\n";

    return 0;
}
