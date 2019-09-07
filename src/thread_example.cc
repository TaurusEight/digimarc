// Time-stamp: <2019-09-07 00:39:30 daniel>
// Author dmendyke [archadious@gmail.com]
//
// Developed for Digimarc
// Demostrates the use of the new standard thread class std::thread


// Required header files
//-----------------------------------------------------------------------------
#include <chrono>  // chrono::seconds
#include <thread>  // std::thread, std::this_thread, sleep_for

#include <random>  // for random int generator
#include <iostream>  // cout, endl


// NS shortcuts
//-----------------------------------------------------------------------------
using namespace std;


// NS used by this class
//-----------------------------------------------------------------------------
namespace dm {

  int random_int( );  // generate a random number
  void worker( const string& );  // sleep for random number of seconds

};  // end NS dm


// Use of the random library included with C++11
// Function returns a random int between 1 and 6
//-----------------------------------------------------------------------------
int dm::random_int() {

  mt19937 rnum;
  rnum.seed( random_device()() );
  uniform_int_distribution< mt19937::result_type > dist6( 1, 6 );
  return dist6( rnum );

};  // end dm::random_int



// Function called by a thread
//-----------------------------------------------------------------------------
void dm::worker( const std::string& data ) {

  int how_many = dm::random_int();

  this_thread::sleep_for( chrono::seconds( how_many ) );
  cout << "After " << how_many << " seconds : " << data << endl;

};  // end dm::worker


// Entry into this example app
//-----------------------------------------------------------------------------
int main( int, char*[] ) {

  // Generate two threads
  thread one( dm::worker, "one" );
  thread two( dm::worker, "two" );

  // Needed
  one.join();
  two.join();

  return 0;  // return success

};  // end main routine
