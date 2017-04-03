#include "DFps.h"

void DFps::setRefreshRate()
{
	#ifdef __GNUC__

		int size;
		Rotation currentRotation;

		Display *d = XOpenDisplay(NULL);
		Window root = RootWindow(d, 0);

		XRRScreenConfiguration *conf = XRRGetScreenInfo(d, root);
		screenRefreshRate = XRRConfigCurrentRate(conf);

		screenFPS = screenRefreshRate;
		screenRefreshRate = 144;		
		

	#elif _MSC_VER

		DEVMODE dm;

		screenRefreshRate = dm.dmDisplayFrequency;
		screenFPS = screenRefreshRate;


	#endif

}

void DFps::calculateFPS()
{	
	static float frameTimes[numSamples];
	static int currentFrame = 0;
	static float previousTick = SDL_GetTicks();

	float currentTick = SDL_GetTicks();

	screenTicks = currentTick - previousTick;
	frameTimes[currentFrame%numSamples] = screenTicks;
	previousTick = currentTick;

	int count;
	currentFrame++;

	if(currentFrame<numSamples)
		count = currentFrame;
	else
		count = numSamples;

	float frameTimeAvg = 0;

	for(int i=0;i<count;i++)
		frameTimeAvg += frameTimes[i];

	frameTimeAvg /= count;

	if(frameTimeAvg>0)
		screenFPS = 1000.0f / frameTimeAvg;

	else
		screenFPS = 144;
}

void DFps::begin()
{
	screenTicks = SDL_GetTicks();
}

float DFps::end()
{
	calculateFPS();

	float frameTick  =SDL_GetTicks() - screenTicks;

	if(1000.0f / 144 > frameTick)
		SDL_Delay(1000.0f / 144- frameTick);

	return screenFPS;

}