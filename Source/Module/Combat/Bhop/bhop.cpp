#include "../../JNI/Helper/Java.h"
#include "../SDK.h"
#include "../../SDK/Entity/Player/Player.h"
#include "../../SDK/Client/Minecraft.h"
#include "bhop.h"
#include "../settings/settings.h"


/* SKIDDED FROM SKIDWARE*/


void Bhop::runModule()
{
	if (settings::NCPBHop) {
		int jumps = 0;

		jfieldID speedairfid = mc.env->GetFieldID(CPlayer::getPlayerClass(), "bF", "F");


		if (CPlayer::isMoving()) {

			double x = CPlayer::get_motion_x();
			double z = CPlayer::get_motion_z();
			double y = CPlayer::get_motion_y();

			if (jumps == 7) {
				CPlayer::strafe(CPlayer::getSpeed() * 1.0);
				jumps = 0;
			}
			else {
				CPlayer::strafe(CPlayer::getSpeed() * 1.01);
				CPlayer::set_motion_x(x * 1.01);
				CPlayer::set_motion_z(z * 1.01);
				jumps++;
			}
			Minecraft::setTimer(1.0005);
			mc.env->SetFloatField(CPlayer::getPlayer(), speedairfid, 0.0201f);
			if (CPlayer::getOnGround() == false) {
				CPlayer::strafe(CPlayer::getSpeed());
			}




		}
		else {
			mc.env->SetFloatField(CPlayer::getPlayer(), speedairfid, 0.02f);
			Minecraft::setTimer(1);
		}
	}
	else if (!settings::NCPBHop && settings::NCPYPort) {
		float speed = Bhop::speed;
		/*
		if (!(GetAsyncKeyState('W') & 0x8000)) return;
		if (LaunchWrapper::getMinecraft().getLocalPlayer().getOnGround()) {
			LaunchWrapper::getMinecraft().getLocalPlayer().set_motion_y(0.42);
			LaunchWrapper::getMinecraft().getLocalPlayer().set_motion_x(LaunchWrapper::getMinecraft().getLocalPlayer().get_motion_x() * 1.12);
			LaunchWrapper::getMinecraft().getLocalPlayer().set_motion_z(LaunchWrapper::getMinecraft().getLocalPlayer().get_motion_z() * 1.12);
		}
		else if (LaunchWrapper::getMinecraft().getLocalPlayer().get_fall_distance() < 0.25) {
			LaunchWrapper::getMinecraft().getLocalPlayer().set_motion_y(-63);
			Logger::Log("StrafeUpdate");
			LaunchWrapper::getMinecraft().getLocalPlayer().setMoveStrafing(LaunchWrapper::getMinecraft().getLocalPlayer().getMoveStrafing() * 2);
			LaunchWrapper::getMinecraft().getLocalPlayer().strafe(speed);
		}
		*/
		if (CPlayer::getOnGround())
			//LaunchWrapper::getMinecraft().getLocalPlayer().strafe(LaunchWrapper::getMinecraft().getLocalPlayer().getSpeed() * speed);
			CPlayer::strafe(CPlayer::getSpeed() * speed);


	}


}

void Bhop::onDisable()
{
	Bhop::speed = 1.01;
}
/* SKIDDED FROM SKIDWARE*/
