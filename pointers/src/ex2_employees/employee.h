/*******************************************************************************
 *
 *  ADS Workshop 1 // Employees Problem
 *
 *  Definitions of custom datatypes.
 *
 ******************************************************************************/

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <map>
#include <string>
#include <utility>
#include <vector>

struct Employee {
    std::string name;
    int age;
    std::vector<double> wages;
};

struct EmployeeRegister;

struct EmployeeRegister {
    std::map<std::string, Employee*> mapOfEmp; //TODO: typedef alias

//    Employee createNewEmployee(std::string n, int a, std::vector<double> w)
//    {
//        Employee newEmp;
//        newEmp.name = n;
//        newEmp.age = a;
//        newEmp.wages = w;
//        return newEmp;
//    }

    // method does not set the instance's state so it must be marked as const
    size_t getCount() const
    {
        return mapOfEmp.size();
    }

    void freeAll()
    {
        for (const std::pair<std::string, Employee*>& el : mapOfEmp )
        {
            delete el.second;
        }
        mapOfEmp.clear();
    }

    ~EmployeeRegister()
    {
        freeAll();
    }

    Employee* createNewEmployee(const std::string& name, int age, const std::vector<double>& wages);

//    The first implementation iterates over all the objects into the internal map structure and looks for an appropriate object
//    Employee* findEmployee(std::string n)
//    {
//        Employee* wantedPointer = nullptr;
//        for(auto& item : mapOfEmp)
//        {
//            if (item.first == n)
//            {
//                wantedPointer = item.second;
//            }
//        }
//        return wantedPointer;
//    }

//    The second implementation uses map features (fast key lookup) for getting access to the Employee object.
    //TODO: separate interface and implementation
    Employee* findEmployee(const std::string& n)
    {
        std::map<std::string, Employee*>::iterator it = mapOfEmp.find(n);
        if (it == mapOfEmp.end())
            return nullptr;
        return it->second;
    }

    Employee** exportEmployeesAsArray(size_t& numOfElements);
//    void exportEmployeesAsArray() {
//        Employee* *employees = new Employee* [mapOfEmp.size()];
//        // Employee* emp = nullptr;
//        std::map<std::string, Employee* >::iterator it = mapOfEmp.begin();
//        for (int i = 0; i != sizeof(mapOfEmp) && it != mapOfEmp.end(); i++) {
//            employees[i] = it->second;
//            it++;
//        }
//    }
}; // struct Employee

struct EmployeeRegister;

////creates and adds a new Employee object and initializes it with given parameters
//Employee* createNewEmployee(EmployeeRegister& reg, const std::string& name, int age, const std::vector<double>& wages);
#endif // EMPLOYEE_H
