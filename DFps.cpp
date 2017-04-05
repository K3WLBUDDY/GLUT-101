#include "DFps.h"

void DFps::setRefreshRate()
{
	#ifdef __GNUC__

		Display *d = XOpenDisplay(NULL);
		Window root = RootWindow(d, 0);

		XRRScreenConfiguration *conf = XRRGetScreenInfo(d, root);
		screenRefreshRate = XRRConfigCurrentRate(conf);	

	#elif _MSC_VER

		DEVMODE dm;

		screenRefreshRate = dm.dmDisplayFrequency;
		screenFPS = screenRefreshRate;


	#endif

}

float DFps::getRefreshRate() const
{
	return screenRefreshRate;
}