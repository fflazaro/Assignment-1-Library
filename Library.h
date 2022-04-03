#include <iostream> 
using namespace std; 

//Constants 
static const int MAX = 100; 

//Add a new book
//Return true for sucess, false if book is already in library
bool AddBook(const string &name); 

//Remove a book
//Return true for success, false if book is not in library
bool RemoveBook(const string &name); 

//List all books in library
void ListAllBooks() const; 

//Return true if book in library, false otherwise 
bool IsInLibrary(const string &name) const;
 
//Friend function: this allows outside methods to directly access private members in the library class
friend ostream &operator<<(ostream &out, const Library &lib); 

//To know whether or not a book exists in the library 
int FindBook (const string &name) const; 