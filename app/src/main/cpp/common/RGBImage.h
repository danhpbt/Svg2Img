#ifndef _RGBIMAGE_H__
#define _RGBIMAGE_H__

#pragma once

#include "Typedef.h"
#include "Agg2D.h"

class RGBImage {

public:
	int Width; // read-only
	int Height; // read-only

	int* RGBData;

	bool AutoDispose;

	Agg2D* g;

public:
	
	RGBImage(int width, int height) {
		AutoDispose = true;
		Width = width;
		Height = height;
		RGBData = new int[Width * Height];

		int stride = Width*sizeof(BMP_ARGB);
		g = new Agg2D();
		g->attach((unsigned char*)RGBData, Width, Height, stride);
		g->viewport(0, 0, Width, Height,
			0, 0, Width, Height, Agg2D::XMidYMid);
	}

	RGBImage(int* rgbData, int width, int height, bool autoDispose) {
		RGBData = rgbData;
		Width = width;
		Height = height;
		AutoDispose = autoDispose;

		int stride = Width*sizeof(BMP_ARGB);
		g = new Agg2D();
		g->attach((unsigned char*)RGBData, Width, Height, stride);
		g->viewport(0, 0, Width, Height,
			0, 0, Width, Height, Agg2D::XMidYMid);
	}

	~RGBImage() {
		Dispose();
	}

	void Dispose(){
		if (AutoDispose && RGBData != NULL) {
			delete RGBData;
		}
		RGBData = NULL;

		if (g)
		{
			delete g;
			g = NULL;
		}
	}

public:
	void ToRGBGreyImage();

	byte* GetChannel(int channel);

	void SetChannel(byte* mono, int channel);	
};

#endif
