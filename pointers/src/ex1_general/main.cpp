/*******************************************************************************
 *
 *  ADS Workshop 1 example 1
 *
 *  Solve differents tasks related to dealing with pointer.
 *  Follow the instructions of a workshop presenter.
 *
 ******************************************************************************/

#include <iostream>
#include <cassert>              // for assert macro

using std::cout;
using std::cin;

void example1()
{
    int a = 0xBBAA4513;
    // red = operator
    // green = type modificator
    int* ptrA = &a;
    int** ptr2A = &ptrA;
    // we can have many *
    *ptrA +=1;
    **ptr2A +=1;
    int& anotherA = a;
    ++ anotherA;
    int& bnother = *ptrA;
    // we only can have 1 &
    
    int b = 8;
    // int q = (long)&a;
    // int q = static_cast<long> (&a);
}

// the entrypoint of the application
int main()
{
    example1();
//    cout << "Hello world!\n\n";
//    cout << "\n\n";

    return 0;
}
