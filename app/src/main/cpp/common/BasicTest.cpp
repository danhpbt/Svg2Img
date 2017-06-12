#ifdef _WIN32
	#include <string.h>
	#include <stdlib.h>	
#endif

#include "Typedef.h"
#include "BasicTest.h"
#include "agg2d.h"


void Agg2DTest(BMP_ARGB *data, int width, int height)
{
	Agg2D* g = new Agg2D();
	int stride = width*sizeof(BMP_ARGB);
	g->attach((unsigned char*)data, width, height, stride);
	g->viewport(0, 0, width, height, 0, 0, width, height, Agg2D::XMidYMid);

	g->fillColor(0, 255, 0, 127);
	g->rectangle(0, 0, width, height);

	DELETE(g);
}