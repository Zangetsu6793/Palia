#pragma once
#ifndef TELEPORT_H
#define TELEPORT_H
#include <tuple> // Include for std::tuple
#include "Memory.h"
#include "Offsets.h"
#include "sdk.h"
#include <thread>
#include <future>
#include <functional>
#include <windows.h>
#include <future>
#include <iostream>


namespace Teleport
{
	std::tuple<float, float, float> GetPositionManual();
	void TpPositionManual(float x, float y, float z, int sleeptime);
	 void startTpAsync();
	 void PressAndReleaseKey(BYTE vkCode = 0x57, int sleepDuration = 100);
	 SDK::FVector GetPlayerPosition();
	 void TpPlayerPos(SDK::FVector Destination, float sleeptime = 0);
	 void TpPlayerPosSequance();

	 
}
#endif