#include "../../../JNI/Helper/Java.h"
#include "../../../Module/SDK.h"
#include "../../Utils/Player/vec3.hpp"
#include "../../Source/Mapper/Mapper.h"
#include "iostream"
#include <Windows.h>
class CPlayer {
	
public:
	static inline jfieldID ongroundfd;




	static jclass getPlayerClass() {
		return mc.env->FindClass("bew");
	}


	static jobject getPlayer() {
		jfieldID getPlayerField = mc.env->GetFieldID(SDK::getMinecraftClass(), "h", "Lbew;");

		return mc.env->GetObjectField(SDK::getMinecraft(), getPlayerField);
	}
	static jclass getEntityLivingBase() {
		return mc.env->FindClass("pr");
	}

	static jobject get_capabilities() {
		jfieldID get_capabilities = mc.env->GetFieldID(mc.env->GetObjectClass(getPlayer()), "bA", "Lwl;");
		return mc.env->GetObjectField(getPlayer(), get_capabilities);
	}

	float getX() {
		jfieldID get_x = mc.env->GetFieldID(mc.env->GetObjectClass(CPlayer::getPlayer()), "s", "D");
		return mc.env->GetDoubleField(CPlayer::getPlayer(), get_x);
	}

	float getY() {
		jfieldID get_y = mc.env->GetFieldID(mc.env->GetObjectClass(CPlayer::getPlayer()), "t", "D");
		return mc.env->GetDoubleField(CPlayer::getPlayer(), get_y);
	}

	float getZ() {
		jfieldID get_z = mc.env->GetFieldID(mc.env->GetObjectClass(CPlayer::getPlayer()), "u", "D");
		return mc.env->GetDoubleField(CPlayer::getPlayer(), get_z);
	}

	static double getSpeed()
	{
		return std::sqrt(get_motion_x() * get_motion_x() + get_motion_z() * get_motion_z());
	}

	static bool isMoving() {
		if (getPlayerClass() == NULL) return NULL;
		return (getMoveForward() != 0) || (getMoveStrafing() != 0);
	}


	static bool getOnGround()
	{
		if (getPlayerClass() == NULL) return -1;
		if (ongroundfd == NULL)
			ongroundfd = mc.env->GetFieldID(getPlayerClass(), "C", "Z");
		mc.env->GetBooleanField(getPlayer(), ongroundfd);
	}

	static jobject raytrace(float dist)
	{
		jclass player_class = mc.env->GetObjectClass(getPlayer());
		jmethodID raytrace_mid = mc.env->GetMethodID(player_class, "a", "(DF)Lauh;");
		mc.env->DeleteLocalRef(player_class);
		return mc.env->CallObjectMethod(getPlayer(), raytrace_mid, 1.0, dist);
	}


	static double get_motion_z()
	{
		if (getPlayer() == NULL) return NULL;
		jclass playerclass = mc.env->GetObjectClass(getPlayer());
		jfieldID xfid = mc.env->GetFieldID(playerclass, "x", "D");
		double z = (double)mc.env->GetDoubleField(getPlayer(), xfid);
		mc.env->DeleteLocalRef(playerclass);
		return z;
	}


	static double get_motion_y()
	{
		if (getPlayerClass() == NULL) return NULL;
		jclass playerclass = mc.env->GetObjectClass(getPlayer());
		jfieldID yfid = mc.env->GetFieldID(playerclass,"w", "D");
		double y = (double)mc.env->GetDoubleField(getPlayer(), yfid);
		mc.env->DeleteLocalRef(playerclass);
		return y;
	}

	static double get_motion_x()
	{
		if (getPlayerClass() == NULL) return NULL;
		jclass playerclass = mc.env->GetObjectClass(getPlayer());
		jfieldID xfid = mc.env->GetFieldID(playerclass, "v", "D");
		double x = (double)mc.env->GetDoubleField(getPlayer(), xfid);
		mc.env->DeleteLocalRef(playerclass);
		return x;
	}




	static void jump() {
		set_motion_y(0.42);
	}





	static bool isOnGround() {

		jfieldID isOnGround1 = mc.env->GetFieldID(mc.env->GetObjectClass(CPlayer::getPlayer()), "C", "Z");
		return mc.env->GetBooleanField(getPlayer(), isOnGround1);
	}


	static void swingItem()
	{
		jmethodID swingItem = mc.env->GetMethodID(mc.env->GetObjectClass(CPlayer::getPlayer()), "bw", "()V");
		mc.env->CallVoidMethod(CPlayer::getPlayer(), swingItem);
	}

	static bool isBlocking()
	{
		jclass playerclass = mc.env->GetObjectClass(getPlayer());
		jmethodID blockmid = mc.env->GetMethodID(playerclass, "bW", "()Z");
		mc.env->DeleteLocalRef(playerclass);
		return (bool)mc.env->CallBooleanMethod(CPlayer::getPlayer(), blockmid);

	}


