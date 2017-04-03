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
	float screenFPS;
	int screenTicks;
	float screenRefreshRate;
	static const int numSamples = 10;

	DFps() : screenFPS(0), screenRefreshRate(0), screenTicks(0) {}

public:

	void setRefreshRate();
	void begin();
	void calculateFPS();
	float end();



};


#endif