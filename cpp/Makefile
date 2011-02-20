scorekeeper: main.o scorekeeper.o player.o
	g++ main.o scorekeeper.o player.o -o scorekeeper

main.o: main.cpp
	g++ -c main.cpp

scorekeeper.o: scorekeeper.cpp
	g++ -c scorekeeper.cpp

player.o: player.cpp
	g++ -c player.cpp

clean:
	rm *.o
