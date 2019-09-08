#ifndef __WORD_PUZZLE_HH__
#define __WORD_PUZZLE_HH__

// Author: Daniel Mendyke [archadious@gmail.com]
// Copyright (c) 2019 All Rights Reserved.
//
// 'word_puzzle.hh' : Header file for the word puzzle creation library.


// Required header files
//-----------------------------------------------------------------------------
#include <iostream>  // defines std::ostream
#include <vector>  // std::vector
#include <string>  // std::string


// NS used to differentiat the puzzle class
//-----------------------------------------------------------------------------
namespace word {


  // Define types for ease of use
  //---------------------------------------------------------------------------
  // Used to pass a list of words to be included to the puzzle constructor.
  typedef std::vector< std::string > word_vector_t;
  // Used to simplify use of a single dimensional vector for storing the puzzle.
  typedef std::vector< char > matrix_t;


  // Wrapper around the creation and output of a word puzzle
  //---------------------------------------------------------------------------
  class puzzle {

  public:

    // 'word::puzzle::exception' only thrown from within word::puzzle::fit_word.
    class exception : public std::runtime_error;

    // Main Constructor.
    // Parameters:
    //     a vector of words to embed within the puzzle.
    //     the number or rows high the puzzle will be.
    //     the number of columns width the puzzle will be.
    puzzle( const word_vector_t&, size_t, size_t );

    // defined to allow this operator to have access to 'matrix_' in order to
    // print the puzzle to the supplied output stream
    friend std::ostream& operator<<( std::ostream&, const puzzle& );

  protected:

    // A recursively called function used to build the puzzle
    // that is called by the constructor.
    // parameters:
    //    a const reference to a word not yet placed within the puzzle
    //    an interator pointing to a direction
    void fit_word( const string&, direction_iterator_t );

  private:

    // 'matrix_' stores the puzzle while it is being created.  This object is
    // not two dimensional.  Locations are calculated based on row_ and column_.
    matrix_t matrix_;  // Stores the puzzle while it is being created.

    // Both the number of rows and the number of columns used by this puzzle.
    // Set through the class constructor.
    size_t row_;
    size_t column_;

  };  // end class puzzle


  // Overloaded "<<" operator to allow easy output of the completed puzzle.
  // This function has been declared a friend to the word::puzzle class
  // so that it will have access to the raw puzzle data.
  std::ostream& operator<<( std::ostream&, const puzzle& );

};  // end NS word

#endif  // __WORD_PUZZLE_HH__
