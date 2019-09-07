
##
rm := /usr/bin/rm
cc := /usr/bin/g++ -std=c++17
valgrind := @valgrind
targets := move_example vector_example thread_example

%.o : %.cc ; $(cc) -c -o $@ $<

all : $(targets)

move_example : move_example.o ; $(cc) -o $@ $^
vector_example : vector_example.o ; $(cc) -o $@ $^
thread_example : thread_example.o ; $(cc) -o $@ $^ -pthread

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

.PHONY : clean
clean : ; $(rm) --force $(targets) *.o
