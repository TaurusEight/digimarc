
##
rm := /usr/bin/rm
cc := g++
valgrind := @valgrind
targets := move_example vector_example

%.cc : %.o ; $(cc) -c $@

all : $(targets)

move_example : move_example.o ; $(cc) -o $@ $<
vector_example : vector_example.o ; $(cc) -o $@ $<


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





.PHONY : clean
clean : ; $(rm) --force $(targets) *.o
