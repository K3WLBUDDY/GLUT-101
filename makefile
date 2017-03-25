OBJS = main.o DWindow.o DShader.o
CC = g++
DEPS = -lSDL2 -lGLEW -lGLU -lGL -lX11 -lpthread -lXrandr -lXi

run : $(OBJS)
	$(CC) -o run $(OBJS) $(DEPS)

DWindow.o : DWindow.h DWindow.cpp
	$(CC) -c DWindow.cpp $(DEPS)

DShader.o: DShader.h DShader.cpp
	$(CC) -c DShader.cpp $(DEPS)

main.o : main.cpp
	$(CC) -c main.cpp
