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

	float screenRefreshRate;


	DFps() : screenRefreshRate(0) {}

public:

	void setRefreshRate();
	float getRefreshRate() const;
};


#endif