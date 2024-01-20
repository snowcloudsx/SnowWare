#pragma once
#include "../../JNI/Helper/Java.h"

class NameChanger {
public:
	inline static bool enabled;
	inline static char name[256];
	void setName(char* name);
	void runModule();
};