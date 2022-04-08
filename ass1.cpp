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
    libs.AddBook("The Secret History");
    libs.AddBook("Basara Volume 1");
    libs.AddBook("Phantom of the Opera");
    libs.AddBook("Dante's Inferno");
    libs.ListAllBooks();
    bool result = libs.IsInLibrary("Dante's Inferno");
    assert(result);
    result = libs.AddBook("Dante's Inferno");
    assert(!result);
    result = libs.RemoveBook("Dante's Inferno");
    assert(result);
    result = libs.IsInLibrary("Dante's Inferno");
    assert(!result);
    result = libs.RemoveBook("Dante's Inferno");
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
