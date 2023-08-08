all: p1

Character.o: Character.h Character.cc
	g++ -c Character.cc

Battle.o: Battle.h Battle.cc Character.h
	g++ -c Battle.cc

main.o: main.cc Character.h Battle.h
	g++ -c main.cc

p1: main.o Character.o Battle.o
	g++ -o p1 main.o Character.o Battle.o

clean:
	rm -f p1 Character.o Battle.o main.o