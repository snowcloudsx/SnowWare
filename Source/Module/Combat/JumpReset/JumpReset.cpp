#include "JumpReset.h"
#include "../../../SDK/Entity/Player/Player.h"
#include "../../Cheat.h"

void JumpReset::runModule()
{
	if (CPlayer::gethurttime() > 0 && !CPlayer::isOnGround()) {

		CPlayer::set_motion_x(0);
		CPlayer::set_motion_z(0);
		

	}
}
