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


// The definition of the Employee structure.
struct Employee {
    std::string name;
    int age;
    std::vector<double> wages;
};



// an example of forward declaration (https://en.cppreference.com/w/cpp/language/class)
struct EmployeeRegister;

// The real definition of the EmployeeRegister structure.
struct EmployeeRegister {
    //==-- types definition go first --==

    // BAD: using cumbersome type identifier
        //std::map<std::string, Employee*> mapOfEmp; //TODO: typedef alias

    // BETTER: using an alias
    typedef std::map<std::string, Employee*> StrEmployeeMap;
    typedef std::pair<std::string, Employee*> StrEmployeeMapEl;

    //==-- then we have public fields definitions (in structures only!) --==
    StrEmployeeMap mapOfEmp;

    //==-- then we have constructors and destructor --==
    ~EmployeeRegister()
    {
        freeAll();
    }

    //==-- finaly, other methods --==

    // correctly clears all the registerd employees
    void freeAll();

    // Returns the number of registered employees.
    //
    // 1) Method does not set the instance's state so it must be marked as const
    // 2) The definition of this method is provided here, because it's pretty little
    // and could be considered by the compiler as inline
    // https://www.learncpp.com/cpp-tutorial/89-class-code-and-header-files/
    size_t getCount() const
    {
        return mapOfEmp.size();
    }

    Employee* createNewEmployee(const std::string& name, int age,
                                const std::vector<double>& wages);

    //  The second implementation uses map features (fast key lookup) for getting
    //  access to the Employee object.
    // DONE: separate interface and implementation
    Employee* findEmployee(const std::string& name);

    // Exports a collection employess as an array of pointers.
    Employee** exportEmployeesAsArray(size_t& numOfElements);


    //==-- dead code --==

    // wrong approach
        //    Employee createNewEmployee(std::string n, int a, std::vector<double> w)
        //    {
        //        Employee newEmp;
        //        newEmp.name = n;
        //        newEmp.age = a;
        //        newEmp.wages = w;
        //        return newEmp;
        //    }


    // BAD approach: map allows to pick up an element for log(n) instead of n
        //    The first implementation iterates over all the objects into the
        //    internal map structure and looks for an appropriate object
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
}; // struct Employee


// just an example that we can have more than one forward declarations
struct EmployeeRegister;


// creates and adds a new Employee object and initializes it with given parameters
// Employee* createNewEmployee(EmployeeRegister& reg, const std::string& name,
//    int age, const std::vector<double>& wages);


#endif // EMPLOYEE_H
