CC = javac
CFLAGS =
LFLAGS =
TARGET = Main
OBJECTS = *.java

# Linking all the object code:
main:
	$(CC) $(LFLAGS) $(OBJECTS)

# Custom commands:
clean:
	rm -f *.class # deleting executable, .o’s and backups

run:
	java $(TARGET) ${args} # executing the program
	
all:
	make clean
	make
	date
	make run
	date
	make clean