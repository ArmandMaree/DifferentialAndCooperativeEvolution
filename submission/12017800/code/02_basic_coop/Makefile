CC = g++
CFLAGS = -std=c++11 -pthread
LFLAGS = -static -pthread
TARGET = main
OBJECTS = cell.o individual.o bestIndividual.o optimizationFunction.o alpineFunction.o eggholderFunction.o griewankFunction.o norwegianFunction.o rosenbrockFunction.o salomonFunction.o schaffer6Function.o schwefel222Function.o shubertFunction.o vincentFunction.o weierstrassFunction.o crossover.o binomialCrossover.o differentialEvolution.o main.o

# Linking all the object code:
main: $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -o $(TARGET)

# Dependencies:
main.o: main.cpp

 Compilation rule:
%.o: %.cpp
	$(CC) $(CFLAGS) -c $?

# Custom commands:
clean:
	rm -f $(TARGET) $(OBJECTS) *.gch *~ # deleting executable, .o’s and backups

run:
	./$(TARGET) $(args) # executing the program
	
all:
	make clean
	make
	date
	make run
	date
	make clean