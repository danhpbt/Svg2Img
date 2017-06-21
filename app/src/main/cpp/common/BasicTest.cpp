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

//	g->viewport(0, 0, width, height, 0, 0, width, height, Agg2D::XMidYMid);
// 	g->fillColor(0, 255, 0, 127);
// 	g->rectangle(0, 0, width, height);

	/*
	g->viewport(0, 0, 600, 600, 0, 0, width, height, Agg2D::XMidYMid);


	// Rounded Rect
	g->lineColor(0, 0, 0);
	g->noFill();
	g->roundedRect(0.5, 0.5, 600-0.5, 600-0.5, 20.0);


	g->fillColor(0, 0, 0);
	g->noLine();

	g->lineColor(50, 0, 0);
	g->fillColor(180, 200, 100);
	g->lineWidth(1.0);

	// Text Alignment
	g->line(250.5-150, 150.5,    250.5+150, 150.5);
	g->line(250.5,     150.5-20, 250.5,     150.5+20);
	g->line(250.5-150, 200.5,    250.5+150, 200.5);
	g->line(250.5,     200.5-20, 250.5,     200.5+20);
	g->line(250.5-150, 250.5,    250.5+150, 250.5);
	g->line(250.5,     250.5-20, 250.5,     250.5+20);
	g->line(250.5-150, 300.5,    250.5+150, 300.5);
	g->line(250.5,     300.5-20, 250.5,     300.5+20);
	g->line(250.5-150, 350.5,    250.5+150, 350.5);
	g->line(250.5,     350.5-20, 250.5,     350.5+20);
	g->line(250.5-150, 400.5,    250.5+150, 400.5);
	g->line(250.5,     400.5-20, 250.5,     400.5+20);
	g->line(250.5-150, 450.5,    250.5+150, 450.5);
	g->line(250.5,     450.5-20, 250.5,     450.5+20);
	g->line(250.5-150, 500.5,    250.5+150, 500.5);
	g->line(250.5,     500.5-20, 250.5,     500.5+20);
	g->line(250.5-150, 550.5,    250.5+150, 550.5);
	g->line(250.5,     550.5-20, 250.5,     550.5+20);


	g->fillColor(100, 50, 50);
	g->noLine();

	double xb1 = 400;
	double yb1 = 80;
	double xb2 = xb1 + 150;
	double yb2 = yb1 + 36;

	g->fillColor(Agg2D::Color(0,50,180,180));
	g->lineColor(Agg2D::Color(0,0,80, 255));
	g->lineWidth(1.0);
	g->roundedRect(xb1, yb1, xb2, yb2, 12, 18);

	g->lineColor(Agg2D::Color(0,0,0,0));
	g->fillLinearGradient(xb1, yb1, xb1, yb1+30,
		Agg2D::Color(100,200,255,255),
		Agg2D::Color(255,255,255,0));
	g->roundedRect(xb1+3, yb1+2.5, xb2-3, yb1+30, 9, 18, 1, 1);

	g->fillColor(Agg2D::Color(0,0,50, 200));
	g->noLine();

	g->fillLinearGradient(xb1, yb2-20, xb1, yb2-3,
		Agg2D::Color(0,  0,  255,0),
		Agg2D::Color(100,255,255,255));
	g->roundedRect(xb1+3, yb2-20, xb2-3, yb2-2, 1, 1, 9, 18);


	// Aqua Button Pressed
	xb1 = 400;
	yb1 = 30;
	xb2 = xb1 + 150;
	yb2 = yb1 + 36;

	g->fillColor(Agg2D::Color(0,50,180,180));
	g->lineColor(Agg2D::Color(0,0,0,  255));
	g->lineWidth(2.0);
	g->roundedRect(xb1, yb1, xb2, yb2, 12, 18);

	g->lineColor(Agg2D::Color(0,0,0,0));
	g->fillLinearGradient(xb1, yb1+2, xb1, yb1+25,
		Agg2D::Color(60, 160,255,255),
		Agg2D::Color(100,255,255,0));
	g->roundedRect(xb1+3, yb1+2.5, xb2-3, yb1+30, 9, 18, 1, 1);

	g->fillColor(Agg2D::Color(0,0,50, 255));
	g->noLine();

	g->fillLinearGradient(xb1, yb2-25, xb1, yb2-5,
		Agg2D::Color(0,  180,255,0),
		Agg2D::Color(0,  200,255,255));
	g->roundedRect(xb1+3, yb2-25, xb2-3, yb2-2, 1, 1, 9, 18);




	// Basic Shapes -- Ellipse
	//===========================================
	g->lineWidth(3.5);
	g->lineColor(20,  80,  80);
	g->fillColor(200, 255, 80, 200);
	g->ellipse(450, 200, 50, 90);


	// Paths
	//===========================================
	g->resetPath();
	g->fillColor(255, 0, 0, 100);
	g->lineColor(0, 0, 255, 100);
	g->lineWidth(2);
	g->moveTo(300/2, 200/2);
	g->horLineRel(-150/2);
	g->arcRel(150/2, 150/2, 0, 1, 0, 150/2, -150/2);
	g->closePolygon();
	g->drawPath();

	g->resetPath();
	g->fillColor(255, 255, 0, 100);
	g->lineColor(0, 0, 255, 100);
	g->lineWidth(2);
	g->moveTo(275/2, 175/2);
	g->verLineRel(-150/2);
	g->arcRel(150/2, 150/2, 0, 0, 0, -150/2, 150/2);
	g->closePolygon();
	g->drawPath();


	g->resetPath();
	g->noFill();
	g->lineColor(127, 0, 0);
	g->lineWidth(5);
	g->moveTo(600/2, 350/2);
	g->lineRel(50/2, -25/2);
	g->arcRel(25/2, 25/2, Agg2D::deg2Rad(-30), 0, 1, 50/2, -25/2);
	g->lineRel(50/2, -25/2);
	g->arcRel(25/2, 50/2, Agg2D::deg2Rad(-30), 0, 1, 50/2, -25/2);
	g->lineRel(50/2, -25/2);
	g->arcRel(25/2, 75/2, Agg2D::deg2Rad(-30), 0, 1, 50/2, -25/2);
	g->lineRel(50, -25);
	g->arcRel(25/2, 100/2, Agg2D::deg2Rad(-30), 0, 1, 50/2, -25/2);
	g->lineRel(50/2, -25/2);
	g->drawPath();


	// Master Alpha. From now on everything will be translucent
	//===========================================
	g->masterAlpha(0.85);


	// Add/Sub/Contrast Blending Modes
	g->noLine();
	g->fillColor(70, 70, 0);
	g->blendMode(Agg2D::BlendAdd);
	g->ellipse(500, 280, 20, 40);

	g->fillColor(255, 255, 255);
	g->blendMode(Agg2D::BlendContrast);
	g->ellipse(500+40, 280, 20, 40);



	// Radial gradient.
	g->blendMode(Agg2D::BlendAlpha);
	g->fillRadialGradient(400, 500, 40,
		Agg2D::Color(255, 255, 0, 0),
		Agg2D::Color(0, 0, 127),
		Agg2D::Color(0, 255, 0, 0));
	g->ellipse(400, 500, 40, 40);

	*/

	g->viewport(0, 0, 600, 600,
	0, 0, width, height,
	//Agg2D::Anisotropic);
	Agg2D::XMidYMid);


	// Rounded Rect
	g->lineColor(0, 0, 0);
	g->noFill();
	g->roundedRect(0.5, 0.5, 600-0.5, 600-0.5, 20.0);


	// Reglar Text
