a.out: giveaway.o Prize.o Viewer.o
	g++ giveaway.o Prize.o Viewer.o

giveaway.o: giveaway.cc Prize.h Viewer.h
	g++ -c giveaway.cc

Prize.o: Prize.cc Prize.h Viewer.h
	g++ -c Prize.cc

Viewer.o: Viewer.h Viewer.cc
	g++ -c Viewer.cc

clean:
	rm -f *.o a.out
