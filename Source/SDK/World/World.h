#pragma once
#include "../../JNI/Helper/Java.h"
#include "../../Module/SDK.h"
class CWorld {
public:
	static jobject getWorld() {
		jfieldID getWorldField = mc.env->GetFieldID(SDK::getMinecraftClass(), "f", "Lbdb;");
		return mc.env->GetObjectField(SDK::getMinecraft(), getWorldField);

	}

	
};
