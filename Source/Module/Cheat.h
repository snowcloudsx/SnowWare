
#pragma once
#include <cstddef>
#include "../SDK/Client/Minecraft.h"

class cheats{
public:
	static void onModuleTick();
	static int* newValue;
	static inline double baseX;
	static inline double baseY;
	inline static jclass minecraftClass = NULL;
	inline static jfieldID getMinecraftFieldID = NULL;
	inline static Minecraft MinecraftInstance = NULL;
	inline static jobject getMinecraftObject = NULL;
	inline static jmethodID setDisplayNameTagMethodID = NULL;


};

