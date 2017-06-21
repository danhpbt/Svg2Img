#include <jni.h>
#include <string>
#include "common/TypeDef.h"
#include "agg_2.5/agg2d.h"


#define BYTES_PER_PIXEL 4

extern "C"
{
JNIEXPORT jstring JNICALL
Java_com_xynotec_svg2img_ActivityMain_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

JNIEXPORT void JNICALL
Java_com_xynotec_svg2img_SvgView_testAgg2D(JNIEnv* env, jobject thizz, jintArray intData, int width, int height) {

    LOGI("Width...............: %d", width);
    LOGI("Height..............: %d", height);

    jint *data = env->GetIntArrayElements(intData, NULL);

    Agg2D *agg2D = new Agg2D();
    agg2D->attach((unsigned char *) data, width, height, width * BYTES_PER_PIXEL);

//    agg2D->viewport(0, 0, width, height,
//                    0, 0, width, height, Agg2D::XMidYMid);
//
//    agg2D->fillColor(255, 0, 0, 127);
//    agg2D->rectangle(0, 0, width, height);

    agg2D->viewport(0, 0, 600, 600, 0, 0, width, height, Agg2D::XMidYMid);


    // Rounded Rect
    agg2D->lineColor(0, 0, 0);
    agg2D->noFill();
    agg2D->roundedRect(0.5, 0.5, 600-0.5, 600-0.5, 20.0);


    agg2D->fillColor(0, 0, 0);
    agg2D->noLine();

    agg2D->lineColor(50, 0, 0);
    agg2D->fillColor(180, 200, 100);
    agg2D->lineWidth(1.0);

    // Text Alignment
    agg2D->line(250.5-150, 150.5,    250.5+150, 150.5);
    agg2D->line(250.5,     150.5-20, 250.5,     150.5+20);
    agg2D->line(250.5-150, 200.5,    250.5+150, 200.5);
    agg2D->line(250.5,     200.5-20, 250.5,     200.5+20);
    agg2D->line(250.5-150, 250.5,    250.5+150, 250.5);
    agg2D->line(250.5,     250.5-20, 250.5,     250.5+20);
    agg2D->line(250.5-150, 300.5,    250.5+150, 300.5);
    agg2D->line(250.5,     300.5-20, 250.5,     300.5+20);
    agg2D->line(250.5-150, 350.5,    250.5+150, 350.5);
    agg2D->line(250.5,     350.5-20, 250.5,     350.5+20);
    agg2D->line(250.5-150, 400.5,    250.5+150, 400.5);
    agg2D->line(250.5,     400.5-20, 250.5,     400.5+20);
    agg2D->line(250.5-150, 450.5,    250.5+150, 450.5);
    agg2D->line(250.5,     450.5-20, 250.5,     450.5+20);
    agg2D->line(250.5-150, 500.5,    250.5+150, 500.5);
    agg2D->line(250.5,     500.5-20, 250.5,     500.5+20);
    agg2D->line(250.5-150, 550.5,    250.5+150, 550.5);
    agg2D->line(250.5,     550.5-20, 250.5,     550.5+20);


    agg2D->fillColor(100, 50, 50);
    agg2D->noLine();

    double xb1 = 400;
    double yb1 = 80;
    double xb2 = xb1 + 150;
    double yb2 = yb1 + 36;

    agg2D->fillColor(Agg2D::Color(0,50,180,180));
    agg2D->lineColor(Agg2D::Color(0,0,80, 255));
    agg2D->lineWidth(1.0);
    agg2D->roundedRect(xb1, yb1, xb2, yb2, 12, 18);

    agg2D->lineColor(Agg2D::Color(0,0,0,0));
    agg2D->fillLinearGradient(xb1, yb1, xb1, yb1+30,
    Agg2D::Color(100,200,255,255),
    Agg2D::Color(255,255,255,0));
    agg2D->roundedRect(xb1+3, yb1+2.5, xb2-3, yb1+30, 9, 18, 1, 1);

    agg2D->fillColor(Agg2D::Color(0,0,50, 200));
    agg2D->noLine();

    agg2D->fillLinearGradient(xb1, yb2-20, xb1, yb2-3,
    Agg2D::Color(0,  0,  255,0),
    Agg2D::Color(100,255,255,255));
    agg2D->roundedRect(xb1+3, yb2-20, xb2-3, yb2-2, 1, 1, 9, 18);


    // Aqua Button Pressed
    xb1 = 400;
    yb1 = 30;
    xb2 = xb1 + 150;
    yb2 = yb1 + 36;

    agg2D->fillColor(Agg2D::Color(0,50,180,180));
    agg2D->lineColor(Agg2D::Color(0,0,0,  255));
    agg2D->lineWidth(2.0);
    agg2D->roundedRect(xb1, yb1, xb2, yb2, 12, 18);

    agg2D->lineColor(Agg2D::Color(0,0,0,0));
    agg2D->fillLinearGradient(xb1, yb1+2, xb1, yb1+25,
    Agg2D::Color(60, 160,255,255),
    Agg2D::Color(100,255,255,0));
    agg2D->roundedRect(xb1+3, yb1+2.5, xb2-3, yb1+30, 9, 18, 1, 1);

    agg2D->fillColor(Agg2D::Color(0,0,50, 255));
    agg2D->noLine();

    agg2D->fillLinearGradient(xb1, yb2-25, xb1, yb2-5,
    Agg2D::Color(0,  180,255,0),
    Agg2D::Color(0,  200,255,255));
    agg2D->roundedRect(xb1+3, yb2-25, xb2-3, yb2-2, 1, 1, 9, 18);




    // Basic Shapes -- Ellipse
    //===========================================
    agg2D->lineWidth(3.5);
    agg2D->lineColor(20,  80,  80);
    agg2D->fillColor(200, 255, 80, 200);
    agg2D->ellipse(450, 200, 50, 90);


    // Paths
    //===========================================
    agg2D->resetPath();
    agg2D->fillColor(255, 0, 0, 100);
    agg2D->lineColor(0, 0, 255, 100);
    agg2D->lineWidth(2);
    agg2D->moveTo(300/2, 200/2);
    agg2D->horLineRel(-150/2);
    agg2D->arcRel(150/2, 150/2, 0, 1, 0, 150/2, -150/2);
    agg2D->closePolygon();
    agg2D->drawPath();

    agg2D->resetPath();
    agg2D->fillColor(255, 255, 0, 100);
    agg2D->lineColor(0, 0, 255, 100);
    agg2D->lineWidth(2);
    agg2D->moveTo(275/2, 175/2);
    agg2D->verLineRel(-150/2);
    agg2D->arcRel(150/2, 150/2, 0, 0, 0, -150/2, 150/2);
    agg2D->closePolygon();
    agg2D->drawPath();


    agg2D->resetPath();
    agg2D->noFill();
    agg2D->lineColor(127, 0, 0);
    agg2D->lineWidth(5);
    agg2D->moveTo(600/2, 350/2);
    agg2D->lineRel(50/2, -25/2);
    agg2D->arcRel(25/2, 25/2, Agg2D::deg2Rad(-30), 0, 1, 50/2, -25/2);
    agg2D->lineRel(50/2, -25/2);
    agg2D->arcRel(25/2, 50/2, Agg2D::deg2Rad(-30), 0, 1, 50/2, -25/2);
    agg2D->lineRel(50/2, -25/2);
    agg2D->arcRel(25/2, 75/2, Agg2D::deg2Rad(-30), 0, 1, 50/2, -25/2);
    agg2D->lineRel(50, -25);
    agg2D->arcRel(25/2, 100/2, Agg2D::deg2Rad(-30), 0, 1, 50/2, -25/2);
    agg2D->lineRel(50/2, -25/2);
    agg2D->drawPath();


    // Master Alpha. From now on everything will be translucent
    //===========================================
    agg2D->masterAlpha(0.85);


    // Add/Sub/Contrast Blending Modes
    agg2D->noLine();
    agg2D->fillColor(70, 70, 0);
    agg2D->blendMode(Agg2D::BlendAdd);
    agg2D->ellipse(500, 280, 20, 40);

    agg2D->fillColor(255, 255, 255);
    agg2D->blendMode(Agg2D::BlendContrast);
    agg2D->ellipse(500+40, 280, 20, 40);



    // Radial gradient.
    agg2D->blendMode(Agg2D::BlendAlpha);
    agg2D->fillRadialGradient(400, 500, 40,
    Agg2D::Color(255, 255, 0, 0),
    Agg2D::Color(0, 0, 127),
    Agg2D::Color(0, 255, 0, 0));
    agg2D->ellipse(400, 500, 40, 40);

    DELETE(agg2D);

    LOGI("testAgg2D...............: success");
}

};