#ifdef AGG2D_USE_FREETYPE
	g->font("c:/WINDOWS/fonts/times.ttf", 14.0, false, false);
#else
	g->font("Times New Roman", 14.0, false, false);
#endif
	g->fillColor(0, 0, 0);
	g->noLine();
	g->text(100, 20, "Regular Raster Text -- Fast, but can't be rotated");

	// Outlined Text
#ifdef AGG2D_USE_FREETYPE
	g->font("c:/WINDOWS/fonts/timesi.ttf", 50.0, false, false, Agg2D::VectorFontCache);
#else
	g->font("Times New Roman", 50.0, false, false, Agg2D::VectorFontCache);
#endif
	g->lineColor(50, 0, 0);
	g->fillColor(180, 200, 100);
	g->lineWidth(1.0);
	g->text(100.5, 50.5, "Outlined Text");

	// Text Alignment
	g->line(250.5-150, 150.5,    250.5+150, 150.5);
	g->line(250.5,     150.5-20, 250.5,     150.5+20);
	g->line(250.5-150, 200.5,    250.5+150, 200.5);
	g->line(250.5,     200.5-20, 250.5,     200.5+20);
	g->line(250.5-150, 250.5,    250.5+150, 250.5);
	g->line(250.5,     250.5-20, 250.5,     250.5+20);
	g->line(250.5-150, 300.5,    250.5+150, 300.5);
	g->line(250.5,     300.5-20, 250.5,     300.5+20);
	g->line(250.5-150, 350.5,    250.5+150, 350.5);
	g->line(250.5,     350.5-20, 250.5,     350.5+20);
	g->line(250.5-150, 400.5,    250.5+150, 400.5);
	g->line(250.5,     400.5-20, 250.5,     400.5+20);
	g->line(250.5-150, 450.5,    250.5+150, 450.5);
	g->line(250.5,     450.5-20, 250.5,     450.5+20);
	g->line(250.5-150, 500.5,    250.5+150, 500.5);
	g->line(250.5,     500.5-20, 250.5,     500.5+20);
	g->line(250.5-150, 550.5,    250.5+150, 550.5);
	g->line(250.5,     550.5-20, 250.5,     550.5+20);


	g->fillColor(100, 50, 50);
	g->noLine();
	//g->textHints(false);
