/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_cardiograph_jni_JNI_Interface */
#include <stdio.h>
#include "mclmcr.h"
#ifndef _Included_com_cardiograph_jni_JNI_Interface
#define _Included_com_cardiograph_jni_JNI_Interface
#ifdef __cplusplus
extern "C" {
#endif
extern const unsigned char __MCC_trapper1105_public_data[];
extern const char *__MCC_trapper1105_name_data;
extern const char *__MCC_trapper1105_root_data;
extern const unsigned char __MCC_trapper1105_session_data[];
extern const char *__MCC_trapper1105_matlabpath_data[];
extern const int __MCC_trapper1105_matlabpath_data_count;
extern const char *__MCC_trapper1105_classpath_data[];
extern const int __MCC_trapper1105_classpath_data_count;
extern const char *__MCC_trapper1105_lib_path_data[];
extern const int __MCC_trapper1105_lib_path_data_count;
extern const char *__MCC_trapper1105_mcr_runtime_options[];
extern const int __MCC_trapper1105_mcr_runtime_option_count;
extern const char *__MCC_trapper1105_mcr_application_options[];
extern const int __MCC_trapper1105_mcr_application_option_count;
/*
 * Class:     com_cardiograph_jni_JNI_Interface
 * Method:    getCInt
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_cardiograph_jni_JNI_1Interface_getCInt(JNIEnv *env, jobject jobj)
{
	int x, y;
	x = 10;
	y = 20;
	x += y;
	return x;
}

/*
 * Class:     com_cardiograph_jni_JNI_Interface
 * Method:    getCString
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_cardiograph_jni_JNI_1Interface_getCString(JNIEnv *env, jobject jobj)
{
	return (*env)->NewStringUTF(env, "getCString  Hello from JNI !");
}

/*
 * Class:     com_cardiograph_jni_JNI_Interface
 * Method:    trapper
 * Signature: (FF)F
 */
JNIEXPORT jfloat JNICALL Java_com_cardiograph_jni_JNI_1Interface_trapper(JNIEnv *env, jobject jobj, jfloat data, jfloat fs)
{
	return 20.0;
}
#ifdef __cplusplus
}
#endif
#endif

static HMCRINSTANCE _mcr_inst = NULL;


static int mclDefaultPrintHandler(const char *s)
{
    return fwrite(s, sizeof(char), strlen(s), stdout);
}

static int mclDefaultErrorHandler(const char *s)
{
    int written = 0, len = 0;
    len = strlen(s);
    written = fwrite(s, sizeof(char), len, stderr);
    if (len > 0 && s[ len-1 ] != '\n')
        written += fwrite("\n", sizeof(char), 1, stderr);
    return written;
}


/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library.
 */
#ifndef LIB_trapper1105_C_API
#define LIB_trapper1105_C_API /* No special import/export declaration */
#endif

LIB_trapper1105_C_API
bool trapper1105InitializeWithHandlers(
    mclOutputHandlerFcn error_handler,
    mclOutputHandlerFcn print_handler
)
{
    if (_mcr_inst != NULL)
        return true;
    if (!mclmcrInitialize())
        return false;
    if (!mclInitializeComponentInstance(&_mcr_inst,
                                        __MCC_trapper1105_public_data,
                                        __MCC_trapper1105_name_data,
                                        __MCC_trapper1105_root_data,
                                        __MCC_trapper1105_session_data,
                                        __MCC_trapper1105_matlabpath_data,
                                        __MCC_trapper1105_matlabpath_data_count,
                                        __MCC_trapper1105_classpath_data,
                                        __MCC_trapper1105_classpath_data_count,
                                        __MCC_trapper1105_lib_path_data,
                                        __MCC_trapper1105_lib_path_data_count,
                                        __MCC_trapper1105_mcr_runtime_options,
                                        __MCC_trapper1105_mcr_runtime_option_count,
                                        true, NoObjectType, ExeTarget, NULL,
                                        error_handler, print_handler))
        return false;
    return true;
}

LIB_trapper1105_C_API
bool trapper1105Initialize(void)
{
    return trapper1105InitializeWithHandlers(mclDefaultErrorHandler,
                                             mclDefaultPrintHandler);
}

LIB_trapper1105_C_API
void trapper1105Terminate(void)
{
    if (_mcr_inst != NULL)
        mclTerminateInstance(&_mcr_inst);
}

int main(int argc, const char **argv)
{
    int _retval;
    if (!mclInitializeApplication(__MCC_trapper1105_mcr_application_options,
                                  __MCC_trapper1105_mcr_application_option_count))
        return 0;

    if (!trapper1105Initialize())
        return -1;
    _retval = mclMain(_mcr_inst, argc, argv, "trapper1105", 1);
    if (_retval == 0 /* no error */) mclWaitForFiguresToDie(NULL);
    trapper1105Terminate();
    mclTerminateApplication();
    return _retval;
}

