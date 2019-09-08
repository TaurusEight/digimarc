
‘Digimarc Examples'
-----------------------

A Docker container containing example C++ and x86 applications
developed as examples for Digimarc.


Build Instructions:
-------------------

* By Docker.  The command ‘docker-compose build’ should be sufficient to
  build the application.  Or ‘docker build -t digimarc .’ if using
  the docker command.

* At the command line.  Change into the directory 'src' and issue the
  command ‘Make’.


Programming Examples:
------------------------

* move_example:    An example of the move constructor in C++

* vector_example:  A set of examples using the C++ vector class

* thread_example:  Example of using std::thread and C++11 random library

* vector_size:     Test code to determine memory use by std::vector

* word_puzzle.hh:  Sample Header File for a word find puzzle generator


Programming notes:
------------------


* C++17 is used as the  programming language but several of the example
  make use of features first released in C++11 or C++14.

* A Docker container is used for testing and debugging.  Both a Dockerfile
  and a docker-compose.yml file are included.

* The application builds with standard GNU Make.
