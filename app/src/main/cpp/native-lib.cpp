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
    agg2D->viewport(0, 0, width, height,
                    0, 0, width, height, Agg2D::XMidYMid);

    agg2D->fillColor(255, 0, 0, 127);
    agg2D->rectangle(0, 0, width, height);


    DELETE(agg2D);

    LOGI("testAgg2D...............: success");
}

};