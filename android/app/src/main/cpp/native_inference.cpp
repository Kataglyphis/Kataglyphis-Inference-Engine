#include <jni.h>
#include <android/log.h>

#define LOG_TAG "NativeInferencePlugin"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_kataglyphis_1inference_1engine_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    LOGI("Native inference plugin loaded");
    return env->NewStringUTF("Native Inference Plugin with GStreamer");
}
