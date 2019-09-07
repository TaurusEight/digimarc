// Time-stamp: <2019-09-06 23:28:32 daniel>
// Author dmendyke [archadious@gmail.com]
//
// Developed for Digimarc
// Demostrates the ideas:
//     Direct assignment to a vector object
//     Simple lambda function
//     Range-based loop


// Required header files
//-----------------------------------------------------------------------------
#include <iostream>  // cout, endl, std
#include <vector>  // std::vector
#include <string>  // std::string


// NS short cuts
//-----------------------------------------------------------------------------
using namespace std;


// Entry into example app
//-----------------------------------------------------------------------------
int main( int, char*[] ) {

  // Create a vector of string objects and assign values to it
  vector< string > svec{ "one", "two", "three" };

  // Create a lambda function to print the value of a string reference
  auto func = []( const string& value ) { cout << value << endl; };

  // Use of range-based for loop
  for( auto& iter : svec ) func( iter );

  return 0;  // no return code

};  // end main routine
