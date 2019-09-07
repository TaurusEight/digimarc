// Time-stamp: <2019-09-07 15:20:46 daniel>
// Author Daniel Mendyke [archadious@gmail.com]
//
// Developed for Digimarc
//

// Required header files
//-----------------------------------------------------------------------------
#include <vector>  // std::vector

// Entry into example app
//-----------------------------------------------------------------------------
int main( int, char*[] ) {

  std::vector< int > nums = { 1, 2, 3 };
  nums.push_back( 4 );
  return 0;  // no return code

};  // end main routine
