#pragma once
#include "../jni.h"


class Java
{
public:
	JavaVM* vm;
	JNIEnv* env;

	JavaVMInitArgs args;
}mc;