#ifdef AGG2D_USE_FREETYPE
	g->font("c:/WINDOWS/fonts/timesi.ttf", 40.0, false, false, Agg2D::VectorFontCache);
#else
	g->font("Times New Roman", 40.0, false, false, Agg2D::VectorFontCache);
#endif

	g->textAlignment(Agg2D::AlignLeft, Agg2D::AlignBottom);
	g->text(250.0,     150.0, "Left-Bottom", true, 0, 0);

	g->textAlignment(Agg2D::AlignCenter, Agg2D::AlignBottom);
	g->text(250.0,     200.0, "Center-Bottom", true, 0, 0);

	g->textAlignment(Agg2D::AlignRight, Agg2D::AlignBottom);
	g->text(250.0,     250.0, "Right-Bottom", true, 0, 0);

	g->textAlignment(Agg2D::AlignLeft, Agg2D::AlignCenter);
	g->text(250.0,     300.0, "Left-Center", true, 0, 0);

	g->textAlignment(Agg2D::AlignCenter, Agg2D::AlignCenter);
	g->text(250.0,     350.0, "Center-Center", true, 0, 0);

	g->textAlignment(Agg2D::AlignRight, Agg2D::AlignCenter);
	g->text(250.0,     400.0, "Right-Center", true, 0, 0);

	g->textAlignment(Agg2D::AlignLeft, Agg2D::AlignTop);
	g->text(250.0,     450.0, "Left-Top", true, 0, 0);

	g->textAlignment(Agg2D::AlignCenter, Agg2D::AlignTop);
	g->text(250.0,     500.0, "Center-Top", true, 0, 0);

	g->textAlignment(Agg2D::AlignRight, Agg2D::AlignTop);
	g->text(250.0,     550.0, "Right-Top", true, 0, 0);


	// Gradients (Aqua Buttons)
	//=======================================
#ifdef AGG2D_USE_FREETYPE
	g->font("c:/WINDOWS/fonts/verdanab.ttf", 20.0, false, false, Agg2D::VectorFontCache);
#else
	g->font("Verdana", 20.0, false, false, Agg2D::VectorFontCache);
