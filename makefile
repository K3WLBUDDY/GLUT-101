OBJS = main.o DWindow.o DShader.o DFps.o DTex.o
CC = g++
DEPS = -lSDL2 -lGLEW -lGLU -lGL -lX11 -lpthread -lXrandr -lXi -lXrandr -lSOIL

run : $(OBJS)
	$(CC) -o run $(OBJS) $(DEPS)

DFps.o :	DFps.h DFps.cpp
	$(CC) -c DFps.cpp $(DEPS)
	

DWindow.o : DWindow.h DWindow.cpp
	$(CC) -c DWindow.cpp $(DEPS)

DShader.o : DShader.h DShader.cpp
	$(CC) -c DShader.cpp $(DEPS)

DTex.o : DTex.h DTex.cpp
	$(CC) -c DTex.cpp $(DEPS)


main.o : main.cpp
	$(CC) -c main.cpp
