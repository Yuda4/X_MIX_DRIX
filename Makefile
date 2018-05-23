CCX=g++ -std=c++11

a.out: Board.o place.o exceptions.o TicTacToe.o DummyPlayers.o Champion.o
		$(CCX) main.cpp *.o
		
Board.o: Board.cpp Board.h
		$(CCX) -c Board.cpp
		
place.o: place.cpp place.hpp
		$(CCX) -c place.cpp

exceptions.o: exceptions.cpp exceptions.hpp
		$(CCX) -c exceptions.cpp
		
TicTacToe.o: TicTacToe.h TicTacToe.cpp
		$(CCX) -c TicTacToe.cpp
		
DummyPlayers.o: Player.h DummyPlayers.h DummyPlayers.cpp
		$(CCX) -c DummyPlayers.cpp
		
Champion.o: Player.h Champion.h Champion.cpp
		$(CCX) -c Champion.cpp

Clean:
		rm  *.o a.out

