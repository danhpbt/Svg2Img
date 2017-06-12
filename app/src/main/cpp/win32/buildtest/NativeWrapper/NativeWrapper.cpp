// This is the main DLL file.

#include "stdafx.h"

#include "NativeWrapper.h"
#include "BasicTest.h"



NativeWrapper::Svg2Img::Svg2Img(System::Drawing::Bitmap^ img)
{
	if (img)
	{
		mImg = img;
		imgWidth = mImg->Width;
		imgHeight = mImg->Height;
	}
}

void NativeWrapper::Svg2Img::SetImage(System::Drawing::Bitmap^ img)
{
	if (img)
	{
		mImg = img;
		imgWidth = mImg->Width;
		imgHeight = mImg->Height;
	}
}

void NativeWrapper::Svg2Img::ApplyAgg2DTest()
{
	System::Drawing::Rectangle mRect(0, 0, imgWidth, imgHeight);
	System::Drawing::Imaging::BitmapData^ bmData = mImg->LockBits(mRect,					
		System::Drawing::Imaging::ImageLockMode::ReadWrite, 
		System::Drawing::Imaging::PixelFormat::Format32bppArgb); 	

	System::IntPtr Scan0 = bmData->Scan0; 

	BMP_ARGB *data = (BMP_ARGB *)(void *)Scan0;

	Agg2DTest(data, imgWidth, imgHeight);

	mImg->UnlockBits(bmData);
}