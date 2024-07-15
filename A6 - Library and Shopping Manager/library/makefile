CC := g++ --std=c++11
CC_OBJECT := $(CC) -c

all: main

main: main.o Library.o magazine.o book.o refernce.o professor.o document.o person.o error_handler.o student.o
	$(CC) *.o -o main 

main.o: main.cc Library.hh
	$(CC_OBJECT) main.cc -o main.o

Library.o: Library.hh Library.cc book.hh magazine.hh refernce.hh student.hh professor.hh
	$(CC_OBJECT) Library.cc -o Library.o

magazine.o: magazine.hh magazine.cc document.hh
	$(CC_OBJECT) magazine.cc -o magazine.o

book.o: book.hh book.cc document.hh
	$(CC_OBJECT) book.cc -o book.o

refernce.o: refernce.hh refernce.cc document.hh
	$(CC_OBJECT) refernce.cc -o refernce.o

student.o: student.hh student.cc person.hh
	$(CC_OBJECT) student.cc -o student.o

professor.o: professor.hh professor.cc person.hh
	$(CC_OBJECT) professor.cc -o professor.o

person.o: person.hh person.cc document.hh
	$(CC_OBJECT) person.cc -o person.o

document.o: document.hh document.cc
	$(CC_OBJECT) document.cc -o document.o

error_hanlder.o: error_hanlder.hh error_hanlder.cc
	$(CC_OBJECT) error_hanlder.cc -o error_handler.o
