// Includes
#include "Library.h"
#include <iostream>
using namespace std;

// Constructor
Library::Library(string name)
{
    LibraryName = name;
}

// This method is mainly responsible for telling the user if their book was successfully added to the library.
bool Library::AddBook(const string &name)
{
    // This if uses FindBook to know whether or not a book should be added to the library.
    if (FindBook(name) == -1)
    {
        // If there is no duplicate, the function will call on another functio, AddBookToList, to add the book to the library.
        AddBookToList(name);
        cout << "MESSAGE: Added " << name << " to your library." << endl;
        return true;
    }
    // If there is a duplicate, the function will tell the user that there is an already existing book in the library.
    // Therefore, the function will not add the book to the library.
    cout << "MESSAGE: " << name << " is already in your library." << endl;
    return false;
}

// This method is mainly responsible for telling the user if their book was successfully removed from the library.
bool Library::RemoveBook(const string &name)
{
    // This if uses FindBook to know whether or not a book should be removed from the library.
    if (FindBook(name) > -1)
    {
        // If the book is in the library, the function will remove the book from the library by calling on another function,
        // RemoveBookFromList, to remove the book from the library.
        RemoveBookFromList(name);
        cout << "MESSAGE: " << name << " was sucessfully removed from your library." << endl;
        return true;
    }
    // If the book isn't in the library, the function will let the user know there has been an error in removing the book.
    // No removal of a book will be made.
    cout << "MESSAGE: Removal of " << name << " was unsuccessful." << endl;
    return false;
}

// This function is responsible for actually removing the book from the array.
void Library::RemoveBookFromList(const string name)
{
    // Temp is used to make a temporary variable for storing the result of calling FindBook.
    int temp = FindBook(name);
    // PreviousNumBooks is used for finding the last book in the library/the last entry in the array.
    int PreviousNumBooks = NumBooks - 1;
    // If temp is more than -1, that means the book is in the library.
    if (temp > -1)
    {
        // The for loop is used to iterate through the library.
        for (int i = 0; i < NumBooks; i++)
        {
            // The if checks to see which index holds the same content as the name of the book given.
            if (LibraryList[i] == name)
            {
                // Then the function assigns the value of the index to the value of the last index in the library array.
                LibraryList[i] = LibraryList[PreviousNumBooks];
                // Lastly, the function decreases the size of the array.
                NumBooks = NumBooks - 1;
            }
        }
    }
    // If temp is less than or equal to -1, no book will be removed from the library.
    // The reason being is because the book does not exist in the library.
}

// This function is responsible for actually adding the book to the array by assigning a value in the array to the book requested.
// Then the function goes to the next "space" in the array for the next book to be stored.
void Library::AddBookToList(const string name)
{
    LibraryList[NumBooks] = name;
    NumBooks++;
}

// This function is used for listing all the books contained in the library.
void Library::ListAllBooks() const
{
    cout << "Your library contains: " << endl;
    for (int i = 0; i < NumBooks; i++)
    {
        cout << "---> " << LibraryList[i] << endl;
    }
}

// This function is used for letting the user know if the book is in the library or not depending on the result of FindBook.
bool Library::IsInLibrary(const string &name) const
{
    if (FindBook(name) > -1)
    {
        cout << "MESSAGE: " << name << " is already in your library." << endl;
        return true;
    }
    cout << "MESSAGE: " << name << " is not in your library." << endl;
    return false;
}

// This function is used for finding a book in the library.
int Library::FindBook(const string &name) const
{
    for (int i = 0; i < NumBooks; i++)
    {
        // While the for loop is looping, it's checking to see if the book listed is in the library.
        // If the book is in the library, it will return the index.
        if (LibraryList[i] == name)
        {
            return i;
        }
    }
    // If the book is not in the library, the function will return -1.
    return -1;
}

// This operation overload is responsible for printing out the contents of the library if the user were to
// print out the object.
ostream &operator<<(ostream &out, const Library &lib)
{
    out << "Library: " << lib.LibraryName << endl;
    out << "Your library contains: " << endl;
    for (int i = 0; i < lib.NumBooks; i++)
    {
        out << "---> " << lib.LibraryList[i] << endl;
    }
    return out;
}
