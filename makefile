OBJS = main.o DWindow.o
CC = g++
DEPS = -lSDL2 -lGLEW -lGLU -lGL -lX11 -lpthread -lXrandr -lXi

run : $(OBJS)
	$(CC) -o run $(OBJS) $(DEPS)

DWindow.o : DWindow.h DWindow.cpp
	$(CC) -c DWindow.cpp $(DEPS)

main.o : main.cpp
	$(CC) -c main.cpp
