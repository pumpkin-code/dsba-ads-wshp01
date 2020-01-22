/*******************************************************************************
 *
 *  ADS Workshop 1 // Employees Problem
 *
 *  Implementations of custom datatypes.
 *
 ******************************************************************************/

#include "employee.h"

Employee* EmployeeRegister::createNewEmployee(const std::string& name, int age,
                                              const std::vector<double>& wages)
{
    // Employee e;
    std::map<std::string, Employee*>::iterator it = mapOfEmp.find(name);
    if (it != this->mapOfEmp.end()) // "this" is not needed
    {
        return it->second;
    }
//    reg.mapOfEmp[name] =
    Employee* em = new Employee(); // creating in the heap
    em->name = name;
    em->age = age;
    // em->wages = age;
    /*this->*/mapOfEmp.insert({name, em});
    return em;
    // eventually we will delete em;
}

Employee* EmployeeRegister::findEmployee(const std::string& name)
{
    std::map<std::string, Employee*>::iterator it = mapOfEmp.find(n);
    if (it == mapOfEmp.end())
        return nullptr;
    return it->second;
}


Employee** EmployeeRegister::exportEmployeesAsArray(size_t& numOfElements)
{
    numOfElements = mapOfEmp.size();
    Employee** arr = new Employee* [numOfElements];



    //TODO: finish up with this method



}

void EmployeeRegister::freeAll()
{
    // awkward
        //for (const std::pair<std::string, Employee*>& el : mapOfEmp )
    // better
    for (const StrEmployeeMapEl& el : mapOfEmp )
    {
        delete el.second;
    }
    mapOfEmp.clear();
}



// It was a free method.
// Employee* createNewEmployee(EmployeeRegister& reg, const std::string& name,
//    int age, const std::vector<double>& wages)
// {
//     // Employee e;
//     std::map<std::string, Employee*>::iterator it = reg.mapOfEmp.find(name);
//     if (it != reg.mapOfEmp.end())
//     {
//         return it->second;
//     }
// //    reg.mapOfEmp[name] =
//     Employee* em = new Employee(); // creating in heap
//     em->name = name;
//     em->age = age;
//     // em->wages = age;
//     reg.mapOfEmp.insert({name, em});
//     return em;
//     // eventually we will delete em;
// }