#endif
	double xb1 = 400;
	double yb1 = 80;
	double xb2 = xb1 + 150;
	double yb2 = yb1 + 36;

	g->fillColor(Agg2D::Color(0,50,180,180));
	g->lineColor(Agg2D::Color(0,0,80, 255));
	g->lineWidth(1.0);
	g->roundedRect(xb1, yb1, xb2, yb2, 12, 18);

	g->lineColor(Agg2D::Color(0,0,0,0));
	g->fillLinearGradient(xb1, yb1, xb1, yb1+30,
		Agg2D::Color(100,200,255,255),
		Agg2D::Color(255,255,255,0));
	g->roundedRect(xb1+3, yb1+2.5, xb2-3, yb1+30, 9, 18, 1, 1);

	g->fillColor(Agg2D::Color(0,0,50, 200));
	g->noLine();
	g->textAlignment(Agg2D::AlignCenter, Agg2D::AlignCenter);
	g->text((xb1 + xb2) / 2.0, (yb1 + yb2) / 2.0, "Aqua Button", true, 0.0, 0.0);

	g->fillLinearGradient(xb1, yb2-20, xb1, yb2-3,
		Agg2D::Color(0,  0,  255,0),
		Agg2D::Color(100,255,255,255));
	g->roundedRect(xb1+3, yb2-20, xb2-3, yb2-2, 1, 1, 9, 18);


	// Aqua Button Pressed
	xb1 = 400;
	yb1 = 30;
	xb2 = xb1 + 150;
	yb2 = yb1 + 36;

	g->fillColor(Agg2D::Color(0,50,180,180));
	g->lineColor(Agg2D::Color(0,0,0,  255));
	g->lineWidth(2.0);
	g->roundedRect(xb1, yb1, xb2, yb2, 12, 18);

	g->lineColor(Agg2D::Color(0,0,0,0));
	g->fillLinearGradient(xb1, yb1+2, xb1, yb1+25,
		Agg2D::Color(60, 160,255,255),
		Agg2D::Color(100,255,255,0));
	g->roundedRect(xb1+3, yb1+2.5, xb2-3, yb1+30, 9, 18, 1, 1);

	g->fillColor(Agg2D::Color(0,0,50, 255));
	g->noLine();
	g->textAlignment(Agg2D::AlignCenter, Agg2D::AlignCenter);
	g->text((xb1 + xb2) / 2.0, (yb1 + yb2) / 2.0, "Aqua Pressed", 0.0, 0.0);

	g->fillLinearGradient(xb1, yb2-25, xb1, yb2-5,
		Agg2D::Color(0,  180,255,0),
		Agg2D::Color(0,  200,255,255));
	g->roundedRect(xb1+3, yb2-25, xb2-3, yb2-2, 1, 1, 9, 18);




	// Basic Shapes -- Ellipse
	//===========================================
	g->lineWidth(3.5);
	g->lineColor(20,  80,  80);
	g->fillColor(200, 255, 80, 200);
	g->ellipse(450, 200, 50, 90);


	// Paths
	//===========================================
	g->resetPath();
	g->fillColor(255, 0, 0, 100);
	g->lineColor(0, 0, 255, 100);
	g->lineWidth(2);
	g->moveTo(300/2, 200/2);
	g->horLineRel(-150/2);
	g->arcRel(150/2, 150/2, 0, 1, 0, 150/2, -150/2);
	g->closePolygon();
	g->drawPath();

	g->resetPath();
	g->fillColor(255, 255, 0, 100);
	g->lineColor(0, 0, 255, 100);
	g->lineWidth(2);
	g->moveTo(275/2, 175/2);
	g->verLineRel(-150/2);
	g->arcRel(150/2, 150/2, 0, 0, 0, -150/2, 150/2);
	g->closePolygon();
	g->drawPath();


	g->resetPath();
	g->noFill();
	g->lineColor(127, 0, 0);
	g->lineWidth(5);
	g->moveTo(600/2, 350/2);
	g->lineRel(50/2, -25/2);
	g->arcRel(25/2, 25/2, Agg2D::deg2Rad(-30), 0, 1, 50/2, -25/2);
	g->lineRel(50/2, -25/2);
	g->arcRel(25/2, 50/2, Agg2D::deg2Rad(-30), 0, 1, 50/2, -25/2);
	g->lineRel(50/2, -25/2);
	g->arcRel(25/2, 75/2, Agg2D::deg2Rad(-30), 0, 1, 50/2, -25/2);
	g->lineRel(50, -25);
	g->arcRel(25/2, 100/2, Agg2D::deg2Rad(-30), 0, 1, 50/2, -25/2);
	g->lineRel(50/2, -25/2);
	g->drawPath();


	// Master Alpha. From now on everything will be translucent
	//===========================================
	g->masterAlpha(0.85);

