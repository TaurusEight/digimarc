// Time-stamp: <2019-09-06 22:47:06 daniel>
// Author dmendyke [archadious@gmail.com]
//
// Developed for Digimarc
// Demostrates the idea of a copy move - added in C++11


// Required header files
//-----------------------------------------------------------------------------
#include <iostream>  // std, cout, endl


// NS Shortcuts
//-----------------------------------------------------------------------------
using namespace std;


// NS Wrapper around this example class
//-----------------------------------------------------------------------------
namespace dm {

  // Wrapper around an example of the use of C++11 Copy Constructor
  class example {
  public:
    example();
    example( example&& );
    ~example();
  protected:
  private:
    int* raw_pointer;
  };  // end class example

};  // end NS dm


// Constructor
// Allways allocates memory for 'raw_pointer' - then assigns it the value 8
//-----------------------------------------------------------------------------
dm::example::example() : raw_pointer{ nullptr } {

  // Note uses of the curly braces around the default value for raw_pointer

  cout << "Constructor: Allocating Heap memory" << endl;
  raw_pointer = new int;  // create an integer on the heap
  *raw_pointer = 8;  // fill it with an value

};  // end constructor


// Move Constructor
// Does not allocate memory for a new 'raw_pointer'
//-----------------------------------------------------------------------------
dm::example::example( dm::example&& original )
  : raw_pointer( move( original.raw_pointer ) ) {

  cout << "Move Constructor: No allocation of memory" << endl;

  // raw_pointer is moved without having to delete a copy
  original.raw_pointer = nullptr;

};  // move constructor


// Destructor
// Will only delete memory for 'raw_pointer' if the pointer is not null
//-----------------------------------------------------------------------------
dm::example::~example() {

  if ( raw_pointer != nullptr ) {
    cout << "Destructor: Deleting the pointer" << endl;
    delete raw_pointer;
  } else {
    cout << "Destructor: Pointer already moved or deleted" << endl;
  };  // end if / else

};  // end destructor



// Entry into the application
//-----------------------------------------------------------------------------
int main( int, char*[] ) {

  dm::example one;
  dm::example two( move( one ) );

  return 0;  // No error code

};  // end main
