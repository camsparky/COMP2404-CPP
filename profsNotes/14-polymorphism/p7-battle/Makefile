OBJECTS = main.o Battle.o Board.o Hero.o Orc.o Character.o Swing.o 

p7: $(OBJECTS)
	g++ -o p7 $(OBJECTS)

main.o:	main.cc Battle.h
	g++ -c main.cc

Battle.o:	Battle.cc Battle.h
	g++ -c Battle.cc

Board.o:	Board.cc Board.h
	g++ -c Board.cc

Hero.o:	Hero.cc Hero.h Character.h
	g++ -c Hero.cc

Orc.o:	Orc.cc Orc.h Character.h
	g++ -c Orc.cc

Character.o: Character.cc Character.h
	g++ -c Character.cc 

Swing.o: Swing.cc Swing.h 
	g++ -c Swing.cc

clean:
	rm -f *.o p7