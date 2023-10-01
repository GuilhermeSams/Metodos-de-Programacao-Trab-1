CXX = g++
CXXFLAGS = -std=c++11 -Wall -ftest-coverage -fprofile-arcs
LDFLAGS =
SOURCES = velha.cpp testa_velha.cpp
EXECUTABLE = testa_velha

all: testa_velha.cpp   velha.cpp velha.hpp velha.o
	g++ -std=c++11 -Wall velha.o testa_velha.cpp -o testa_velha
	./testa_velha
	#Algumas coisas a Considerar: Quando rodei make gcov ele criou diversos arquivos gcov e não 1 gcov com antotação e achei isso inesperado, então eu não inclui eles no trabalho, caso queira, rode um make gcov no terminal da pasta do projeto. O site disponibilizado pra ver as regras do jogo da velha está indisponível.

compile: testa_velha.cpp   velha.cpp velha.hpp velha.o
	g++ -std=c++11 -Wall velha.o testa_velha.cpp -o testa_velha

velha.o : velha.cpp velha.hpp
	g++ -std=c++11 -Wall -c velha.cpp
	
testa_velha: 	testa_velha.cpp   velha.cpp velha.hpp velha.o
	g++ -std=c++11 -Wall velha.o testa_velha.cpp -o testa_velha
	
test: testa_velha	
	./testa_velha
	
cpplint: testa_velha.cpp   velha.cpp velha.hpp
	cpplint   --exclude=catch.hpp  *.*
	
gcov: testa_velha.cpp   velha.cpp velha.hpp 
	g++ -std=c++11 -Wall -fprofile-arcs -ftest-coverage -c velha.cpp
	g++ -std=c++11 -Wall -fprofile-arcs -ftest-coverage velha.o testa_velha.cpp -o testa_velha
	./testa_velha
	gcov *.cpp	
	 
debug: testa_velha.cpp   velha.cpp velha.hpp 
	g++ -std=c++11 -Wall -g -c velha.cpp
	g++ -std=c++11 -Wall  -g velha.o testa_velha.cpp -o testa_velha
	gdb testa_velha
	
	
cppcheck: testa_velha.cpp   velha.cpp velha.hpp
	cppcheck  --enable=warning .

valgrind: testa_velha
	valgrind --leak-check=yes --log-file=valgrind.rpt testa_velha


clean:
	rm -rf *.o *.exe *.gc* testa_velha valgrind.rpt
