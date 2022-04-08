// Franchesca Lazaro
// HW1 - Classes

// Includes
#include <stdio.h>
#include <iostream>
#include <assert.h>
#include "Library.h"
using namespace std;

// A method that calls and tests all the methods.
void Test1()
{
    Library libs("Franchesca's Library");
    libs.AddBook("Don Quixote");
    libs.AddBook("In Search of Lost Time");
    libs.AddBook("Ulysses");
    libs.AddBook("The Odyssey");
    libs.ListAllBooks();
    bool result = libs.IsInLibrary("The Odyssey");
    assert(result);
    result = libs.AddBook("The Odyssey");
    assert(!result);
    result = libs.RemoveBook("The Odyssey");
    assert(result);
    result = libs.IsInLibrary("The Odyssey");
    assert(!result);
    result = libs.RemoveBook("The Odyssey");
    assert(!result);
}

// A method to call Test1() and to state that the tests were completed.
void TestAll()
{
    Test1();
    cout << "Successfully completed all tests." << endl;
}

int main()
{
    TestAll();
    return 0;
}
