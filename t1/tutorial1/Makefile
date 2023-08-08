all: p1 p2 p3

p1: p1.cc
	g++ -o p1 p1.cc

p2: p2.cc
	g++ -o p2 p2.cc

p3: p3.cc
	g++ -c p3.cc
	g++ -o p3 power.cc p3.o

clean:
	rm -f p1
	rm -f p2
	rm -f p3
