#include "DFps.h"

int DFps::getRefreshRate()
{
	#ifdef __GNUC__

		int size;
		Rotation currentRotation;

		Display *d = XOpenDisplay(NULL);
		Window root = RootWindow(d, 0);

		XRRScreenConfiguration *conf = XRRGetScreenInfo(d, root);
		screenRefreshRate = XRRConfigCurrentRate(conf);

		return screenRefreshRate;
	#elif _MSC_VER

		DEVMODE dm;

		screenRefreshRate = dm.dmDisplayFrequency;
		return screenRefreshRate;
		
	#endif

}