// NativeWrapper.h

#pragma once

using namespace System;
using namespace System::Drawing;

namespace NativeWrapper {

	public ref class Svg2Img
	{
		// TODO: Add your methods for this class here.
		public:
			Svg2Img(System::Drawing::Bitmap^ img);	
			void SetImage(System::Drawing::Bitmap^ img);	
			void ApplyAgg2DTest();

		private:
			System::Drawing::Bitmap^ mImg;
			int imgWidth;
			int imgHeight;
	};
}
