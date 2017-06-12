#include <math.h>
#include "RGBImage.h"

void RGBImage::ToRGBGreyImage() {

#ifndef GRAY_FROM_RGB
	#define GRAY_FROM_RGB(r, g, b) (unsigned char)((r*29 + g*150 + b*77 + 128)/256)
#endif

	unsigned char* image = (unsigned char*)RGBData;
	int length = Width * Height;
	unsigned char gray = 0;
	for (int i = 0; i < length; i++, image += 4)
	{
		gray = GRAY_FROM_RGB(*image, *(image + 1), *(image + 2));

		*image = gray;
		*(image + 1) = gray;
		*(image + 2) = gray;
	}

	image = NULL;
}

byte* RGBImage::GetChannel(int channel) {

	int length = Width * Height;
	byte* mono = new byte[length];

	byte* dst = mono;
	byte* ptr = (byte*)RGBData + channel;
	int bpp = sizeof(int);

	for (int i=0; i<length; i++, dst++, ptr += bpp) {
		*dst = *ptr;
	}

	return mono;
}

void RGBImage::SetChannel(byte* mono, int channel) {

	int length = Width * Height;

	byte* src = mono;
	byte* ptr = (byte*)RGBData + channel;
	int bpp = sizeof(int);

	for (int i=0; i<length; i++, src++, ptr += bpp) {
		*ptr = *src;
	}
}