/*
	// Image Transformations
	//===========================================
	Agg2D::Image img(rbuf_img(0).buf(),
		rbuf_img(0).width(),
		rbuf_img(0).height(),
		rbuf_img(0).stride());
	g->imageFilter(Agg2D::Bilinear);

	//g->imageResample(Agg2D::NoResample);
	//g->imageResample(Agg2D::ResampleAlways);
	g->imageResample(Agg2D::ResampleOnZoomOut);

	// Set the initial image blending operation as BlendDst, that actually
	// does nothing.
	//-----------------
	g->imageBlendMode(Agg2D::BlendDst);
*/

	// Transform the whole image to the destination rectangle
	//-----------------
	//g->transformImage(img, 450, 200, 595, 350);

	// Transform the rectangular part of the image to the destination rectangle
	//-----------------
	//g->transformImage(img, 60, 60, img.width()-60, img.height()-60,
	//                          450, 200, 595, 350);

	// Transform the whole image to the destination parallelogram
	//-----------------
	//double parl[6] = { 450, 200, 595, 220, 575, 350 };
	//g->transformImage(img, parl);

	// Transform the rectangular part of the image to the destination parallelogram
	//-----------------
	//double parl[6] = { 450, 200, 595, 220, 575, 350 };
	//g->transformImage(img, 60, 60, img.width()-60, img.height()-60, parl);

	// Transform image to the destination path. The scale is determined by a rectangle
	//-----------------
	//g->resetPath();
	//g->moveTo(450, 200);
	//g->cubicCurveTo(595, 220, 575, 350, 595, 350);
	//g->lineTo(470, 340);
	//g->transformImagePath(img, 450, 200, 595, 350);

/*
	// Transform image to the destination path.
	// The scale is determined by a rectangle
	//-----------------
	g->resetPath();
	g->moveTo(450, 200);
	g->cubicCurveTo(595, 220, 575, 350, 595, 350);
	g->lineTo(470, 340);
	g->transformImagePath(img, 60, 60, img.width()-60, img.height()-60,
		450, 200, 595, 350);
*/

	// Transform image to the destination path.
	// The transformation is determined by a parallelogram
	//g->resetPath();
	//g->moveTo(450, 200);
	//g->cubicCurveTo(595, 220, 575, 350, 595, 350);
	//g->lineTo(470, 340);
	//double parl[6] = { 450, 200, 595, 220, 575, 350 };
	//g->transformImagePath(img, parl);

	// Transform the rectangular part of the image to the destination path.
	// The transformation is determined by a parallelogram
	//g->resetPath();
	//g->moveTo(450, 200);
	//g->cubicCurveTo(595, 220, 575, 350, 595, 350);
	//g->lineTo(470, 340);
	//double parl[6] = { 450, 200, 595, 220, 575, 350 };
	//g->transformImagePath(img, 60, 60, img.width()-60, img.height()-60, parl);


	// Add/Sub/Contrast Blending Modes
	g->noLine();
	g->fillColor(70, 70, 0);
	g->blendMode(Agg2D::BlendAdd);
	g->ellipse(500, 280, 20, 40);

	g->fillColor(255, 255, 255);
	g->blendMode(Agg2D::BlendContrast);
	g->ellipse(500+40, 280, 20, 40);



	// Radial gradient.
	g->blendMode(Agg2D::BlendAlpha);
	g->fillRadialGradient(400, 500, 40,
		Agg2D::Color(255, 255, 0, 0),
		Agg2D::Color(0, 0, 127),
		Agg2D::Color(0, 255, 0, 0));
	g->ellipse(400, 500, 40, 40);


	DELETE(g);

}