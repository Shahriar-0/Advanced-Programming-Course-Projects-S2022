CC := g++ --std=c++11
CC_OBJECT := $(CC) -c

all: main

main: main.o library.o magazine.o book.o refrence.o professor.o document.o person.o
	$(CC) *.o -o main 

main.o: main.cc library.hh
	$(CC_OBJECT) main.cc -o main.o

library.o: library.hh library.cc book.hh magazine.hh refrence.hh students.hh professor.hh
	$(CC_OBJECT) library.cc -o library.o

magazine.o: magazine.hh magazine.cc document.hh
	$(CC_OBJECT) magazine.cc -o magazine.o

book.o: book.hh book.cc document.hh
	$(CC_OBJECT) book.cc -o book.o

refrence.o: refrence.hh refrence.cc document.hh
	$(CC_OBJECT) refrence.cc -o refrence.o

student.o: student.hh student.cc person.hh
	$(CC_OBJECT) student.cc -o student.o

professor.o: professor.hh professor.cc person.hh
	$(CC_OBJECT) professor.cc -o professor.o

person.o: person.hh person.cc document.hh
	$(CC_OBJECT) person.cc -o person.o

document.o: document.hh document.cc
	$(CC_OBJECT) document.cc -o document.o
