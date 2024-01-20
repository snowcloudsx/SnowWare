#pragma once
#include "../JNI/Helper/Java.h"

class SDK {
public:
	static jclass getMinecraftClass();
	static jobject getMinecraft();
	static jclass getMinecraftClassForge();

};