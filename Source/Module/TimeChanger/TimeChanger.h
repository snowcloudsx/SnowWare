#pragma once
#include "../../JNI/Helper/Java.h"
class TimeChanger {
public:
	static inline bool enabled;
	static inline int time;
	void runModule(jlong time);
	void onDisable();

};