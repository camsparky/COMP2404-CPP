all: test
	
test: test.cc StoreLocation.o Location.o
	g++ -o test test.cc StoreLocation.o Location.o
	
StoreLocation.o: StoreLocation.h StoreLocation.cc Location.h defs.h
	g++ -c StoreLocation.cc 

Location.o:	Location.h Location.cc defs.h
	g++ -c Location.cc
	
clean:
	rm -f test *.o
