//
// Created by Administrator on 2018/1/25 0025.
//
#include <jni.h>
extern "C"
JNIEXPORT Mat* JNICALL
Java_com_mygrabcut_mygrabcut_NativeGrabCut_grabCutFromJNI(JNIEnv *env, jobject instance, jlong m,
                                                          jint l, jint t, jint r, jint b) {


        // TODO
        Mat *img = (Mat *) m ;

        Rect rect(l,t,r - l,b - t);

        Mat firstMask;
        Mat bgModel;
        Mat fgModel;

        grabCut(*img,
                firstMask,
                rect,
                bgModel,fgModel,
                5,
                GC_INIT_WITH_RECT);
        compare(firstMask,GC_PR_FGD,firstMask,CMP_EQ);

        Mat *foreground = new Mat(img->size(),CV_8UC3,Scalar(255,255,255));

        img->copyTo(*foreground,firstMask);

        return foreground;


    }