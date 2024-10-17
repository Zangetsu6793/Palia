#include "Teleport.h"

namespace Teleport
{
	std::future<void> result;
	std::future<void> KeyPressresult;
	std::tuple<float, float, float> GetPositionManual()
	{
		uintptr_t xPlayerPosBase = sdk::ClientBase + Offsets::PlayerXPosOffsets[0];
		uintptr_t finalAddress = Memory::FollowPointerChain(xPlayerPosBase, Offsets::PlayerXPosOffsets + 1, sizeof(Offsets::PlayerXPosOffsets) / sizeof(Offsets::PlayerXPosOffsets[0]) - 1);
		float xFloat = Memory::ReadFloat(finalAddress);
		float zFloat = Memory::ReadFloat(finalAddress + sizeof(float));
		float yFloat = Memory::ReadFloat(finalAddress + 2 * sizeof(float));

		float x = xFloat;
		float y = yFloat;
		float z = zFloat;

		return std::make_tuple(x, y, z);
	}

	void TpPositionManual(float x, float y, float z, int sleeptime)
	{
		uintptr_t xPlayerPosBase = sdk::ClientBase + Offsets::PlayerXPosOffsets[0];
		uintptr_t finalAddress = Memory::FollowPointerChain(xPlayerPosBase, Offsets::PlayerXPosOffsets + 1, sizeof(Offsets::PlayerXPosOffsets) / sizeof(Offsets::PlayerXPosOffsets[0]) - 1);
		Memory::WriteFloat(finalAddress, x);
	    Memory::WriteFloat(finalAddress + sizeof(float), z);
		Memory::WriteFloat(finalAddress + 2 * sizeof(float), y);
		
		PressAndReleaseKey(0x57, 100);

		Sleep(sleeptime);
		
	}
	
	

	void startTpAsync() {
		result = std::async(std::launch::async, TpPlayerPosSequance);
	}
	void PressAndReleaseKey(BYTE vkCode , int sleepDuration) // Default key 'W' and sleep duration 100ms
	{
		bool temp = show_menu;
		show_menu = false;
		INPUT input = { 0 };

		// Press the key
		input.type = INPUT_KEYBOARD;
		input.ki.wVk = vkCode;
		SendInput(1, &input, sizeof(INPUT));

		// Sleep for the specified duration
		Sleep(sleepDuration);

		// Release the key
		input.ki.dwFlags = KEYEVENTF_KEYUP;
		SendInput(1, &input, sizeof(INPUT));

		Sleep(100);
		show_menu = temp;
	}


	


	SDK::FVector GetPlayerPosition()
	{
		if (!sdk::World)
			return SDK::FVector(0,0,0);

		if (!sdk::World->OwningGameInstance)
			return SDK::FVector(0, 0, 0);

		if (!sdk::World->OwningGameInstance->LocalPlayers[0])
			return SDK::FVector(0, 0, 0);

		if (!sdk::World->OwningGameInstance->LocalPlayers[0]->PlayerController)
			return SDK::FVector(0, 0, 0);

		return sdk::World->OwningGameInstance->LocalPlayers[0]->PlayerController->AcknowledgedPawn->K2_GetActorLocation();

	}

	void TpPlayerPos(SDK::FVector Destination, float sleeptime)
	{
		if (!sdk::World)
			return;

		if (!sdk::World->OwningGameInstance)
			return;

		if (!sdk::World->OwningGameInstance->LocalPlayers[0])
			return;

		if (!sdk::World->OwningGameInstance->LocalPlayers[0]->PlayerController)
			return;

		sdk::World->OwningGameInstance->LocalPlayers[0]->PlayerController->AcknowledgedPawn->K2_SetActorLocation(Destination, false, nullptr, true);
		Sleep(sleeptime);
	}

	void TpPlayerPosSequance()
	{

		float waitTime = 2.0f; // Wait for 0.1 seconds between iterations
		float accumulator = 0.0f;
		for (const auto& location : vars::teleportLocations)
		{
			if (location.selected) {

				fprintf(stderr, "Teleporting to: x=%.2f, y=%.2f, z=%.2f\n", location.x, location.y, location.z);
				SDK::FVector pos = SDK::FVector(location.x, location.y, location.z);
				Teleport::TpPlayerPos(pos, 3000);

			}

			float deltaTime = ImGui::GetIO().DeltaTime;
			accumulator += deltaTime;

			while (accumulator > waitTime)
			{
				// Do nothing, just wait
				accumulator -= waitTime;

			}

		}
	}
}
