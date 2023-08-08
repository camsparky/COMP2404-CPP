all: a1

Room.o: Room.cc Room.h
	g++ -c Room.cc

Student.o: Student.cc Student.h
	g++ -c Student.cc

Date.o: Date.cc Date.h
	g++ -c Date.cc

Reservation.o: Reservation.cc Reservation.h Student.h Room.h Date.h
	g++ -c Reservation.cc

Library.o: Reservation.h Library.cc Library.h
	g++ -c Library.cc

a1-global.o: a1-global.cc Library.h Date.h
	g++ -c a1-global.cc

a1: a1-global.o Room.o Student.o Date.o Reservation.o Library.o
	g++ -o a1 a1-global.o Room.o Student.o Date.o Reservation.o Library.o

clean:
	rm -f a1 *.o