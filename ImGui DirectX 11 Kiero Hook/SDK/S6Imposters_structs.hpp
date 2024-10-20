#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: S6Imposters

#include "Basic.hpp"


namespace SDK
{

// Enum S6Imposters.ES6_ImposterLayoutType
// NumValues: 0x0004
enum class ES6_ImposterLayoutType : uint8
{
	FullSphere                               = 0,
	UpperHemisphere                          = 1,
	Billboards                               = 2,
	ES6_ImposterLayoutType_MAX               = 3,
};

// Enum S6Imposters.ES6_ImposterBakeType
// NumValues: 0x0005
enum class ES6_ImposterBakeType : uint8
{
	BaseColor                                = 0,
	Opacity                                  = 1,
	Normal                                   = 2,
	Depth                                    = 3,
	ES6_ImposterBakeType_MAX                 = 4,
};

}

