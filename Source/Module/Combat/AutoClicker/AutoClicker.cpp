#include "AutoClicker.h"
#include <Windows.h>
#include <WinUser.h>
#include <sysinfoapi.h>
#include <stdio.h>




void AutoClicker::runModule()
{
	auto click_left = []() {
		INPUT Input = { 0 };

		// left down
		Input.type = INPUT_MOUSE;
		Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
		SendInput(1, &Input, sizeof(INPUT));

		// left up
		RtlSecureZeroMemory(&Input, sizeof(INPUT));
		Input.type = INPUT_MOUSE;
		Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
		SendInput(1, &Input, sizeof(INPUT));
		};

	auto timer = []() {
		static double start_time = GetTickCount();
		double current_time = GetTickCount() - start_time;

		int cps = 10;

		if (current_time >= (1000 / cps)) {
			start_time = GetTickCount();
			return true;
		}
		return false;
		};
	if (timer() && enabled) {
		click_left();
		//printf("Held down");
	}
}

	

	

	

