# Time-stamp: <2019-09-07 20:46:30 daniel>
# Author: Daniel Mendyke

#
# Makefile for sample applications written for Digimarc
#

##
# Macros
rm := /usr/bin/env rm
cc := /usr/bin/env g++ -std=c++17
valgrind := @valgrind
targets := move_example \
           vector_example \
           thread_example \
           vector_size

##
# Standard rule for creating C++ applications from source
%.o : %.cc ; $(cc) -c -o $@ $<

##
# Main target
all : $(targets)

##
# Build sample applications from their objects
move_example : move_example.o ; $(cc) -o $@ $^
vector_example : vector_example.o ; $(cc) -o $@ $^
thread_example : thread_example.o ; $(cc) -o $@ $^ -pthread
vector_size : vector_size.o ; $(cc) -o $@ $^

##
# Test the sample applications by running them through Valgrind
test : $(targets)
# Move Constructor Example
	@echo
	@echo Running Valgrind with move example
	@echo ==================================
	$(valgrind) ./move_example
	@echo
# Vector examples
	@echo Running Vector Examples
	@echo ==================================
	$(valgrind) ./vector_example
	@echo
# Thread examples
	@echo Running Thread Example
	@echo ==================================
	$(valgrind) ./thread_example
	@echo
# Vector size
	@echo Vector Data Size
	@echo ==================================
	$(valgrind) ./vector_size
	@echo


##
# Remove objects and compiled applications
.PHONY : clean
clean : ; $(rm) --force $(targets) *.o
