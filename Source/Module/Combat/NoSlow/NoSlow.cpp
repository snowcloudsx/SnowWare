#include "NoSlow.h"
#include "../../settings/settings.h"
#include "../../../SDK/Entity/Player/Player.h"

void NoSlow::OnTick()
{
	if (settings::NoSlow != true) return;
	if (CPlayer::isBlocking())
	{
		if ((GetAsyncKeyState(VK_RBUTTON) & 0x8000)) {
			if (!CPlayer::isMoving()) return;
			double x = CPlayer::get_motion_x();
			double z = CPlayer::get_motion_z();
			if (CPlayer::getOnGround())
				CPlayer::strafe(0.2);
		}
	}
}
