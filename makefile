OBJS = main.o DWindow.o
CC = g++

run : $(OBJS)
	$(CC) -o run $(OBJS) -lSDL2

DWindow.o : DWindow.h DWindow.cpp
	$(CC) -c DWindow.cpp

main.o : main.cpp
	$(CC) -c main.cpp
