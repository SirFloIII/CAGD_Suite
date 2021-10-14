
#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#include "CAGD_Suite.h"




int main()
{
	CAGD_Suite demo;
	if (demo.Construct(SCREENHEIGHT * 16 / 9, SCREENHEIGHT, 4, 4, true, true))
		demo.Start();

	return 0;
}
