CCX=g++ -std=c++11

a.out: Board.o place.o exceptions.o 
		$(CCX) main.cpp *.o
		
Board.o: Board.cpp Board.h
		$(CCX) -c Board.cpp
		
place.o: place.cpp place.hpp
		$(CCX) -c place.cpp

exceptions.o: exceptions.cpp exceptions.hpp
		$(CCX) -c exceptions.cpp
		
Clean:
		rm  *.o a.out

