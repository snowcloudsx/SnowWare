#include "sprint.h"
#include "../../SDK/Entity/Player/Player.h"
#include <Windows.h>
#include "../../Mapper/Mapper.h"


void Sprint::runModule(jboolean sprinting)
{
	if(!blatent)
	{
		if (!GetAsyncKeyState('W') || GetAsyncKeyState('S') || GetAsyncKeyState(VK_LCONTROL)) return;
		jmethodID set_sprint = mc.env->GetMethodID(mc.env->GetObjectClass(CPlayer::getPlayer()), "d", "(Z)V");
		mc.env->CallBooleanMethod(CPlayer::getPlayer(), set_sprint, sprinting);
	}
	else if (blatent) {
		jmethodID set_sprint = mc.env->GetMethodID(mc.env->GetObjectClass(CPlayer::getPlayer()), "d", "(Z)V");
		mc.env->CallBooleanMethod(CPlayer::getPlayer(), set_sprint, true);
	}
}


