all: assign4ES

assign4ES: main.o UserInterface.o Polynomial.o Term.o Complex.o
	g++ main.o UserInterface.o Polynomial.o Term.o Complex.o -o assign4ES

main.o: main.cpp
	g++ -c main.cpp

UserInterface.o: UserInterface.cpp
	g++ -c UserInterface.cpp

Polynomial.o: Polynomial.cpp
	g++ -c Polynomial.cpp
    
Term.o: Term.cpp
	g++ -c Term.cpp

Complex.o: Complex.cpp
	g++ -c Complex.cpp

clean:
	rm -rf *o assign4ES