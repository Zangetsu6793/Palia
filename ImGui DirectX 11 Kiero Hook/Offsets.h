#pragma once

#include <cstdint>
#include <thread>
#include "sdk.h"

namespace Offsets {

    // client
    constexpr std::ptrdiff_t dwLocalPlayerPawn = 0x173B568;
    constexpr std::ptrdiff_t m_iHealth = 0x334;

    constexpr std::ptrdiff_t PlayerXPosOffsets[] = { 0x07F1E6A0, 0x0, 0x28, 0x40, 0x8, 0x90, 0x1F0 };
    // std::ptrdiff_t PlayerVisualPosOffsets[] = { 0x07F42B28, 0x48, 0x128, 0xA0, 0x2A0, 0x60, 0xD0, 0x1F0 };

}
