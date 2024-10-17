#pragma once

#include <Windows.h>
#include <string>
#include "sdk.h"
#include "./CppSDK/SDK/WorldFunctionLibrary_classes.hpp"
#include "./CppSDK/SDK/Engine_classes.hpp"

namespace Scripts
{
	std::string eval(std::string script);
	bool isMapOpen();
}
namespace Util
{
	SDK::FString FString(std::string str);
	ImVec2 WorldToScreen(SDK::FVector world);
}