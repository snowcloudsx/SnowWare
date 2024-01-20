#include "TimeChanger.h"
#include "../SDK.h"
#include "../../SDK/World/World.h"

inline bool reset = false;


void TimeChanger::runModule(jlong time)
{
	
	jmethodID set_time = mc.env->GetMethodID(mc.env->GetObjectClass(CWorld::getWorld()), "b", "(J)V");
	mc.env->CallLongMethod(CWorld::getWorld(), set_time, time);
	
}

void TimeChanger::onDisable()
{
	jmethodID set_time = mc.env->GetMethodID(mc.env->GetObjectClass(CWorld::getWorld()), "b", "(J)V");

	if(reset = false)
		mc.env->CallLongMethod(CWorld::getWorld(), set_time, 0);
		reset = true;
}
