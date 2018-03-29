OBJS = DWindow.o DShader.o DFps.o DTex.o main.o 
CC = g++
DEPS = -lSDL2 -lGLEW -lGLU -lGL -lX11 -lpthread -lXrandr -lXi -lSOIL -fPIC 

run : $(OBJS)
	$(CC) -o run $(OBJS) $(DEPS) 
	
DWindow.o : DWindow.h DWindow.cpp
	$(CC) -c DWindow.cpp $(DEPS) -fPIC

DShader.o : DShader.h DShader.cpp
	$(CC) -c DShader.cpp $(DEPS) -fPIC

DTex.o : DTex.h DTex.cpp
	$(CC) -c DTex.cpp $(DEPS) -fPIC

DFps.o :	DFps.h DFps.cpp
	$(CC) -c DFps.cpp $(DEPS) -fPIC	

main.o : main.cpp
	$(CC) -c main.cpp -fPIC

