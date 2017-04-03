#ifndef DFPSH
#define DFPSH

#include <SDL2/SDL.h>
#include <iostream>

#ifdef __GNUC__

#include <X11/Xlib.h>
#include <X11/extensions/Xrandr.h>

#elif _MSC_VER

#include <Windows.h>

#endif

class DFps
{
private:
	int screenFPS;
	int screenTicks;
	int screenRefreshRate;

	DFps() : screenFPS(60), screenRefreshRate(60), screenTicks(0) {}

public:

	int getRefreshRate();



};


#endif