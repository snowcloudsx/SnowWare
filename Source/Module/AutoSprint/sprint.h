#pragma once
#include "../../JNI/Helper/Java.h"

class Sprint {
public:
	static inline char keybind;
	static inline bool enabled;
	static inline bool blatent;
	void runModule(jboolean sprinting);
	void onDisable();
};