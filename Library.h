// Includes
#include <iostream>
#ifndef LIBRARY_H
#define LIBRARY_H
using namespace std;

class Library
{
public:
    // Members
    static const int MAX = 100;

    // Methods
    // Constructor
    Library(const string name);

    // Add a new book
    // Return true for success, false if book is already in library
    bool AddBook(const string &name);

    // Remove a book
    // Return true for success, false if book is not in library
    bool RemoveBook(const string &name);

    // List all books in library
    void ListAllBooks() const;

    // Return true if book in library, false otherwise
    bool IsInLibrary(const string &name) const;

    // Friend function: this allows outside methods to directly access private members in the library class
    friend ostream &operator<<(ostream &out, const Library &lib);

    // To know whether or not a book exists in the library
    int FindBook(const string &name) const;

private:
    // Members
    // Name of the library
    string LibraryName;

    // Number of books in the library
    int NumBooks = 0;

    // Array
    string LibraryList[MAX];

    // Methods
    // This method is the one actually responsible for adding a book to the private array.
    void AddBookToList(const string name);

    // This method is the one actually responsible for removing a book from the private array.
    void RemoveBookFromList(const string name);
};
#endif
