#include "Flight.h"
#include "../../JNI/Helper/Java.h"
#include "../../SDK/Entity/Player/Player.h"


inline bool reset = false;


void Flight::runModule(bool state)
{
	if(!Flight::blatent)
	{
		jfieldID set_flight = mc.env->GetFieldID(mc.env->GetObjectClass(CPlayer::get_capabilities()), "b", "Z");
		mc.env->SetBooleanField(CPlayer::get_capabilities(), set_flight, state);
	}
	else if (Flight::blatent) {
		Flight::runModuleV2();
	}
	
}

void Flight::onDisable(){
	jfieldID set_flight = mc.env->GetFieldID(mc.env->GetObjectClass(CPlayer::get_capabilities()), "b", "Z");

	if(reset = false)
		mc.env->SetBooleanField(CPlayer::get_capabilities(), set_flight, false);
		reset = true;

}

void Flight::runModuleV2()
{
	//spartan fly

	
	CPlayer::set_motion_y(0);
	if (CPlayer::get_fall_distance() > 0) {
		CPlayer::set_motion_y(0.2);
		CPlayer::setFallDist(0);
	}
	CPlayer::strafe(Flight::speed);
	if (CPlayer::getMoveForward() == 0) {
		//pasted cause lazy lol
		CPlayer::set_motion_x(0);
		CPlayer::set_motion_z(0);
	}
	
}