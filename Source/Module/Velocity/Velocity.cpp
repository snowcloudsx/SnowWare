#include "Velocity.h"
#include "../../JNI/Helper/Java.h"
#include "../../SDK/Entity/Player/Player.h"
#include <iostream>

jfieldID motionX;
jfieldID motionY;
jfieldID motionZ;


void getMotionX() {
	if (motionX != NULL) {
		motionX = mc.env->GetFieldID(CPlayer::getPlayerClass(), "b", "()I");
		mc.env->GetIntField(CPlayer::getPlayer(), motionX);
	}
}
void getMotionY() {
	if (motionY != NULL) {
		motionY = mc.env->GetFieldID(CPlayer::getPlayerClass(), "c", "()I");
		mc.env->GetIntField(CPlayer::getPlayer(), motionY);

	}
}

void getMotionZ() {
	if (motionZ != NULL) {
		motionZ = mc.env->GetFieldID(CPlayer::getPlayerClass(), "d", "()I");
		mc.env->GetIntField(CPlayer::getPlayer(), motionY);

	}
}

void setVelocity(double x, double y, double z) {
	jmethodID setvelocity = mc.env->GetMethodID(mc.env->GetObjectClass(CPlayer::getPlayer()), "i", "(DDD)V");
	mc.env->CallVoidMethod(CPlayer::getPlayer(), setvelocity, x, y, z);
}


void Velocity::setMotionX(int value) {
	mc.env->SetDoubleField(CPlayer::getPlayer(), motionX, value);
}
void Velocity::setMotionY(int value) {
	mc.env->SetDoubleField(CPlayer::getPlayer(), motionY, value);
}
void Velocity::setMotionZ(int value) {
	mc.env->SetDoubleField(CPlayer::getPlayer(), motionZ, value);
}

void Velocity::runModule()
{
	if (CPlayer::gethurttime() > 0)
	{
		getMotionX();
		getMotionY();
		getMotionZ();
		Velocity::setMotionX(Velocity::Vx);
		Velocity::setMotionY(Velocity::Vy);
		Velocity::setMotionY(Velocity::Vz);

	}
}

void Velocity::onDisable()
{
	//there nothing
}
