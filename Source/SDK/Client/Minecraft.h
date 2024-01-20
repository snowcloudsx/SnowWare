#pragma once
#include "../../JNI/jni.h"
class Minecraft {
public:
	Minecraft(jobject);
	jobject CurrentObject = NULL;
	static void setTimer(float value);
	
};
