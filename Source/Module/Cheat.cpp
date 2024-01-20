#include "Cheat.h"
#include "../JNI/Helper/Java.h"
#include <chrono>
#include <iostream>
#include <Windows.h>
#include <thread>
#include <string>
#include "SDK.h"
#include "../ImGui/imgui.h"
#include "../SDK/Entity/Player/Player.h"
#include "Step/Step.h"
#include "TimeChanger/TimeChanger.h"
#include "AutoSprint/sprint.h"
#include "Flight/Flight.h"
#include "Fullbright/Fullbright.h"
#include "Velocity/Velocity.h"
#include "../Mapper/Mapper.h"
#include "NameChanger/Name.h"
#include "../SDK/World/World.h"
#include "settings/settings.h"
#include "Combat/Reach/Reach.h"
#include "Combat/AutoClicker/AutoClicker.h"
#include "Combat/Bhop/bhop.h"
#include "Combat/JumpReset/JumpReset.h"
#include "Combat/NoSlow/NoSlow.h"


jclass SDK::getMinecraftClass()
{
	return mc.env->FindClass("ave");
}

jobject SDK::getMinecraft()
{
	jmethodID getMinecraftMethod = mc.env->GetStaticMethodID(getMinecraftClass(), "A", "()Lave;");
	return mc.env->CallStaticObjectMethod(getMinecraftClass(), getMinecraftMethod);

}



void setRightClickDelay() {
	jfieldID mouse_delayID{ mc.env->GetFieldID(SDK::getMinecraftClass(), "ap", "I") };
	
	if (mouse_delayID != NULL) {
		mc.env->SetIntField(SDK::getMinecraft(), mouse_delayID, 0);

	}


}





bool isSneaking() {

	jmethodID setSneak = mc.env->GetMethodID(mc.env->GetObjectClass(CPlayer::getPlayer()), "av", "()Z");
	bool rtrn = mc.env->CallBooleanMethod(CPlayer::getPlayer(), setSneak);
	return rtrn;

}



bool is_alive() {
	jmethodID alive = mc.env->GetMethodID(mc.env->GetObjectClass(CPlayer::getPlayer()), "ai", "()Z");
	return mc.env->CallBooleanMethod(CPlayer::getPlayer(), alive);
}

float get_x() {
	jfieldID get_x = mc.env->GetFieldID(mc.env->GetObjectClass(CPlayer::getPlayer()), "s", "D");
	return mc.env->GetDoubleField(CPlayer::getPlayer(), get_x);
}

float get_y() {
	jfieldID get_y = mc.env->GetFieldID(mc.env->GetObjectClass(CPlayer::getPlayer()), "t", "D");
	return mc.env->GetDoubleField(CPlayer::getPlayer(), get_y);
}

float get_z() {
	jfieldID get_z = mc.env->GetFieldID(mc.env->GetObjectClass(CPlayer::getPlayer()), "u", "D");
	return mc.env->GetDoubleField(CPlayer::getPlayer(), get_z);
}


jobject get_capabilities() {
	jfieldID get_capabilities = mc.env->GetFieldID(mc.env->GetObjectClass(SDK::getMinecraft()), "bA", "Lwn;");
	return mc.env->GetObjectField(SDK::getMinecraft(), get_capabilities);
}






void set_yaw(jfloat yaw) {
//"y", "F"
	jfieldID set_yaw = mc.env->GetFieldID(mc.env->GetObjectClass(CPlayer::getPlayer()), "y", "F");
	mc.env->SetFloatField(CPlayer::getPlayer(), set_yaw, yaw);
}

void set_pitch(jfloat pitch) {
	jfieldID set_pitch = mc.env->GetFieldID(mc.env->GetObjectClass(CPlayer::getPlayer()), "z", "F");
	mc.env->SetFloatField(CPlayer::getPlayer(), set_pitch, pitch);
}

float get_pitch() {
	jfieldID get_pitch = mc.env->GetFieldID(mc.env->GetObjectClass(CPlayer::getPlayer()), "z", "F");
	return mc.env->GetFloatField(CPlayer::getPlayer(), get_pitch);
}

float get_yaw() {
	jfieldID get_yaw = mc.env->GetFieldID(mc.env->GetObjectClass(CPlayer::getPlayer()), "y", "F");
	return mc.env->GetFloatField(CPlayer::getPlayer(), get_yaw);
}

float getHealth() {
	//jfieldID entityLivingBase_getHealth = mc.env->GetFieldID(SDK::getEntityLivingBase(), "bn", "()F");
	//return mc.env->GetFloatField(SDK::getEntityLivingBase(), entityLivingBase_getHealth);

}

void setFlySpeed(int flySpeed) {
	jfieldID flypeed = mc.env->GetFieldID(mc.env->GetObjectClass(get_capabilities()), "a", "(F)V");
	mc.env->SetIntField(CPlayer::getPlayer(), flypeed, flySpeed);
}

void set_flight(jboolean state) {
	jfieldID set_flight = mc.env->GetFieldID(mc.env->GetObjectClass(get_capabilities()), "b", "Z");
	mc.env->SetBooleanField(get_capabilities(), set_flight, state);
}






void cheats::onModuleTick() {
	Step step;
	step.stepHeight = 1.5f;
	
	TimeChanger time;
	//time.time = 1000;
	Bhop bhop;
	bhop.speed = 1.01;
	Sprint sprint;
	Flight flight;
	AutoClicker clicker;
	Fullbright gamma;
	Velocity velocity;
	NameChanger name;
	Reach reach;
	JumpReset jr;
	NoSlow noslow;


	static double baseX = CPlayer::get_motion_x();
	static double baseY = CPlayer::get_motion_y();
		
	
	while (true) {
		if (!SDK::getMinecraft()) continue;
		if (!CWorld::getWorld()) continue;
		if (!CPlayer::getPlayer()) continue;

	
		if (step.enabled){
			step.runModule(step.stepHeight);
		}
		else if (!step.enabled) {
			step.onDisable();
		}
		if (time.enabled) {
			time.runModule(time.time);
		}
		else if (!time.enabled) {
			time.onDisable();
		}
		if (bhop.enabled) {
			bhop.runModule();

		}
		else if (!bhop.enabled) {
			bhop.onDisable();
		}

		if (sprint.enabled) {
			sprint.runModule(true);
		}
		else if (!sprint.enabled) {
			//sprint
		}
		if (flight.enabled) {
			flight.runModule(true);
		}
		else if (!flight.enabled) {
			flight.onDisable();
		}
		
		if (clicker.enabled) {
			if(GetAsyncKeyState(VK_LBUTTON))
				clicker.runModule();
		}
		if (gamma.enabled) {
			gamma.runModule();
		}
		else if (!gamma.enabled)
		{
			gamma.onDisable();
		}
		if (velocity.enabled) {
	        velocity.runModule();
		}
		else if (!velocity.enabled) {
			//velocity.onDisable();
		}
		if (name.enabled) {
			name.runModule();
		}
		else if (!name.enabled) {
			//name.onDisable()
		}
		if (settings::Reach) {
			reach.runModule();
		}
		else if (!settings::Reach) {
			settings::dist = 3.2;
		}
		if (settings::JumpReset) {
			jr.runModule();
		}
		if (settings::NoSlow) {
			noslow.OnTick();
		}

		//setRightClickDelay();
		//std::cout << CPlayer::isBlocking() << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(5));

	}


}