	static int gethurttime()
	{
		jfieldID hurttime_fid = mc.env->GetFieldID(mc.env->GetObjectClass(CPlayer::getPlayer()), "Z", "I");

		return mc.env->GetIntField(CPlayer::getPlayer(), hurttime_fid);
	}

	vec3 getLocation()
	{
		return vec3{
			this->getX(),
			this->getY(),
			this->getZ(),
		};
	}
	double getDistanceTo(const std::shared_ptr<CPlayer>& other)
	{
		return getLocation().distance(other->getLocation());
	}


	static void set_motion_y(double y)
	{
		if (CPlayer::getPlayer() == NULL) return;
		jfieldID yfid = mc.env->GetFieldID(CPlayer::getPlayerClass(), "w", "D");
		mc.env->SetDoubleField(CPlayer::getPlayer(), yfid, (jdouble)y);
		mc.env->DeleteLocalRef(CPlayer::getPlayerClass());
	}	static void set_motion_x(double x)
	{
		if (CPlayer::getPlayer() == NULL) return;
		jfieldID xfid = mc.env->GetFieldID(CPlayer::getPlayerClass(), "v", "D");
		mc.env->SetDoubleField(CPlayer::getPlayer(), xfid, (jdouble)x);
		mc.env->DeleteLocalRef(CPlayer::getPlayerClass());
	}

	static float get_fall_distance() {
		jclass playerclass = mc.env->GetObjectClass(getPlayer());
		jfieldID falldfid = mc.env->GetFieldID(playerclass, "O", "F");
		mc.env->DeleteLocalRef(playerclass);
		return mc.env->GetFloatField(CPlayer::getPlayer(), falldfid);
	}

	static void setFallDist(float dist)
	{
		jclass playerclass = mc.env->GetObjectClass(CPlayer::getPlayer());
		jfieldID falldfid = mc.env->GetFieldID(playerclass, "O", "F");
		mc.env->DeleteLocalRef(playerclass);
		return mc.env->SetFloatField(getPlayer(), falldfid, dist);
	}

	static float getMoveStrafing()
	{
		if (CPlayer::getPlayer() == NULL) return NULL;
		jfieldID moveStrafe = mc.env->GetFieldID(CPlayer::getPlayerClass(), "aZ", "F");
		return mc.env->GetFloatField(getPlayer(), moveStrafe);
	}

	static double toRadians(float degrees) {
		return degrees * (M_PI / 180);
	}
	static float getRotationYaw()
	{
		jfieldID yaw = mc.env->GetFieldID(getPlayerClass(), "y", "F");
		return mc.env->GetFloatField(getPlayer(), yaw);
	}

	static double getDirection() {
		if (getPlayer() == NULL) return NULL;
		float rotationYaw = getRotationYaw();
		if (CPlayer::getMoveForward() < 0.0f) {
			rotationYaw += 180.0f;
		}
		float forward = 1.0f;
		if (CPlayer::getMoveForward() < 0.0f) {
			forward = -0.5f;
		}
		else if (CPlayer::getMoveForward() > 0.0f) {
			forward = 0.5f;
		}
		if (CPlayer::getMoveStrafing() > 0.0f) {
			rotationYaw -= 90.0f * forward;
		}
		if (CPlayer::getMoveStrafing() < 0.0f) {
			rotationYaw += 90.0f * forward;
		}
		return toRadians(rotationYaw);
	}



	static float getMoveForward()
	{
		if (getPlayerClass() == NULL) return NULL;
		jfieldID moveForward = mc.env->GetFieldID(getPlayerClass(), "ba", "F");
		return mc.env->GetFloatField(getPlayer(), moveForward);
	}
	static bool isStrafing() {
		if (getPlayer() == NULL) return NULL;
		return CPlayer::getMoveStrafing() != 0.0;
	}

	static bool isMovingForwardOrBackwards() {
		if (getPlayerClass() == NULL) return NULL;
		return CPlayer::getMoveForward() != 0.0;
	}

	static void set_motion_z(double z)
	{
		if (getPlayerClass() == NULL) return;
		jclass playerclass = mc.env->GetObjectClass(getPlayer());
		jfieldID xfid = mc.env->GetFieldID(playerclass, "x", "D");
		mc.env->SetDoubleField(getPlayer(), xfid, (jdouble)z);
		mc.env->DeleteLocalRef(playerclass);
	}


	static void strafe(float speed) {
		if (getPlayerClass() == NULL) return;
		if (!CPlayer::isStrafing() && !CPlayer::isMovingForwardOrBackwards()) {
			return;
		}
		if (CPlayer::isStrafing() || CPlayer::isMovingForwardOrBackwards()) {
			double yaw = getDirection();

			CPlayer::set_motion_x(-sin(yaw) * speed);
			CPlayer::set_motion_z(cos(yaw) * speed);
		}
	}
};
