#pragma once

#include <Windows.h>
#include <string>
#include "sdk.h"
#include "./SDK/Engine_classes.hpp"

namespace Scripts
{
	
}
namespace Util
{
	SDK::FString FString(std::string str);
	ImVec2 WorldToScreen(SDK::FVector world);
}