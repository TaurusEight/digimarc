
##
rm := /usr/bin/rm
cc := g++
valgrind := @valgrind
targets := move_example


all : $(targets)

move_example : move_example.o ; $(cc) -o $@ $<

test : $(targets)
	@echo
	@echo Running Valgrind with move example
	@echo ==================================
	$(valgrind) ./move_example
	@echo



.PHONY : clean
clean : ; $(rm) --force $(targets) *.o
